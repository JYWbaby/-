oled我放在主函数里面了  initx里面定义 while1 里面执行显示 我在主函数里面改了 这个函数可以删了


extern int speed_afterfilter;/

/////*****************************************////////////////////////////////
void oled_display(int speed_afterfilter ,int position)
{
	unsigned char temp1[100];     //ËÙ¶ÈÊý¾Ý
	unsigned char temp2[100];     //Î»ÖÃÊý¾Ý
//	unsigned char temp3[100];     
//	unsigned char temp4[100];     
	
	sprintf((char*)temp1,"speed: %d", speed_afterfilter );
  sprintf((char*)temp2,"position: %d",position);

	
	LCD_Print(0,0,temp1);
	LCD_Print(0,15,temp2);
	
	
}




























#include "LQ12864.h"


//************oled显示模块初始化
void oled_Init()
{
		PLL_Init(PLL180);            //初始化PLL为180M
		LCD_Init();			//调用龙邱的LCD_Init函数
}


/*  OLDE显示     暂时只显示speed 和 position  */
void oled_display(int speed,int position)
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
