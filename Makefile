# Command-line build for the three ATmega32 firmware images (alternative to the Eclipse AVR plugin).
#
#   make              build master, slave1 and slave2  ->  build/<name>.hex
#   make master       build one image
#   make OPT=-O0      match the Eclipse "Debug" configuration (avoid: _delay_ms() needs optimisation)
#   make clean
#
# Flags mirror the Eclipse project settings (ATmega32 @ 8 MHz, gnu99, packed structs, short enums).

MCU    ?= atmega32
F_CPU  ?= 8000000UL
OPT    ?= -Os
BUILD  ?= build

CC      = avr-gcc
OBJCOPY = avr-objcopy
SIZE    = avr-size

CFLAGS  = -Wall -Wextra -Werror $(OPT) -std=gnu99 -mmcu=$(MCU) -DF_CPU=$(F_CPU) \
          -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
          -fno-common -ffunction-sections -fdata-sections -MMD -MP
LDFLAGS = -mmcu=$(MCU) -Wl,--gc-sections

PROJECTS = master slave1 slave2

.PHONY: all clean $(PROJECTS)
all: $(PROJECTS)

define project_rule
SRC_$(1) := $$(sort $$(shell find $(1) -name '*.c')) common/HomeLogic.c
OBJ_$(1) := $$(SRC_$(1):%.c=$$(BUILD)/%.o)
$(1): $$(BUILD)/$(1).hex
$$(BUILD)/$(1).elf: $$(OBJ_$(1))
	$$(CC) $$(LDFLAGS) -Wl,-Map,$$(BUILD)/$(1).map -o $$@ $$^
	$$(SIZE) --format=avr --mcu=$$(MCU) $$@
endef
$(foreach p,$(PROJECTS),$(eval $(call project_rule,$(p))))

$(BUILD)/%.hex: $(BUILD)/%.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(firstword $(subst /, ,$*)) -c -o $@ $<

clean:
	rm -rf $(BUILD)

-include $(shell find $(BUILD) -name '*.d' 2>/dev/null)

HOST_CC ?= gcc
HOST_SANITIZERS ?= -fsanitize=address,undefined -fno-omit-frame-pointer -fno-pie -no-pie
HOST_TESTS = logic scheduler register_drivers keypad slave_services password_change access thermostat
HOST_BINS = $(addprefix $(BUILD)/host/test_,$(HOST_TESTS))
.PHONY: test
test: $(HOST_BINS)
	@set -e; for executable in $(HOST_BINS); do timeout 30s ./$$executable; done

$(BUILD)/host/test_%: tests/test_%.c common/HomeLogic.c $(shell find master slave1 slave2 common tests/mocks -name '*.h' -o -name '*.c')
	@mkdir -p $(dir $@)
	$(HOST_CC) -std=c11 -Wall -Wextra -Werror -g -Itests/mocks $(HOST_SANITIZERS) $< common/HomeLogic.c -o $@
