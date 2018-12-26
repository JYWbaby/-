void Read_ADC(void)
{
     int16_t  i;
     int16_t  ad_valu[4][4];
     for(i=0;i<4;i++)
     {
         ad_valu[0][i]=AD_aver(5,ADC1_SE6_PE2);  			// AD1
         ad_valu[1][i]=AD_aver(5,ADC1_SE6_PE2);       	// AD2
         ad_valu[2][i]=AD_aver(5,ADC1_SE6_PE2);  			// AD3
         ad_valu[3][i]=AD_aver(5,ADC1_SE6_PE2);     		// AD4
         //ad_valu[4][i]=ad_ave(AD_Mid , ADC_12bit, 5);     		// AD5ÖÐ¼ä		 
     }
}


//此函数为ad信号读取滤波后的信号 我在底层修改了AD_aver() ad_valu[4][i]这是一个读取adc值后均值滤波后的数组 相应的.c和.h还有底层已修改，类似邓宇邦程序 







































































#include <headdfile.h>
#dedine N_ADC_Filter    10    //ADC滤波的N值
int adc_afterfilter[]={0,0,0,0,0}; //adc_afterfilter[0]空置，1-4分别为滤波后adc值
int adc_max[]={0,0,0,0,0};         //adc归一化过程中读到的最大值
int adc_normalized[]={0,0,0,0,0}; //adc_normalized[0]空置，1-4分别为归一化后adc值

#define left2 adc_afterfilter[1]
#define left1 adc_afterfilter[2]
#define right1 adc_afterfilter[3]
#define right2 adc_afterfilter[4]





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


//***********处理adc读取值（滤波、归一化、获得相对位置）
void adc_deal()
{
	ADC_Filter();//得到4路adc滤波后的有效值
	if(left1)
	{	
		
		
	
}


//***********对ADC读取并进行滤波处理
void ADC_Filter()
{
for(temp2=1;temp2<=4;temp2++)       //读取4路ADC
{
	 char value_buf[N_ADC_Filter]; 
   	char count,i,j,temp; 
   	for ( count=0;count<N_ADC_Filter;count++)           //N可调
   	{ 
      	value_buf[count] = GetADC(temp2)；
      	//delay();    此处需延时很短一段时间，具体后面调试的时候确定
  	 } 
   	for (j=0;j<N_ADC_Filter-1;j++) 
  	 { 
     	 	for (i=0;i<N_ADC_Filter-j;i++) 
      		{ 
         		if ( value_buf[i]>value_buf[i+1] ) 
        	 	{ 
          	  		temp = value_buf[i]; 
			   	value_buf[i] = value_buf[i+1];  
         	    		value_buf[i+1] = temp; 
         		} 
       		 } 
  	 } 
	adc_afterfilter[temp2]=value_buf[(N_ADC_Filter-1)/2];//排序之后输出中间值
}

//读取某一ADC数值
int GetADC(temp)
{	
	char channel[];
	int number;
	
	switch(temp)
	{	
		case 1:{channel="HW_ADC0";number=1;};break;  //0p1
		case 2:{channel="HW_ADC1";number=1;};break;  //1p1
		case 3:{channel="HW_ADC1";number=3;};break;  //1p3
		case 4:{channel="HW_ADC0";number=3;};break;  //0p3
	}
	
	    /* 启动一次ADC转换 */
    ADC_StartConversion(channel,number, kADC_MuxA);
    
    while(1)
    {
        /* 如果ADC转换完成 */
        if(ADC_IsConversionCompleted(channel, kADC_MuxA) == 0)
        {
            /* 读取ADC的值   */
            return ADC_ReadValue(channel, kADC_MuxA);
        }
       
    }
}
