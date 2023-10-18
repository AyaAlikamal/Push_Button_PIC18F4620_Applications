/* 
 * File:   ecu_led_cfg.h
 * Author: AyaAli
 *
 * Created on October 9, 2023, 8:05 AM
 */

#ifndef ECU_LED_CFG_H
#define	ECU_LED_CFG_H
/*Section : Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led.h"



/*Section : Data Type Declaration*/
typedef enum{
    LED_OFF=0,
    LED_ON  
}led_status_t;

typedef struct{
    uint_8 Port_Name :4;
    uint_8 pin : 3 ;
    uint_8 led_statues: 1;
}led_t;

/*Section : Macro Declaration*/

/*Section : Macro Function Declaration*/



/*Section : Function Declaration*/
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_toggle(const led_t *led);

#endif	/* ECU_LED_CFG_H */

