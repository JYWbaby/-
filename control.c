//此函数用于根据4个传感器的值来控制电机和舵机

float value1,value2;

void contol(float s1,float s2,float s3,float s4)//输入变量为4个传感器接受值
{
	value1=s2-s3;//左1减右1
	value1=s1-s4;//左2减右2
	
	//根据value1、value2的值来调整motor和servo的pwm输出
	
}