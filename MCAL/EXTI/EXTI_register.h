/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: EXTI                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:16/2/2024           *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define EXTI_MCUCR    (*(( volatile u8 *)0X55))
#define EXTI_MCUCSR   (*(( volatile u8 *)0X54))
#define EXTI_GICR     (*(( volatile u8 *)0X5B))
#define EXTI_GIFR     (*(( volatile u8 *)0X5A))


#endif