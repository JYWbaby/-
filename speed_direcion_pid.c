//此函数用于根据4个传感器的值和编码器的数值来控制电机和舵机
/*分为3部分
	1.数据处理
	2.方向控制
	3.
	
int Value1=0;//编码器读数定义
//****************************编码器获取数值
void GetSpeed()
{//计数
 //清零
 

}




//****************************电机和舵机pid参数初始化
void startpid_Init(void)
{
//电机
//舵机
}



//*****************************舵机控制
void Duoji_control(void) 
{
//pid参数转化 同时转换占空比

FTM_PWM_ChangeDuty(HW_FTM1, HW_FTM_CH0, PWM);
}



//*****************************电机控制
void Motor_Control()
{
//pid参数转化 同时转换占空比

FTM_PWM_ChangeDuty(HW_FTM1, HW_FTM_CH0, PWM);
}





//*****************************速度滤波
int16_t Speed_Filter(int16_t v) 
{
//排序之后输出中间值
}




































float value1,value2;

void contol(float s1,float s2,float s3,float s4，speed)//输入变量为4个传感器接受值
{
	value1=s2-s3;//左1减右1
	value1=s1-s4;//左2减右2
	
	//根据value1、value2的值来调整motor和servo的pwm输出（pid算法）
	
}


void stop()
{
	GPIO_WriteBit(HW_GPIOx, x, 0);
	GPIO_WriteBit(HW_GPIOx, x, 0);//关闭电机和舵机使能
}
