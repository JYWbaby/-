void Init()
{
	//ϵͳ��ʼ��
	
	//delay_Init
	 
	 //pid�㷨��ʼ��
		pid_Init();
	
	 //���pwm�����ʼ��
		ftm_motor_pwm_Init();
	
	 //���pwm�����ʼ��
		ftm_servo_pwm_Init();
	
   //������ftm��ʼ��	
		ftm_encorder_Init();
	
	 //pit��ʼ��
	  pit_init();
	
	  //adc��ʼ��
	  adc_Init();
}