/* 
 * File:   mcal_std_type.h
 * Author: AyaAli
 *
 * Created on September 22, 2023, 10:45 AM
 */

#ifndef MCAL_STD_TYPE_H
#define	MCAL_STD_TYPE_H

/*Section : Includes*/
#include "std_libraries.h"
#include "compiler.h"

/*Section : Macro Declaration*/

typedef unsigned char        uint_8;
typedef unsigned short       uint_16;
typedef unsigned int         uint_32;

typedef signed char        sint_8;
typedef signed short       sint_16;
typedef signed int         sint_32;
typedef uint_8 Std_ReturnType;

/*Section : Macro Function Declaration*/
#define HWREG8 (_X)  (*((volatile uint_8 *)(_X)))


#define SET_BIT(REG, BIT_POSN)      (REG |= (BIT_MASK<<BIT_POSN))  
#define CLEAR_BIT(REG, BIT_POSN)        (REG &= ~(BIT_MASK<<BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)     (REG ^=(BIT_MASK<<BIT_POSN))
#define READ_BIT(REG, BIT_POSN)       ((REG >>BIT_POSN)&BIT_MASK)




/*Section : Data Type Declaration*/
typedef enum{
    LOW = 0,
    HIGH        
}logic_t;


typedef enum{
    Output = 0,
    Input      
}direction_t;

typedef enum{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7        
}pin_index;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX        
}Port_Index;

typedef struct{
    uint_8 port :3;
    uint_8 pin  :3;
    uint_8 direction :1;
    uint_8 logic : 1;
}pin_config_t;

/*Section : Function Declaration*/



#endif	/* MCAL_STD_TYPE_H */

