/***********************************************************************/
/***********************************************************************/
/********************  Author: Ahmed Hany      *************************/
/********************  SWC: SVNSeg             *************************/
/********************  LAYER: HAL              *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:21/2/2024          *************************/
/***********************************************************************/
/***********************************************************************/

#define  F_CPU 16000000
#include <util/delay.h>

/*LIB*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Error_State.h"

/*DIO*/
#include "DIO_interface.h"

/*SevenSegment*/
#include "SVNSeg_config.h"
#include "SVNSeg_interface.h"
#include "SVNSeg_private.h"



void SVN_INIT()
{
	DIO_u8SetPinDirection(SVN_DATA_PORT,SVN_DATA_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SVN_DATA_PORT,SVN_DATA_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SVN_DATA_PORT,SVN_DATA_PIN3,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SVN_DATA_PORT,SVN_DATA_PIN4,DIO_PIN_OUTPUT);
	
	//ENABLE SSD1
	DIO_u8SetPinDirection(SVN_ENABLE_PORT,SVN_EN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(SVN_ENABLE_PORT,SVN_EN1,DIO_PIN_HIGH);
	//ENABLE SSD2
	DIO_u8SetPinDirection(SVN_ENABLE_PORT,SVN_EN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(SVN_ENABLE_PORT,SVN_EN2,DIO_PIN_HIGH);
	

}

void SVN_SetDigit(u8 num)
{
	ASSIGN_BIT(PORTA,4,GET_BIT(num,0));
	ASSIGN_BIT(PORTA,5,GET_BIT(num,1));
	ASSIGN_BIT(PORTA,6,GET_BIT(num,2));
	ASSIGN_BIT(PORTA,7,GET_BIT(num,3));

}