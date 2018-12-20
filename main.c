#include "gpio.h"
#include "common.h"
#include "uart.h"
#include "ftm.h"
#include "pit.h"
#include "cpuidy.h"
#include "uart.h"
#include "adc.h"


void Intx(void)
{
	  DelayInit();    //ÑÓÊ±³õÊ¼»¯
    UART_QuickInit(UART0_RX_PD06_TX_PD07, 115200);              //´®¿Ú³õÊ¼»¯                  /* ³õÊ¼»¯Ò»¸ö´®¿Ú Ê¹ÓÃUART0¶Ë¿ÚµÄPTD6Òý½ÅºÍPTD7Òý½Å×÷Îª½ÓÊÕºÍ·¢ËÍ£¬Ä¬ÈÏÉèÖÃ baud 115200 */
	  ADC_QuickInit(ADC0_SE20_DM1, kADC_SingleDiff12or13);       //adc³õÊ¼»¯  £¨Ò»Â·£©   	ADC0 Í¨µÀ20 Òý½ÅDM1 µ¥¶Ë ¾«¶È 12Î»
	  FTM_PWM_QuickInit(FTM0_CH3_PA06, kPWM_EdgeAligned, 1000);  //FTM0  Í¨µÀ3 PTA6   1000HZ   pwm,Ä¬ÈÏ  50%Õ¼¿Õ±È)
	
	  FTM_QD_QuickInit(FTM1_QD_PHA_PA08_PHB_PA09, kFTM_QD_NormalPolarity, kQD_CountDirectionEncoding);  //Õý½»½âÂë³õÊ¼»¯  
	
}




void mac(void)           // Í¨ÓÃio¿ÚÊäÈëÊä³öº¯Êý
{

	GPIO_QuickInit(HW_GPIOD, 11, kGPIO_Mode_OPP);             //io¿Ú¼òµ¥³õÊ¼»¯
	GPIO_WriteBit(HW_GPIOD, 11, 1);                           //ÖÆ¶¨Òý½ÅÅäÖÃ¸ßµçÆ½
	
	                   
	GPIO_QuickInit(HW_GPIOD, 9, kGPIO_Mode_OPP);              //io¿Ú¼òµ¥³õÊ¼»¯
	GPIO_WriteBit(HW_GPIOD, 9, 0);                            //ÖÆ¶¨Òý½ÅÅäÖÃ¸ßµçÆ½
	
}




int main(void)
{
    Intx();  //³õÊ¼»¯º¯Êý
	  mac();  // Í¨ÓÃio¿ÚÊäÈëÊä³öº¯Êý
	
	 
   


	
	while(1)
    {
    printf("HelloWorld!!!\r\n"); 
        GPIO_ToggleBit(HW_GPIOE, 6);
        DelayMs(500);
    }
}

