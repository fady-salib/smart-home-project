#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../common/HomeLogic.h"
#include "../master/LIB/STD_TYPES.h"
#include "../master/MCAL/DIO/DIO_Interface.h"

static u16 adc_sample;
void ADC_voidInit(void) { }
void ADC_StartConv(u8 channel, u16 *value) { (void)channel; *value = adc_sample; }
void DIO_VoidSetPinDirection(u8 port, u8 pin, u8 mode) { (void)port; (void)pin; (void)mode; }
#include "../master/HAL/LM35/LM35_Prog.c"

int main(void)
{
    uint8_t digits[4] = {1, 2, 3, 4};
    uint16_t result = 999;
    assert(home_digits_to_u16(digits, 4, &result) && result == 1234);
    digits[0] = '#'; assert(!home_digits_to_u16(digits, 4, &result));
    assert(result == 1234);
    assert(!home_digits_to_u16(NULL, 4, &result));
    assert(!home_digits_to_u16(digits, 0, &result));
    assert(!home_digits_to_u16(digits, 5, &result));
    memset(digits, 0, sizeof(digits));
    assert(home_digits_to_u16(digits, 4, &result) && result == 0);
    assert(home_temperature_zone(44) == 0 && home_temperature_zone(45) == 1);
    assert(home_temperature_zone(69) == 1 && home_temperature_zone(70) == 2);
    struct { u8 before, temperature, after; } guarded = {0xA5, 0, 0x5A};
    adc_sample = 512;
    LM35_voidReadValue(0, &guarded.temperature);
    assert(guarded.before == 0xA5 && guarded.after == 0x5A);
    assert(guarded.temperature == 250);
    adc_sample = 1023; LM35_voidReadValue(0, &guarded.temperature);
    assert(guarded.temperature == 255); /* must saturate instead of wrapping */
    assert(home_lm35_celsius(0) == 0 && home_lm35_celsius(102) == 49);
    char text[12];
    home_format_i32(INT32_MIN, text); assert(strcmp(text, "-2147483648") == 0);
    home_format_i32(INT32_MAX, text); assert(strcmp(text, "2147483647") == 0);
    home_format_i32(0, text); assert(strcmp(text, "0") == 0);
    puts("PASS logic and real LM35 driver: decimal bounds, 45C boundary, guard bytes, saturation, int32 formatting");
}
