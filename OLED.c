#include "LQ12864.h"


//************oled显示模块初始化
void oled_Init()
{
		PLL_Init(PLL180);            //初始化PLL为180M
		LCD_Init();			//调用龙邱的LCD_Init函数
}


//与OLED有关的其他函数