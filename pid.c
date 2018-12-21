/*pid�㷨��������*/


#include "pid.h"
#include "ftm.h"
#include "uart.h"
#include "shiboqi.h"

Motor Pid;

int16_t Reslut=0;
int Set_Speed;

/************��ʼ������*************/
void Pid_All_Init(void)
{
		Pid.Kp = 15;              //���PID ����   30
	  Pid.Ki = 33;// 50
	  Pid.Kd = 0.20;//   .45

	
		Pid.Err = 0.0 ;
		Pid.Last_Err = 0.0 ;
		Pid.Last_Last_Err = 0.0 ;
		Pid.Set_Value = 0 ;
	  Pid.Actual_Value = 0 ;
		Pid.Result = 0.0 ;

}


/*****************����ջ�����*****************/
void Motor_Control(int16_t Speed_Goal ,int16_t Actual_Speed)              //����ʽPID   Ŀ���ٶ�,ʵ���ٶ�
{

		Pid.Set_Value = Speed_Goal;                      //����PID���� 
		Pid.Actual_Value = Actual_Speed; 
	  Pid.Err = Pid.Set_Value - Pid.Actual_Value ;
	
		if(Pid.Err>-3&&Pid.Err<3)                    //ȥ��PID����
			 Pid.Result=Pid.Result;
		else
		Pid.Result += Pid.Kp * (Pid.Err-Pid.Last_Err)  + Pid.Ki * Pid.Err + Pid.Kd * (Pid.Err -2*Pid.Last_Err+Pid.Last_Last_Err);
		
		Pid.Last_Last_Err = Pid.Last_Err;
		Pid.Last_Err = Pid.Err;
		Reslut=Pid.Result;
		
			if(Pid.Result>=8000)                     //����޷�
				Reslut=8000;
		Set_Speed=Pid.Set_Value;
		if(Reslut>=0)
		{
			FTM_PWM_ChangeDuty(HW_FTM0, HW_FTM_CH7, Reslut);                       //pid�ջ�
		}
		else
		{
			FTM_PWM_ChangeDuty(HW_FTM0, HW_FTM_CH7, -Reslut);
		}

}







