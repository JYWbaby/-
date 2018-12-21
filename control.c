//此函数用于根据4个传感器的值和编码器的数值来控制电机和舵机
/*分为3部分
	1.数据处理
	2.方向控制
	3.速度控制
*/

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
