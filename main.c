#include <headdfile.h>
//int value1; 
//uint8_t dir; /* 记录编码器旋转方向1 */
   



void mac(void)           // 通用io口输入输出函数
{

	GPIO_QuickInit(HW_GPIOD, 11, kGPIO_Mode_OPP);             //io口简单初始化
	GPIO_WriteBit(HW_GPIOD, 11, 1);                           //制定引脚配置高电平
                  
	GPIO_QuickInit(HW_GPIOD, 9, kGPIO_Mode_OPP);              //io口简单初始化
	GPIO_WriteBit(HW_GPIOD, 9, 0);                            //制定引脚配置高电平
	
}




int main(void)
{
    initx();  //初始化函数
	  mac();  // 通用io口输入输出函数 调pid给的是驱动的一个/这里可以不用
	 
   


	
	while(1)
    {
    printf("HelloWorld!!!\r\n"); 
        GPIO_ToggleBit(HW_GPIOE, 6);
        DelayMs(500);
    }
}

































#include "pid.h"
#include "ftm.h"
#include "uart.h"
#include "shiboqi.h"
#include "pit.h"
#include "gpio.h"

#define OFF 0
#define SET 1




float speed;
float sensor_1,sensor_2,sensor_3,sensor_4;//4路传感器反馈值，分别为左2，左1，右1，右2

/*
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
*/











int main(){
		
		Init();//初始化

	
	
		
		
		
	
		while(1){
		 scan_reed();//干簧管检测停车标志
		 //如果检测到终点，则stop（）
			
			
		scan_sensor();	//adc_1、adc_2、adc_3读取、adc_4读取
			
			//根据读取到的值来确定速度和方向
		}      
	}
