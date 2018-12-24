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

/**************ADC模块初始化函数*******8*/
void adc_Init()
{
/* 初始化ADC模块  */
    ADC_InitTypeDef ADC_InitStruct1;
    ADC_InitStruct1.instance = HW_ADC0;
    ADC_InitStruct1.clockDiv = kADC_ClockDiv2; /* ADC采样时钟2分频 */
    ADC_InitStruct1.resolutionMode = kADC_SingleDiff8or9;
    ADC_InitStruct1.triggerMode = kADC_TriggerSoftware; /* 软件触发转换 */
    ADC_InitStruct1.singleOrDiffMode = kADC_Single; /*单端模式 */
    ADC_InitStruct1.continueMode = kADC_ContinueConversionEnable; /* 启动连续转换 转换一次后 自动开始下一次转换*/
    ADC_InitStruct1.hardwareAveMode = kADC_HardwareAverageDisable; /*禁止 硬件平均 功能 */
    ADC_InitStruct1.vref = kADC_VoltageVREF;                       /* 使用外部VERFH VREFL 作为模拟电压参考 */
    ADC_Init(&ADC_InitStruct1);
	
    ADC_InitTypeDef ADC_InitStruct2;
    ADC_InitStruct2.instance = HW_ADC1;
    ADC_InitStruct2.clockDiv = kADC_ClockDiv2; /* ADC采样时钟2分频 */
    ADC_InitStruct2.resolutionMode = kADC_SingleDiff8or9;
    ADC_InitStruct2.triggerMode = kADC_TriggerSoftware; /* 软件触发转换 */
    ADC_InitStruct2.singleOrDiffMode = kADC_Single; /*单端模式 */
    ADC_InitStruct2.continueMode = kADC_ContinueConversionEnable; /* 启动连续转换 转换一次后 自动开始下一次转换*/
    ADC_InitStruct2.hardwareAveMode = kADC_HardwareAverageDisable; /*禁止 硬件平均 功能 */
    ADC_InitStruct2.vref = kADC_VoltageVREF;                       /* 使用外部VERFH VREFL 作为模拟电压参考 */
    ADC_Init(&ADC_InitStruct2);
	
    //初始化对应引脚
	//所用引脚均为ADC专用引脚
}


	
