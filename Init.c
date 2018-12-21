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
	
   //编码器ftm初始化	
		ftm_encorder_Init();
	
	 //pit初始化
	  pit_init();
	
	  //adc初始化
	  adc_Init();
	
	 //干簧管初始化
	reed_Init();
		
	  //oled初始化
	oled_Init();
}
