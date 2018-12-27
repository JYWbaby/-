

#include <headdfile.h>


//************oled显示模块初始化
void oled_Init()
{
		PLL_Init(PLL180);            //初始化PLL为180M
		LCD_Init();			//调用龙邱的LCD_Init函数
}


/*  OLDE显示     暂时只显示speed 和 position  */
void oled_display(int speed_afterfilter,int position)
{
	 char temp1[100];  //存放速度显示项
	 char temp2[100];  //存放位置显示项  
   		//还可以再增加其他项，但是只有一行位置了

	
	sprintf(temp1,"speed: %d",speed_afterfilter);
  
	sprintf(temp2,"position: %d",position);

	
	LCD_Print(0,0,temp1);
	LCD_Print(0,2,temp2);
	
}
	



