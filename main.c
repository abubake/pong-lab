#include "msp.h"
#include <driverlib.h>
#include "G8RTOS.h"
#include "LCD.h"
#include "time.h"
#include "stdlib.h"
#include "cc3100_usage.h"
#include "Game.h"

#define MAIN_LAB5
#ifdef MAIN_LAB5

void main(void){
	/* Initializes all the hardware resources on the board and sets the amount of threads and system time to 0 */
	G8RTOS_Init();

	/* Initializes the Wifi on the host (Switch if you are Client) */
	initCC3100(Host);
	//SendData(_u8 *data, _u32 IP, _u16 BUF_SIZE);


	//Host waits to hear from client
	//BsdUdpServer(_u16 Port, _u8 *data, _u16 BUF_SIZE)

	LCD_Init(true);

	/* For the color randomness */
	srand(time(NULL));

 /* Sets up a semaphore for indicating if the LED resource and the sensor resource are available */
	//G8RTOS_InitSemaphore(&SENSOR_READY, 1);
	G8RTOS_InitSemaphore(&USING_SPI, 1);

	/* Adds each task individually to the system */
	G8RTOS_AddThread(CreateGame, 150, "CreateGame"); //NEEDS real PRI and maybe better nam
	//G8RTOS_AddAPeriodicEvent(LCD_Tap, 3,  PORT4_IRQn);

	G8RTOS_InitFIFO(JOYSTICKFIFO);
	//G8RTOS_InitFIFO(BALLNUMFIFO);

	/* Initializes the Systick to trigger every 1ms and sets the priority for both PendSV and Systick  */
	/* Sets the first thread control block as the current thread, and calls the start_os assembly function */
	G8RTOS_Launch();
}

void PORT4_IRQHandler(void){
        P4IE &= ~BIT0; // disables interrupt on pin 4
        P4IFG &= ~BIT0; // must clear IFG flag to operate
        P4IE |= BIT0; // enable interrupt on pin 4
    }


#endif /* MAIN_LAB5 */


#ifdef MAIN_LAB4

void main(void)
	{
	/* Initializes all the hardware resources on the board and sets the amount of threads and system time to 0 */
	G8RTOS_Init();

	LCD_Init(true);
	/* For the color randomness */
	srand(time(NULL));

 /* Sets up a semaphore for indicating if the LED resource and the sensor resource are available */
	G8RTOS_InitSemaphore(&SENSOR_READY, 1);
	G8RTOS_InitSemaphore(&SPI_READY, 1);

	/* Adds each task individually to the system */
	G8RTOS_AddThread(Read_Accel, 150, "ReadAccel");
	G8RTOS_AddThread(Idle, 200, "Idle");

	G8RTOS_AddAPeriodicEvent(LCD_Tap, 3,  PORT4_IRQn);

	G8RTOS_InitFIFO(BALLFIFO);
	G8RTOS_InitFIFO(BALLNUMFIFO);

	/* Initializes the Systick to trigger every 1ms and sets the priority for both PendSV and Systick  */
	/* Sets the first thread control block as the current thread, and calls the start_os assembly function */
	G8RTOS_Launch();
}

void PORT4_IRQHandler(void){
        P4IE &= ~BIT0; // disables interrupt on pin 4
        P4IFG &= ~BIT0; // must clear IFG flag to operate
        P4IE |= BIT0; // enable interrupt on pin 4
    }

#endif /* MAIN_LAB4 */

