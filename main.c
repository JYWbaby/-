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
	 
   


	
	while(1){
    scan_reed();//干簧管检测停车标志
		 //如果检测到终点，则stop（）
	}
}













































int main(){
		
		Init();//初始化

	
	
		
		
		
	
		while(1){
		 scan_reed();//干簧管检测停车标志
		 //如果检测到终点，则stop（）
			
			
		
		}      
	}
