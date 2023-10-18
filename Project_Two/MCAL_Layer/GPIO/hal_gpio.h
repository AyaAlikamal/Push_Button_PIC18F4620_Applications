/* 
 * File:   hal_gpio.h
 * Author: AyaAli
 *
 * Created on September 22, 2023, 10:34 AM
 */


#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/*Section : Includes*/
#include "../../../../Embeded-Compiler/pic/include/proc/pic18f4620.h"
#include "../mcal_std_type.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"

/*Section : Data Type Declaration*/
typedef unsigned char        uint_8;
typedef unsigned short       uint_16;
typedef unsigned int         uint_32;

typedef signed char        sint_8;
typedef signed short       sint_16;
typedef signed int         sint_32;

typedef uint_8 Std_ReturnType;

/*Section : Macro Declaration*/
#define STD_HIGH          0x01
#define STD_LOW           0x00
#define STD_ON            0x01
#define STD_OFF           0x00
#define STD_ACTIVE        0x01
#define STD_IDLE          0x00
#define E_OK              (Std_ReturnType)0x01
#define E_NOT_OK          (Std_ReturnType)0x00


#define BIT_MASK 1
#define PORT_PIN_MAX_NUMBER 8
#define PORT_MAX_NUMBER  5 
#define PORTC_MASK 0xFF


#define GPIO_PORT_PIN_CONFIGRATION CONFIG_ENABLE
#define GPIO_PORT_CONFIGRATION CONFIG_ENABLE





/*Section : Macro Function Declaration*/



/*Section : Function Declaration*/

Std_ReturnType gpio_pin_direction_intialize(const pin_config_t * pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t * pin_config, direction_t * direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t * pin_config, logic_t  logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t * pin_config, logic_t * logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t * pin_config);
Std_ReturnType gpio_pin_intialize(const pin_config_t * pin_config);


Std_ReturnType gpio_port_direction_intialize(Port_Index port, uint_8 direction);
Std_ReturnType gpio_port_get_direction_status(Port_Index port, uint_8 *direction_status);
Std_ReturnType gpio_port_write_logic(Port_Index port, uint_8 logic);
Std_ReturnType gpio_port_read_logic(Port_Index port, uint_8 *logic);
Std_ReturnType gpio_port_toggle_logic(Port_Index port);

#endif	/* HAL_GPIO_H */

