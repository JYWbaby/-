#include <headdfile.h>
#include "initx.h"

void initx(void)
{
	  DelayInit();    //延时初始化
    UART_QuickInit(UART0_RX_PD06_TX_PD07, 115200);              //串口初始化                  /* 初始化一个串口 使用UART0端口的PTD6引脚和PTD7引脚作为接收和发送，默认设置 baud 115200 */
	  Car_PIT1_Init();
	  ADC_user_init();

	
	
//	  FTM_PWM_QuickInit(FTM2_CH1_PB19, kPWM_EdgeAligned, 1000);  //FTM0  通道3 PTA6   1000HZ   pwm,默认  50%占空比)
	
//	  FTM_QD_QuickInit(FTM1_QD_PHA_PA08_PHB_PA09, kFTM_QD_NormalPolarity, kQD_CountDirectionEncoding);  //正交解码初始化  
	
}


































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


	
