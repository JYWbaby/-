#include <headdfile.h>

/*舵机PID部分参数_______________________*/
extern float d;  //角度(偏差值)
extern int PWM;  //舵机pwm
extern float error,lasterror,preverror,derror;
extern float kp,kd;//舵机控制PD
extern float kp_j,kp_c,kp_x;
int value1; 
uint8_t dir;    

#define N_Speed_Filter  10    //速度滤波函数的N值
#dedine N_ADC_Filter    10    //ADC滤波的N值
float adc_value1,adc_value2;//ADC作差处理值
int Value1=0;//编码器读数定义
int adc_afterfilter[]={0,0,0,0,0}; //adc_afterfilter[0]空置，1-4分别为滤波后adc值
int adc_max[]={0,0,0,0,0};         //adc归一化过程中读到的最大值
int adc_normalized[]={0,0,0,0,0}; //adc_normalized[0]空置，1-4分别为归一化后adc值


//****************************************************************************
//  函数名：Paramater_Init(void)
//  功能： 电机和舵机PID参数初始化
//  说明：无
//*****************************************************************************/
/*
void Paramater_Init(void)
{
//舵机PID部分初始化
	error=0;
	derror=0;
	lasterror=0;
	preverror=0;

	kp=0.3;   
	kd=0.45; 
	kp_j=0.01;
	kp_c=3500.0;
	kp_x=0.3;
	
}
*/
/*舵机控制部分_________________________*/

//****************************************************************************
//  函数名：duoji_control(void) 
//  功能：舵机控制函数
//  说明：无
//*****************************************************************************/
/*void duoji_control(void)                         
{	
	derror=error-lasterror;
	lasterror=error;
	kp = kp_j + (error *error)/kp_c;
	if(kp>=kp_x)kp=kp_x;  
	//kp=0.3;
	d=-(kp*error+kd*derror);		
	if(d>30)	d=30;
	if(d<-30)	d=-30;
	PWM = ((d+102.2)/90.0+0.5)/20 * 10000;	
	FTM_PWM_ChangeDuty(HW_FTM1, HW_FTM_CH0, PWM);
}
*/











/****************************电机和舵机pid参数初始化**********/
void startpid_Init(void)
{
//电机
//舵机
}



/*****************************舵机控制**********/
void servo_control(void) 
{
//pid参数转化 同时转换占空比

FTM_PWM_ChangeDuty(HW_FTM1, HW_FTM_CH0, PWM);
}



/*****************************电机控制***********/
void Motor_Control()
{
//传入计算出的pid
pid参数转化 同时转换占空比

FTM_PWM_ChangeDuty(HW_FTM1, HW_FTM_CH0, PWM);
}





/*****************************速度滤波********/
int16_t Speed_Filter() 
{
	int speed;
 char value_buf[N_Speed_Filter]; 
   char count,i,j,temp; 
   for ( count=0;count<N_Speed_Filter;count++)           //N可调
   { 
      value_buf[count] = GetSpeed()；
      //delay();    此处需延时很短一段时间，具体后面调试的时候确定
   } 
   for (j=0;j<N_Speed_Filter-1;j++) 
   { 
      for (i=0;i<N_Speed_Filter-j;i++) 
      { 
         if ( value_buf[i]>value_buf[i+1] ) 
         { 
            temp = value_buf[i]; 
            value_buf[i] = value_buf[i+1];  
             value_buf[i+1] = temp; 
         } 
      } 
   } 
speed=value_buf[(N_Speed_Filter-1)/2];//排序之后输出中间值
return speed;   //可以用返回值或设speed为全局变量在其他函数中调用
}



//*************将ADC处理值和编码器滤波值传入control函数执行控制程序
void contol(location,speed)
{
	
	
}



//***********处理adc读取值（滤波、归一化、获得相对位置）
void adc_deal()
{
	ADC_Filter();//得到4路adc滤波后的有效值
	
}


//***********对ADC读取并进行滤波处理
void ADC_Filter()
{
for(temp2=1;temp2<=4;temp2++)
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

void GetADC(temp)
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

//****************停车
void stop()
{
	GPIO_WriteBit(HW_GPIOx, x, 0);
	GPIO_WriteBit(HW_GPIOx, x, 0);//关闭电机和舵机使能
}
