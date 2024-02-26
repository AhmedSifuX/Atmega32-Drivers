/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: EXTI                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:16/2/2024           *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_INT0    6
#define EXTI_INT1    7
#define EXTI_INT2    5



#define EXTI_SENSE_CTRL_RISING_EDGE  0
#define EXTI_SENSE_CTRL_FALLING_EDGE 1
#define EXTI_SENSE_CTRL_ON_CHANGE    2
#define EXTI_SENSE_CTRL_LOW_LEVEL    3




u8 EXTI_u8INTPeripheralEnable(u8 copy_u8IntID,u8 copy_u8SenseControl);
u8 EXTI_u8INTPeripheralDisable(u8 copy_u8INTid);

u8 EXTI_u8CallBackFunction(u8 copy_u8IntID,void(*ptrToFunction)(void));





#endif
