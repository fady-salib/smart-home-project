# Source audit — 2026-10-29

Baseline `5305fb6`, branch `main`; 171 tracked paths. All C/header implementations
were inspected using content-hash deduplication and application-specific copies
were reviewed separately. Eclipse settings, Makefile, ignore/attributes and
Proteus archive members were inventoried. Historical ELF binaries were retained
as artifacts; they are not source or current validation. See
[the per-file inventory](file-inventory.md).

## Actual scope and ownership

Three direct-register ATmega32 projects, not an IoT/server platform. Active code
uses keypad/LCD, EEPROM/TWI, UART activation, LM35, LDR, discrete device outputs,
stepper sequencing and timer scheduling. No MQTT, HTTP, REST, Docker, Python,
machine-learning model, humidity/PIR integration or account-role system exists.
The root README was truncated and had unsupported build/MIT badges.

Eclipse targets and Makefile agree on ATmega32 / 8 MHz. Proteus ZIP contents
include ROOT.DSN, ROOT.CDB, PROJECT.XML and power-rail data; binary model strings
include ATMEGA32, LM35, 24C04F/24C08, LM016L and LM044L. This is not confirmation
of a physical BOM or an executed simulation. Headers retain author identifiers
`M.H` and `Hanos_000`. Owner-provided dates are Aug–Sep 2023; personal/team and
ITI-source contributions require clarification before sole-authorship claims.

## Prioritized findings and disposition

| Priority | Source finding | Treatment |
|---|---|---|
| P1 | LM35 passes `u8*` to ADC's `u16*`, overwriting adjacent RAM; divide-by-two also truncates before scaling | Read into a real 16-bit local; explicit 5 V/10-bit conversion and 8-bit saturation; guard-byte regression |
| P1 | Phone entry writes 11 digits to 10-element array; attempts to convert that number into 16 bits | Refactor display-only entry to bounded digit count without unused buffer/integer conversion; no dialing/storage feature fabricated |
| P1 | Change-password uses wrong digit pointer type, 8-bit accumulator and integer as EEPROM output pointer | Shared decimal validation, 16-bit result, valid pointers, consistent addresses and readback verification |
| P1 | Out-of-range EEPROM application addresses `0x1234/0x1245` exceed supported banked parts | Use first-bank `0x0034/0x0045` in common definitions; re-provisioning required; HAL rejects >0x07FF |
| P1 | Password provisioning readback failures could proceed to later actions | Explicit mismatch/range failure returns before door/UART activation; failure test |
| P1 | Timer ISR runs LCD/ADC and blocking keypad clock-entry tasks | ISR marks pending work; atomic foreground dispatch; split bounded clock input task, validated HHMMSS |
| P1 | Default setpoint zero can activate cooling immediately | Keep thermal outputs off until valid setpoint; manual heat/cool requests deactivate opposite output |
| P2 | ADC channel selection ORs new channel into old mux bits | Mask/replace channel; regression switches 7 → 0 |
| P2 | TWI read/modify/write retains START/ACK control across transactions; no status checks or bounded waits | Explicit W1C commands, expected statuses, bounded polls, final-byte NACK and EEPROM repeated START/error sentinel; register-model checks, electrical timing unverified |
| P2 | DIO port-value function writes DDR rather than PORT | Correct register; fake-register test protects DDR |
| P2 | Three-column keypad initializes a phantom fourth column and blocks until release | Exactly three output columns, input pull-ups, bounded edge-event scan; no debounce accuracy claim |
| P2 | Stepper sets whole port to outputs and uses 8-bit loop counter for 32-bit count | Configure only coils, widen counter; test >255 cycles and UART pin preservation |
| P2 | Scheduler indexes unchecked tasks, allows zero period, global modulo counter wraps | Validate inputs; per-task countdowns, atomic state and pending coalescing; 70,000-tick regression |
| P2 | 1 ms timer uses OCR=125 instead of 124 at 8 MHz/64 | Correct compare value; tested configuration and documented clock assumption |
| P2 | UART string index uninitialized, receive declaration disagrees with implementation; RX direction wrong in master | Initialize index, guard null string, correct declaration/directions |
| P2 | Temperature exactly 45°C takes no branch | Complete <45 / 45–69 / ≥70 partition and actual service regression |
| P2 | LCD integer formatter overflows at INT32_MIN and reserves 100 stack bytes | Shared bounded int32 formatting; min/max/zero tests |
| P3 | Duplicate globals rely on common-symbol merging; string qualifiers/implicit declarations generate warnings | Explicit ownership/externs, fixed-width types, const-correct strings and headers; `-fno-common`, warnings as errors |
| P3 | LDR repeatedly initializes LCD and leaves zero ADC input with stale output | Remove unrelated LCD init; complete original >3 V decision using integer threshold; actual light polarity still unverified |
| P3 | Unused LCD custom-character stub returns success without uploading data | Return failure explicitly; no invented implementation |

## File organization and preserved code

The three original Eclipse directory trees are retained. Equivalent fixes were
applied across matching driver copies rather than redirecting their include paths
or moving all drivers. `common/HomeLogic.*` extracts only hardware-independent
logic used by the applications and tests. Author headers are retained. Commented
legacy experiments and historical binaries remain; no useful original artifact
was silently deleted. Repeated unused phone-buffer/conversion code was replaced
because it contributed the verified overflow and never stored/sent a number.

`master/APP.c` calls access setup, whose successful path performs door sequencing,
sends a byte and enters LDR polling. `slave1/APP.c` waits for that byte, then runs
blocking menu/temperature operations. `slave2/APP.c` configures three cooperative
tasks: temperature warning (50 ms), clock input (20 ms), clock tick/display
(1,000 ms). This is not a preemptive RTOS or a real-time timing guarantee.

## Important residual issues

Boot-time PIN replacement is still a security bypass by design; plaintext EEPROM,
unauthenticated single-byte UART and nontransactional PIN changes are unsuitable
for real access control. EEPROM topology, pull-ups, write-cycle timing and
multi-master arbitration require physical/Proteus verification. The default driver
uses banked one-byte word addressing, not a generic 16-bit-address EEPROM protocol.

ADC/UART waits remain blocking. Sensor disconnection is not reliably identified;
5 V scaling/polarity is assumed. Cooperative work can run late and coalesces missed
periods; slave1 menus can defer thermostat updates. No hysteresis, actuator-feedback
or physical interlock validation exists. There is no smoke-sensor acquisition.

The unused half-step sequence is not a validated half-step driver, and unused
SPI/external-interrupt paths have remaining concerns (SS configuration, global
interrupt side effects/callback ordering). They are not claimed as integrated
features. Door forward/reverse counts differ and can drift; changing those counts
requires measured mechanics, not a guessed rewrite. ATmega32 JTAG/fuse settings
and LCD dimensions need confirmation against the actual circuit.

No secrets were added. Tests use non-sensitive dummy digit sequences. No project
LICENSE file exists; original teaching/team-source ownership must be resolved
before selecting a license. See [verification](verification.md) for exact build,
resource and host-test evidence.
