#include "pid.h"
#include "ftm.h"
#include "uart.h"
#include "shiboqi.h"
#include "pit.h"
#include "gpio.h"





float speed;
float sensor_1,sensor_2,sensor_3,sensor_4;//4路传感器反馈值，分别为左2，左1，右1，右2


//中断读取编码器脉冲
//反馈给控制程序
static void PIT_ISR(void)
{
	int value;
	uint8_t  direction;
	
	FTM_QD_GetData(HW_FTM1, &value, &direction);
	FTM_QD_ClearCount(HW_FTM1);
	speed=value;//(25*0.001);
	
  control(sensor_1,sensor_2,sensor_3,sensor_4，speed);
	
	//oled显示
}












int main(){
		
		Init();//初始化

	
	
		
		
		
	
		while(1){
		 //干簧管检测停车标志
		 //如果检测到终点，则stop（）
			
			
			//adc_1读取
			//adc_2读取
			//adc_3读取
			//adc_4读取
			
			//根据读取到的值来确定速度和方向
		}      
	}
