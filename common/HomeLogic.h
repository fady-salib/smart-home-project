#ifndef HOME_LOGIC_H
#define HOME_LOGIC_H
#include <stdint.h>
/* Returns 1 only for 1..4 decimal digits; preserves numeric 0000 as valid. */
uint8_t home_digits_to_u16(const uint8_t *digits, uint8_t count, uint16_t *number);
/* LM35 10 mV/degree, 10-bit ADC, assumed 5 V reference; saturated to uint8. */
uint8_t home_lm35_celsius(uint16_t raw);
/* Complete threshold partition: <45 normal, 45..69 warm, >=70 alarm. */
uint8_t home_temperature_zone(uint8_t celsius);
uint8_t home_format_i32(int32_t value, char output[12]);
#define HOME_PIN_HIGH_ADDRESS 0x0034u
#define HOME_PIN_LOW_ADDRESS  0x0045u
#endif
