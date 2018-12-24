#include <headdfile.h>

uint8_t AG_counter,SP_counter,DIR_counter;
extern int value1;
extern uint8_t dir;

/**************************************************
//   函数名: Car_PIT1_Init()
//   功能:   模块1中断初始化
//   说明:     
***************************************************/
void  Car_PIT1_Init()
{
    PIT_QuickInit(HW_PIT_CH1, 2000);  
    PIT_CallbackInstall(HW_PIT_CH1, PIT1_CallBack); //注册回调
    PIT_ITDMAConfig(HW_PIT_CH1, kPIT_IT_TOF,ENABLE); //开启中断
}

//****************************************************************************
//  函数名：PIT1_CallBack(void)
//  功能：PIT1中断处理函数
//  说明：舵机电机控制处理函数
//*****************************************************************************/
void PIT1_CallBack(void)    
{	
	static uint16_t  fcflag=0;
	
	//int value1;
	 fcflag++;
		  AG_counter++;
	
  FTM_QD_GetData(HW_FTM2, &value1, &dir);
		// FTM_QD_GetData(HW_FTM1, &PUL_R,&dir);
	//GetSpeed();
	//Set_Speed();
	//Motor_Control();
}


