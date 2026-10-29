# Verification — 2026-10-29

Baseline `5305fb6`; no existing test suite. A bare `make` initially could not find
avr-gcc. After selecting GNU AVR 7.3.0-atmel3.6.1-arduino7, the unmodified source
built all three images and emitted **132 warnings**. These included incompatible
ADC/password pointers, uninitialized UART index, implicit declarations, array
initializer overflow and incorrect main signatures.

| Image | Baseline program / SRAM | Reviewed program / SRAM |
|---|---:|---:|
| master | 5,302 / 186 bytes | 4,976 / 193 bytes |
| slave1 | 7,516 / 700 bytes | 6,856 / 720 bytes |
| slave2 | 4,166 / 87 bytes | 3,818 / 131 bytes |

Reviewed **clean** build passed with `-Wall -Wextra -Werror -fno-common`, gnu99,
`-Os`, ATmega32 and `F_CPU=8000000UL`; no warnings. These are linker static figures,
not stack high-water or physical timing measurements. AVR's 32 KiB flash/2 KiB
SRAM limits were not exceeded. Images were not flashed.

Eight host executables passed using GCC 14.2.0 with AddressSanitizer/UBSan and
warnings as errors. Leak detection was disabled explicitly (`detect_leaks=0`)
because of the review runner's ptrace restriction. Each executable has a 30-second
timeout so an accidental reintroduction of a blocking loop fails CI.

| Executable | Verified scenarios |
|---|---|
| `test_logic` | Numeric bounds/0000, invalid symbols, actual LM35 driver guard bytes, 16-bit acquisition, saturation, 45°C threshold and INT32_MIN/MAX formatting |
| `test_scheduler` | Bad priority/null callback/zero period, no callbacks in ISR, foreground dispatch, coalescing, suspend/resume/delete, 70,000-tick rollover and compare=124 |
| `test_register_drivers` | Actual DIO/stepper/ADC/TWI source against substituted registers: PORT versus DDR, preserve UART pins, >255 phase cycles terminate, ADC channel 7→0, explicit TWI control/status/error sentinels and >255-byte UART strings |
| `test_keypad` | Three-column configuration, no phantom PA0 output, one event per held key, release/re-press |
| `test_slave_services` | Real temperature service at 44/45/70°C, midnight rollover, bounded clock input, invalid time rejection and valid update |
| `test_password_change` | Real change-password code, symbol rejection, full four-digit width, valid EEPROM pointers, eleven phone digits without undersized array/integer conversion |
| `test_access` | Real provisioning/comparison flow, success sequence, EEPROM readback failure blocks door/UART, three failed attempts lock out |
| `test_thermostat` | Real room-control source: outputs off before setpoint, numeric setpoint, exclusive heat/cool and equal-temperature off |

Register tests substitute memory and completion/status behavior; they do not
simulate all ATmega32 electrical/W1C/timing behavior or prove I²C bus compatibility.
The atomic-block host shim checks task logic, not actual interrupt preemption.
No Proteus, physical board, ADC reference, EEPROM, relay, stepper, human interface
or real fire/HVAC/security validation was available. Unsafe scenarios must remain
on isolated low-voltage models. The root historical ELF files are unchanged and
must not be mistaken for the newly built review images.

Reproduce with `make` and `ASAN_OPTIONS=detect_leaks=0 make test` (or ordinary
`make test` outside restricted runners). Tool-path overrides are documented in
the README. Remote CI and a published PR are not claimed; current GitHub writes
are blocked. Exact local build/test logs accompany the delivery artifacts.
