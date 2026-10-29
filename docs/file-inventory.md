# Original tracked-file inventory

Base `5305fb6`: 171 original paths. Identical C/header copies were compared by SHA-256 and inspected by representative content; application-specific differences were inspected separately. Proteus was inventoried, not executed.

| Original path | Role / review finding |
|---|---|
| `.gitattributes` | Repository presentation/build/configuration inspected; unsupported README claims replaced |
| `.gitignore` | Repository presentation/build/configuration inspected; unsupported README claims replaced |
| `ITI_MASTER_1.elf` | Historical binary: retained unchanged, not source/review build or validation |
| `ITI_MC1.elf` | Historical binary: retained unchanged, not source/review build or validation |
| `ITI_MC2.elf` | Historical binary: retained unchanged, not source/review build or validation |
| `ITI_MC3.elf` | Historical binary: retained unchanged, not source/review build or validation |
| `ITI_SLAVE_1.elf` | Historical binary: retained unchanged, not source/review build or validation |
| `ITI_SLAVE_2.elf` | Historical binary: retained unchanged, not source/review build or validation |
| `ITI_SmartHome_Simulation.pdsprj` | Proteus ZIP project: members/models inventoried; not executed or fully decoded as wiring |
| `Makefile` | Repository presentation/build/configuration inspected; unsupported README claims replaced |
| `README.md` | Repository presentation/build/configuration inspected; unsupported README claims replaced |
| `master/.cproject` | Repository presentation/build/configuration inspected; unsupported README claims replaced |
| `master/.project` | Eclipse metadata/configuration inspected; target/clock checked where recorded |
| `master/.settings/de.innot.avreclipse.core.prefs` | Eclipse metadata/configuration inspected; target/clock checked where recorded |
| `master/APP.c` | Application entry point; board-specific flow and source pin map |
| `master/HAL/EEPROM/EEPROM_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/EEPROM/EEPROM_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/EEPROM/EEPROM_Prog.c` | Banked-address interface; repeated START and error defaults |
| `master/HAL/Key_Pad/KP_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/Key_Pad/KP_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/Key_Pad/KP_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/Key_Pad/KP_Prog.c` | 3-column config and blocking held-key scan; fixed |
| `master/HAL/LCD/LCD_config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/LCD/LCD_interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/LCD/LCD_private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/LCD/LCD_program.c` | LCD transfers/formatting; const API, bounded int32 formatting, stub returns failure |
| `master/HAL/LM35/LM35_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/LM35/LM35_Prog.c` | 16-bit write through 8-bit output pointer fixed; 5 V conversion explicit |
| `master/HAL/Step_Motor/SM_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/HAL/Step_Motor/SM_Prog.c` | Coil sequencing; wide counter/pin isolation; unused half-step still limited |
| `master/LIB/BIT_MATH.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/LIB/STD_TYPES.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/ADC/ADC_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/ADC/ADC_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/ADC/ADC_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/ADC/ADC_Prog.c` | ADC mux selection/result width; channel mask corrected |
| `master/MCAL/DIO/DIO_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/DIO/DIO_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/DIO/DIO_Program.c` | PORT value mistakenly wrote DDR; fixed |
| `master/MCAL/EXT_INT/EXT_INT_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/EXT_INT/EXT_INT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/EXT_INT/EXT_INT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/EXT_INT/EXT_INT_Prog.c` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/GPT_Timer/GPT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/GPT_Timer/GPT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/GPT_Timer/GPT_Prog.c` | Timer0 mode/prescaler source; prescaler field mask corrected |
| `master/MCAL/Global_INT/Global_INT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/Global_INT/Global_INT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/Global_INT/Global_INT_Prog.c` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/SPI/SPI_interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/SPI/SPI_private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/SPI/SPI_program.c` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/TWI/TWI_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/TWI/TWI_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/TWI/TWI_Prog.c` | Explicit W1C/status/error handling and bounded polling |
| `master/MCAL/USART/USART_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/USART/USART_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/USART/USART_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/MCAL/USART/USART_Prog.c` | UART init/read/write; uninitialized string index corrected |
| `master/SERVICE/InteractiveLCD_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/SERVICE/InteractiveLCD_Prog.c` | Slave1 menus; master copy is commented legacy code |
| `master/SERVICE/Security_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/SERVICE/Security_Prog.c` | PIN/input/EEPROM or phone entry logic; width/pointer/bounds fixes |
| `master/SERVICE/Services_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/SERVICE/Services_Prog.c` | Board-specific light/temperature/device or clock/alarm logic |
| `master/TMU/TMU_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/TMU/TMU_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/TMU/TMU_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `master/TMU/TMU_Prog.c` | Unchecked periodic tasks inside ISR; foreground dispatcher and bounds added |
| `slave1/.cproject` | Repository presentation/build/configuration inspected; unsupported README claims replaced |
| `slave1/.project` | Eclipse metadata/configuration inspected; target/clock checked where recorded |
| `slave1/.settings/de.innot.avreclipse.core.prefs` | Eclipse metadata/configuration inspected; target/clock checked where recorded |
| `slave1/APP.c` | Application entry point; board-specific flow and source pin map |
| `slave1/HAL/EEPROM/EEPROM_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/EEPROM/EEPROM_Interface.h` |
| `slave1/HAL/EEPROM/EEPROM_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/EEPROM/EEPROM_Private.h` |
| `slave1/HAL/EEPROM/EEPROM_Prog.c` | Banked-address interface; repeated START and error defaults; baseline identical to `master/HAL/EEPROM/EEPROM_Prog.c` |
| `slave1/HAL/Key_Pad/KP_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/Key_Pad/KP_Config.h` |
| `slave1/HAL/Key_Pad/KP_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/Key_Pad/KP_Interface.h` |
| `slave1/HAL/Key_Pad/KP_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/Key_Pad/KP_Private.h` |
| `slave1/HAL/Key_Pad/KP_Prog.c` | 3-column config and blocking held-key scan; fixed |
| `slave1/HAL/LCD/LCD_config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/LCD/LCD_config.h` |
| `slave1/HAL/LCD/LCD_interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave1/HAL/LCD/LCD_private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/LCD/LCD_private.h` |
| `slave1/HAL/LCD/LCD_program.c` | LCD transfers/formatting; const API, bounded int32 formatting, stub returns failure |
| `slave1/HAL/LM35/LM35_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/LM35/LM35_Interface.h` |
| `slave1/HAL/LM35/LM35_Prog.c` | 16-bit write through 8-bit output pointer fixed; 5 V conversion explicit; baseline identical to `master/HAL/LM35/LM35_Prog.c` |
| `slave1/LIB/BIT_MATH.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/LIB/BIT_MATH.h` |
| `slave1/LIB/STD_TYPES.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/LIB/STD_TYPES.h` |
| `slave1/MCAL/ADC/ADC_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/ADC/ADC_Config.h` |
| `slave1/MCAL/ADC/ADC_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/ADC/ADC_Interface.h` |
| `slave1/MCAL/ADC/ADC_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/ADC/ADC_Private.h` |
| `slave1/MCAL/ADC/ADC_Prog.c` | ADC mux selection/result width; channel mask corrected; baseline identical to `master/MCAL/ADC/ADC_Prog.c` |
| `slave1/MCAL/DIO/DIO_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/DIO/DIO_Interface.h` |
| `slave1/MCAL/DIO/DIO_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/DIO/DIO_Private.h` |
| `slave1/MCAL/DIO/DIO_Program.c` | PORT value mistakenly wrote DDR; fixed; baseline identical to `master/MCAL/DIO/DIO_Program.c` |
| `slave1/MCAL/EXT_INT/EXT_INT_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Config.h` |
| `slave1/MCAL/EXT_INT/EXT_INT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Interface.h` |
| `slave1/MCAL/EXT_INT/EXT_INT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Private.h` |
| `slave1/MCAL/EXT_INT/EXT_INT_Prog.c` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Prog.c` |
| `slave1/MCAL/GPT_Timer/GPT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/GPT_Timer/GPT_Interface.h` |
| `slave1/MCAL/GPT_Timer/GPT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/GPT_Timer/GPT_Private.h` |
| `slave1/MCAL/GPT_Timer/GPT_Prog.c` | Timer0 mode/prescaler source; prescaler field mask corrected; baseline identical to `master/MCAL/GPT_Timer/GPT_Prog.c` |
| `slave1/MCAL/Global_INT/Global_INT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/Global_INT/Global_INT_Interface.h` |
| `slave1/MCAL/Global_INT/Global_INT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/Global_INT/Global_INT_Private.h` |
| `slave1/MCAL/Global_INT/Global_INT_Prog.c` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/Global_INT/Global_INT_Prog.c` |
| `slave1/MCAL/TWI/TWI_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/TWI/TWI_Interface.h` |
| `slave1/MCAL/TWI/TWI_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/TWI/TWI_Private.h` |
| `slave1/MCAL/TWI/TWI_Prog.c` | Explicit W1C/status/error handling and bounded polling; baseline identical to `master/MCAL/TWI/TWI_Prog.c` |
| `slave1/MCAL/USART/USART_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/USART/USART_Config.h` |
| `slave1/MCAL/USART/USART_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave1/MCAL/USART/USART_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave1/MCAL/USART/USART_Prog.c` | UART init/read/write; uninitialized string index corrected |
| `slave1/SERVICE/InteractiveLCD_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave1/SERVICE/InteractiveLCD_Prog.c` | Slave1 menus; master copy is commented legacy code |
| `slave1/SERVICE/Security_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave1/SERVICE/Security_Prog.c` | PIN/input/EEPROM or phone entry logic; width/pointer/bounds fixes |
| `slave1/SERVICE/Services_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave1/SERVICE/Services_Prog.c` | Board-specific light/temperature/device or clock/alarm logic |
| `slave1/TMU/TMU_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/TMU/TMU_Config.h` |
| `slave1/TMU/TMU_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/TMU/TMU_Interface.h` |
| `slave1/TMU/TMU_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/TMU/TMU_Private.h` |
| `slave1/TMU/TMU_Prog.c` | Unchecked periodic tasks inside ISR; foreground dispatcher and bounds added; baseline identical to `master/TMU/TMU_Prog.c` |
| `slave2/.cproject` | Repository presentation/build/configuration inspected; unsupported README claims replaced |
| `slave2/.project` | Eclipse metadata/configuration inspected; target/clock checked where recorded |
| `slave2/.settings/de.innot.avreclipse.core.prefs` | Eclipse metadata/configuration inspected; target/clock checked where recorded |
| `slave2/APP.c` | Application entry point; board-specific flow and source pin map |
| `slave2/HAL/EEPROM/EEPROM_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/EEPROM/EEPROM_Interface.h` |
| `slave2/HAL/EEPROM/EEPROM_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/EEPROM/EEPROM_Private.h` |
| `slave2/HAL/EEPROM/EEPROM_Prog.c` | Banked-address interface; repeated START and error defaults; baseline identical to `master/HAL/EEPROM/EEPROM_Prog.c` |
| `slave2/HAL/Key_Pad/KP_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/Key_Pad/KP_Config.h` |
| `slave2/HAL/Key_Pad/KP_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/Key_Pad/KP_Interface.h` |
| `slave2/HAL/Key_Pad/KP_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/Key_Pad/KP_Private.h` |
| `slave2/HAL/Key_Pad/KP_Prog.c` | 3-column config and blocking held-key scan; fixed; baseline identical to `slave1/HAL/Key_Pad/KP_Prog.c` |
| `slave2/HAL/LCD/LCD_config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/LCD/LCD_config.h` |
| `slave2/HAL/LCD/LCD_interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `slave1/HAL/LCD/LCD_interface.h` |
| `slave2/HAL/LCD/LCD_private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/LCD/LCD_private.h` |
| `slave2/HAL/LCD/LCD_program.c` | LCD transfers/formatting; const API, bounded int32 formatting, stub returns failure; baseline identical to `slave1/HAL/LCD/LCD_program.c` |
| `slave2/HAL/LM35/LM35_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/HAL/LM35/LM35_Interface.h` |
| `slave2/HAL/LM35/LM35_Prog.c` | 16-bit write through 8-bit output pointer fixed; 5 V conversion explicit; baseline identical to `master/HAL/LM35/LM35_Prog.c` |
| `slave2/LIB/BIT_MATH.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/LIB/BIT_MATH.h` |
| `slave2/LIB/STD_TYPES.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/LIB/STD_TYPES.h` |
| `slave2/MCAL/ADC/ADC_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/ADC/ADC_Config.h` |
| `slave2/MCAL/ADC/ADC_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave2/MCAL/ADC/ADC_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave2/MCAL/ADC/ADC_Prog.c` | ADC mux selection/result width; channel mask corrected |
| `slave2/MCAL/DIO/DIO_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/DIO/DIO_Interface.h` |
| `slave2/MCAL/DIO/DIO_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/DIO/DIO_Private.h` |
| `slave2/MCAL/DIO/DIO_Program.c` | PORT value mistakenly wrote DDR; fixed; baseline identical to `master/MCAL/DIO/DIO_Program.c` |
| `slave2/MCAL/EXT_INT/EXT_INT_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Config.h` |
| `slave2/MCAL/EXT_INT/EXT_INT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Interface.h` |
| `slave2/MCAL/EXT_INT/EXT_INT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Private.h` |
| `slave2/MCAL/EXT_INT/EXT_INT_Prog.c` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/EXT_INT/EXT_INT_Prog.c` |
| `slave2/MCAL/GPT_Timer/GPT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/GPT_Timer/GPT_Interface.h` |
| `slave2/MCAL/GPT_Timer/GPT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/GPT_Timer/GPT_Private.h` |
| `slave2/MCAL/GPT_Timer/GPT_Prog.c` | Timer0 mode/prescaler source; prescaler field mask corrected; baseline identical to `master/MCAL/GPT_Timer/GPT_Prog.c` |
| `slave2/MCAL/Global_INT/Global_INT_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/Global_INT/Global_INT_Interface.h` |
| `slave2/MCAL/Global_INT/Global_INT_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/Global_INT/Global_INT_Private.h` |
| `slave2/MCAL/Global_INT/Global_INT_Prog.c` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/Global_INT/Global_INT_Prog.c` |
| `slave2/MCAL/TWI/TWI_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/TWI/TWI_Interface.h` |
| `slave2/MCAL/TWI/TWI_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/TWI/TWI_Private.h` |
| `slave2/MCAL/TWI/TWI_Prog.c` | Explicit W1C/status/error handling and bounded polling; baseline identical to `master/MCAL/TWI/TWI_Prog.c` |
| `slave2/MCAL/USART/USART_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/MCAL/USART/USART_Config.h` |
| `slave2/MCAL/USART/USART_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `slave1/MCAL/USART/USART_Interface.h` |
| `slave2/MCAL/USART/USART_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `slave1/MCAL/USART/USART_Private.h` |
| `slave2/MCAL/USART/USART_Prog.c` | UART init/read/write; uninitialized string index corrected; baseline identical to `slave1/MCAL/USART/USART_Prog.c` |
| `slave2/SERVICE/Services_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable |
| `slave2/SERVICE/Services_Prog.c` | Board-specific light/temperature/device or clock/alarm logic |
| `slave2/TMU/TMU_Config.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/TMU/TMU_Config.h` |
| `slave2/TMU/TMU_Interface.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/TMU/TMU_Interface.h` |
| `slave2/TMU/TMU_Private.h` | Driver/interface/configuration declarations inspected; direct ATmega32 registers where applicable; baseline identical to `master/TMU/TMU_Private.h` |
| `slave2/TMU/TMU_Prog.c` | Unchecked periodic tasks inside ISR; foreground dispatcher and bounds added; baseline identical to `master/TMU/TMU_Prog.c` |
