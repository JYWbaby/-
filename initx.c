#include <headdfile.h>
#include "initx.h"


void Initx()
{
	//系统初始化
	
	gpio_Init();
	
	DelayInit();
	 
	 //pid算法初始化
		pid_Init();
	
	 //电机pwm输出初始化
		ftm_motor_pwm_Init();
	
	 //舵机pwm输出初始化
		ftm_servo_pwm_Init();
	
   //编码器gpio初始化	
		GPIO_QuickInit(HW_GPIOC,6, kGPIO_Mode_IPU);
		encoder_init();
	
	
		ADC_user_init();
	
	
	 
	
	//pit初始化
	Car_PIT1_Init();
	
	 //干簧管初始化
	reed_Init();
		
	  //oled初始化
	oled_Init();
}


