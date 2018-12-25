#include <headdfile.h>

void ADC_user_init()
{
	
	/* 初始化ADC模块 ADC0*/
    ADC_InitTypeDef ADC_InitStruct1;
    ADC_InitStruct1.instance = HW_ADC0;
    ADC_InitStruct1.clockDiv = kADC_ClockDiv2; /* ADC采样时钟2分频 */
    ADC_InitStruct1.resolutionMode = kADC_SingleDiff12or13;
    ADC_InitStruct1.triggerMode = kADC_TriggerSoftware; /* 软件触发转换 */
    ADC_InitStruct1.singleOrDiffMode = kADC_Single; /*单端模式 */
    ADC_InitStruct1.continueMode = kADC_ContinueConversionDisable; /* 启动连续转换 转换一次后 自动开始下一次转换*/
    ADC_InitStruct1.hardwareAveMode = kADC_HardwareAverageDisable; /*禁止 硬件平均 功能 */
    ADC_InitStruct1.vref = kADC_VoltageVREF;                       /* 使用外部VERFH VREFL 作为模拟电压参考 */
    ADC_Init(&ADC_InitStruct1);
	
	/* 初始化ADC模块 ADC1 */
    ADC_InitStruct1.instance = HW_ADC1;
    ADC_InitStruct1.clockDiv = kADC_ClockDiv2; /* ADC采样时钟2分频 */
    ADC_InitStruct1.resolutionMode = kADC_SingleDiff12or13;
    ADC_InitStruct1.triggerMode = kADC_TriggerSoftware; /* 软件触发转换 */
    ADC_InitStruct1.singleOrDiffMode = kADC_Single; /*单端模式 */
    ADC_InitStruct1.continueMode = kADC_ContinueConversionDisable; /* 启动连续转换 转换一次后 自动开始下一次转换*/
    ADC_InitStruct1.hardwareAveMode = kADC_HardwareAverageDisable; /*禁止 硬件平均 功能 */
    ADC_InitStruct1.vref = kADC_VoltageVREF;                       /* 使用外部VERFH VREFL 作为模拟电压参考 */
    ADC_Init(&ADC_InitStruct1);
    
    /* 初始化对应引脚 */
    /* 引脚为专门的模拟引脚*/
    
    
}


