/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

led_t led_1 = {
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF,
};

button_t btn_high= {
.button_pin.port = PORTD_INDEX,
.button_pin.pin = PIN0,
.button_pin.direction = Input,
.button_pin.logic = LOW,
.button_connection = BUTTON_ACTIVE_HIGH,
.button_state= BUTTON_RELEASED,
};

button_state_t btn_button_high_st = BUTTON_RELEASED;

button_state_t btn_button_high_valid_st = BUTTON_RELEASED;
button_state_t btn_button_high_last_valid_st = BUTTON_RELEASED;

led_status_t led_st = LED_OFF;

uint_32 valid_button = 0;


int main() {
    
Std_ReturnType ret = E_NOT_OK;
application_initialize();


while(1){
  
ret = Button_Read_State(&btn_high,&btn_button_high_st);

if(btn_button_high_st == BUTTON_PRESSED){
valid_button++;
if (valid_button >500){
btn_button_high_valid_st = BUTTON_PRESSED;
}
}

else{
valid_button = 0;
btn_button_high_valid_st = BUTTON_RELEASED;
}

if(btn_button_high_valid_st != btn_button_high_last_valid_st){
btn_button_high_last_valid_st = btn_button_high_valid_st;
if(btn_button_high_valid_st == BUTTON_PRESSED ){
    if(led_st == LED_OFF){
    led_turn_on(&led_1);
    led_st = LED_ON;
    }
    else{
    led_turn_off(&led_1);    
    led_st = LED_OFF;
    }
    
}
}  
  }
  return (EXIT_SUCCESS);
}
void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
ret = Button_Initialize(&btn_high);

ret = led_initialize(&led_1);

}