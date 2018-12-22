//此函数用于根据4个传感器的值和编码器的数值来控制电机和舵机
/*分为3部分
	1.数据处理
	2.方向控制
	3.速度控制

#define N_Speed_Filter  10    //速度滤波函数的N值
float adc_value1,adc_value2;//ADC作差处理值
int Value1=0;//编码器读数定义


//****************************编码器获取数值
void GetSpeed()
{

                                             //计数 
	LPTMR_PC_QuickInit(LPTMR_ALT2_PC05);	
	Value1 = LPTMR_PC_ReadCounter();
	                                    //计数用这个模块 方便！			     
					     
        LPTMR_ClearCounter();                                  //清零
 

}




//****************************电机和舵机pid参数初始化
void startpid_Init(void)
{
//电机
//舵机
}



//*****************************舵机控制
void servo_control(void) 
{
//pid参数转化 同时转换占空比

FTM_PWM_ChangeDuty(HW_FTM1, HW_FTM_CH0, PWM);
}



//*****************************电机控制
void Motor_Control()
{
//传入计算出的pid
pid参数转化 同时转换占空比

FTM_PWM_ChangeDuty(HW_FTM1, HW_FTM_CH0, PWM);
}





//*****************************速度滤波
int16_t Speed_Filter() 
{
 char value_buf[N]; 
   char count,i,j,temp; 
   for ( count=0;count<N_Speed_Filter;count++)           //N可调
   { 
      value_buf[count] = GetSpeed()；
      //delay();    此处需延时很短一段时间，具体后面调试的时候确定
   } 
   for (j=0;j<N-1;j++) 
   { 
      for (i=0;i<N-j;i++) 
      { 
         if ( value_buf[i]>value_buf[i+1] ) 
         { 
            temp = value_buf[i]; 
            value_buf[i] = value_buf[i+1];  
             value_buf[i+1] = temp; 
         } 
      } 
   } 
speed=value_buf[(N-1)/2];//排序之后输出中间值
return speed;   //可以用返回值或设speed为全局变量在其他函数中调用
}



//*************将ADC处理值和编码器滤波值传入control函数执行控制程序
void contol(location,speed)
{
	
	
}



//***********处理adc读取值（滤波、归一化、获得相对位置）
void adc_deal（）
{
	
}


//***********对ADC读取并进行滤波处理
void ADC_Filter()
{

}

//****************停车
void stop()
{
	GPIO_WriteBit(HW_GPIOx, x, 0);
	GPIO_WriteBit(HW_GPIOx, x, 0);//关闭电机和舵机使能
}
