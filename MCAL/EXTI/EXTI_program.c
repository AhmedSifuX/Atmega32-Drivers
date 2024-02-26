#include "STD_TYPES.h"
#include "Error_State.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

void (*ptrToFunction_INT0)(void)=NULL;
void (*ptrToFunction_INT1)(void)=NULL;
void (*ptrToFunction_INT2)(void)=NULL;



u8 EXTI_u8INTPeripheralEnable(u8 copy_u8IntID,u8 copy_u8SenseControl)
{
	
	u8 Local_u8ErrorState=OK;

	/*enable pie*/
	SET_BIT(EXTI_GICR,copy_u8IntID);
	
	switch(copy_u8IntID)
	{
		case EXTI_INT0:
		
		switch(copy_u8SenseControl)
		{
			case EXTI_SENSE_CTRL_RISING_EDGE:
			SET_BIT(EXTI_MCUCR,ISC00);
			SET_BIT(EXTI_MCUCR,ISC01);
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			CLR_BIT(EXTI_MCUCR,ISC00);
			SET_BIT(EXTI_MCUCR,ISC01);
			break;
			case EXTI_SENSE_CTRL_LOW_LEVEL:
			CLR_BIT(EXTI_MCUCR,ISC00);
			CLR_BIT(EXTI_MCUCR,ISC01);
			break;
			case EXTI_SENSE_CTRL_ON_CHANGE:
			SET_BIT(EXTI_MCUCR,ISC00);
			CLR_BIT(EXTI_MCUCR,ISC01);
			break;
			default:Local_u8ErrorState=NOK; break;
		}
		break;
		case EXTI_INT1:
		switch(copy_u8SenseControl)
		{
			case EXTI_SENSE_CTRL_RISING_EDGE:
			SET_BIT(EXTI_MCUCR,ISC10);
			SET_BIT(EXTI_MCUCR,ISC11);
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			CLR_BIT(EXTI_MCUCR,ISC10);
			SET_BIT(EXTI_MCUCR,ISC11);
			break;
			case EXTI_SENSE_CTRL_LOW_LEVEL:
			CLR_BIT(EXTI_MCUCR,ISC10);
			CLR_BIT(EXTI_MCUCR,ISC11);
			break;
			case EXTI_SENSE_CTRL_ON_CHANGE:
			SET_BIT(EXTI_MCUCR,ISC10);
			CLR_BIT(EXTI_MCUCR,ISC11);
			break;
			default:Local_u8ErrorState=NOK; break;
		}
		
		break;
		case EXTI_INT2:
		switch(copy_u8SenseControl)
		{
			case EXTI_SENSE_CTRL_RISING_EDGE:
			SET_BIT(EXTI_MCUCSR,ISC2);
			
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			CLR_BIT(EXTI_MCUCSR,ISC2);
			break;
			default:Local_u8ErrorState=NOK; break;
		}
		
		break;
		
		default:Local_u8ErrorState=NOK; break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8INTPeripheralDisable(u8 copy_u8IntID)
{
	u8 Local_u8ErrorState=OK;

	if(copy_u8IntID>EXTI_INT1 || copy_u8IntID<EXTI_INT2)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		CLR_BIT(EXTI_GICR,copy_u8IntID);
	}
	



	/*
	switch (copy_u8INTid)
	{

	case EXTI_INT0:    CLR_BIT(EXTI_GICR,INT0);  break;
	case EXTI_INT1:    CLR_BIT(EXTI_GICR,INT1);  break;
	case EXTI_INT2:    CLR_BIT(EXTI_GICR,INT2);  break;
	default:           Local_u8ErrorState=NOK; break;
	}

	*/
	return Local_u8ErrorState;

}




u8 EXTI_u8CallBackFunction(u8 copy_u8IntID,void(*ptrToFunction)(void))
{
	
	u8 Local_u8ErrorState=OK;
	if(ptrToFunction != NULL){
		switch (copy_u8IntID)
		{

			case EXTI_INT0:     ptrToFunction_INT0 = ptrToFunction ; break;
			case EXTI_INT1:     ptrToFunction_INT1 = ptrToFunction ; break;
			case EXTI_INT2:     ptrToFunction_INT2 = ptrToFunction ; break;
			default:           Local_u8ErrorState=NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	
	
}

/*INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(ptrToFunction_INT0 != NULL)
	{
		ptrToFunction_INT0();
	}
	else
	{}

}

/*INT1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(ptrToFunction_INT1 != NULL)
	{
		ptrToFunction_INT1();
	}
	else
	{}

}
/*INT2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{

	if(ptrToFunction_INT2 != NULL)
	{
		ptrToFunction_INT2();
	}
	else
	{}


}