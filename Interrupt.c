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
	int speed_afterfilter;//滤波后速度值
	int position;//相对位置
	 
		  fcflag++;
		  AG_counter++;
	speed_afterfilter=Speed_Filter();
	position=adc_deal();//四路ADC滤波值记录在全局变量adc_afterfilter[]中，经归一化处理为adc_normalized[];最后得到处理后position状态
	oled_display(speed_afterfilter,position);//OLED显示
	control(speed_afterfilter,position);//根据速度值和相对位置带入算法调整电机和舵机的状态
	
		
}


