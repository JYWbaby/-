#include <headdfile.h>

/*舵机PID部分参数_______________________*/
extern float d;  //角度(偏差值)
extern int PWM;  //舵机pwm
extern float error,lasterror,preverror,derror;
extern float kp,kd;//舵机控制PD
extern float kp_j,kp_c,kp_x;
    




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









//*************将ADC处理值和编码器滤波值传入control函数执行控制程序
void contol(speed,location)
{
	
	
}





//****************停车
void stop()
{
	GPIO_WriteBit(HW_GPIOx, x, 0);
	GPIO_WriteBit(HW_GPIOx, x, 0);//关闭电机和舵机使能
}
