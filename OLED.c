#include "LQ12864.h"


//************oled��ʾģ���ʼ��
void oled_Init()
{
		PLL_Init(PLL180);            //��ʼ��PLLΪ180M
		LCD_Init();			//���������LCD_Init����
}


//��OLED�йص���������