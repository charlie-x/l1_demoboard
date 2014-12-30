/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/
#define led_init() {  _ODB7 = 1; _LATB7 = 1; _TRISB7 = 0;}
#define led_off()   { _LATB7 = 0; }
#define led_on()  { _LATB7 = 1; }
/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
extern void  reset( void ) ;

int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

   ANSB = 0;
    /* TODO <INSERT USER APPLICATION CODE HERE> */
   led_init();


    {
        unsigned int counter;
    led_off();
    counter=40000;
    while(counter--);
    led_on();
    counter=40000;
    while(counter--);
    }

   reset();
}
