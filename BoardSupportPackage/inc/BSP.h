/*
 * BSP.h
 *
 *  Created on: Dec 30, 2016
 *      Author: Raz Aloni
 */

#ifndef BSP_H_
#define BSP_H_

/* Includes */

#include <stdint.h>
#include "bme280_support.h"
#include "bmi160_support.h"
#include "opt3001.h"
#include "tmp007.h"
#include "BackChannelUart.h"
#include "ClockSys.h"
#include "Joystick.h"
// Insert include for LEDs here 
#include "RGB_I2C_Driver.h"
#include "RGBLeds.h"


/********************************** Public Functions **************************************/

/* Initializes the entire board */
extern void BSP_InitBoard();

/********************************** Public Functions **************************************/

#endif /* BSP_H_ */
