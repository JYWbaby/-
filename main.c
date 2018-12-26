#include <headdfile.h>
//int value1; 
//uint8_t dir; /* 记录编码器旋转方向1 */

//*****************************/变量定义部分///*******************************
float d;  //角度(偏差值)
int PWM;  //舵机pwm
float error,lasterror,preverror,derror;
float kp,kd;//舵机控制PD
float kp_j,kp_c,kp_x;

extern int speed_afterfilter;//滤波后速度值

/////*****************************************////////////////////////////////
void oled_display(int speed_afterfilter ,int position)
{
	unsigned char temp1[100];     //速度数据
	unsigned char temp2[100];     //位置数据
//	unsigned char temp3[100];     //左adc数据
//	unsigned char temp4[100];     //右adc数据
	
	sprintf((char*)temp1,"speed: %d", speed_afterfilter );
  sprintf((char*)temp2,"position: %d",position);

	
	LCD_Print(0,0,temp1);
	LCD_Print(0,15,temp2);
	
	
}



void mac(void)           // 通用io口输入输出函数    
{

	GPIO_QuickInit(HW_GPIOB, 05, kGPIO_Mode_OPP);             //io口简单初始化
	GPIO_WriteBit(HW_GPIOB, 05, 1);                           //制定引脚配置高电平
                  
	//GPIO_QuickInit(HW_GPIOD, 9, kGPIO_Mode_OPP);              //io口简单初始化
	//GPIO_WriteBit(HW_GPIOD, 9, 0);                            //制定引脚配置高电平
	
}




int main(void)
{
    initx();  //初始化函数
	  mac();  // 给驱动的使能端
    



	
	
	while(1)
    {
			oled_display();
			//void LCD_Rectangle(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char color,unsigned char gif)
    printf("HelloWorld!!!\r\n"); 
        GPIO_ToggleBit(HW_GPIOE, 6);
        DelayMs(500);
    }
}














