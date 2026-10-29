#include "HomeLogic.h"

uint8_t home_digits_to_u16(const uint8_t *digits, uint8_t count, uint16_t *number)
{
    uint16_t result = 0;
    if (!digits || !number || count == 0 || count > 4) return 0;
    for (uint8_t i = 0; i < count; ++i) {
        if (digits[i] > 9) return 0;
        result = (uint16_t)(result * 10u + digits[i]);
    }
    *number = result;
    return 1;
}

uint8_t home_lm35_celsius(uint16_t raw)
{
    if (raw > 1023) raw = 1023;
    uint16_t degrees = (uint16_t)(((uint32_t)raw * 500u) / 1024u);
    return degrees > 255 ? 255 : (uint8_t)degrees;
}

uint8_t home_temperature_zone(uint8_t celsius)
{
    return celsius < 45 ? 0 : (celsius < 70 ? 1 : 2);
}

uint8_t home_format_i32(int32_t value, char output[12])
{
    char reversed[10];
    uint8_t count = 0, length = 0;
    if (!output) return 0;
    uint32_t magnitude = value < 0 ? (uint32_t)(-(value + 1)) + 1u : (uint32_t)value;
    if (value < 0) output[length++] = '-';
    do {
        reversed[count++] = (char)('0' + magnitude % 10u);
        magnitude /= 10u;
    } while (magnitude);
    while (count) output[length++] = reversed[--count];
    output[length] = '\0';
    return length;
}
