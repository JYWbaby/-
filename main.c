#include "pid.h"
#include "ftm.h"
#include "uart.h"
#include "shiboqi.h"
#include "pit.h"
#include "gpio.h"





float speed;
float sensor_1,sensor_2,sensor_3,sensor_4;//4·����������ֵ���ֱ�Ϊ��2����1����1����2


//�ж϶�ȡ����������
//���������Ƴ���
static void PIT_ISR(void)
{
	int value;
	uint8_t  direction;
	
	FTM_QD_GetData(HW_FTM1, &value, &direction);
	FTM_QD_ClearCount(HW_FTM1);
	speed=value;//(25*0.001);
	
  control(sensor_1,sensor_2,sensor_3,sensor_4);
	
	//oled��ʾ
}












int main(){
		
		Init();//��ʼ��

	
	
		
		
		
	
		while(1){
		 //�ɻɹܼ��ͣ����־
		 //�����⵽�յ㣬��stop����
			
			
			//adc_1��ȡ
			//adc_2��ȡ
			//adc_3��ȡ
			//adc_4��ȡ
			
			//���ݶ�ȡ����ֵ��ȷ���ٶȺͷ���
		}      
	}
