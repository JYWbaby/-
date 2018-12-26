#include "LQ12864.h"


//************oled显示模块初始化
void oled_Init()
{
		PLL_Init(PLL180);            //初始化PLL为180M
		LCD_Init();			//调用龙邱的LCD_Init函数
}


/*  OLDE显示     暂时只显示speed 和 position  */
void olde_display(int speed,int position)
{
	char temp1[100];     //存放速度数据
	char temp2[100];     //存放位置数据
	char temp3[100];     //存放左两路adc相对值
	char temp4[100];     //存放右两路adc相对值
	
	sprintf(temp1,"speed: %d",speed);
	sprintf(temp2,"position: %d",position);
	//sprintf(temp3,"L1:
	
	LCD_Print(0,0,temp1);
	LCD_Print(0,15,temp2);
	
}
	


//与OLED有关的其他函数
