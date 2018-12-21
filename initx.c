void Init()
{
	//系统初始化
	
	gpio_Init();
	
	delay_Init();
	 
	 //pid算法初始化
		pid_Init();
	
	 //电机pwm输出初始化
		ftm_motor_pwm_Init();
	
	 //舵机pwm输出初始化
		ftm_servo_pwm_Init();
	
   //编码器gpio初始化	
		GPIO_QuickInit(HW_GPIOC,6, kGPIO_Mode_IPU);
   //编码器计数初始化
	        LPTMR_PC_QuickInit(LPTMR_ALT2_PC05);
	 
	
	//pit初始化
	{
	//这里面也要产生正常中断 才可以调用那个计数函数
	}
	  //adc初始化
	  adc_Init();
	
	 //干簧管初始化
	reed_Init();
		
	  //oled初始化
	oled_Init();
}
