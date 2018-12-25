#ifndef _PIN_MAP_H
#define _PIN_MAP_H

#include "headdfile.h"




 /*电机编码器管脚定义*/
#define ENC_L_PIN      FTM2_QD_PHA_PB18_PHB_PB19           //FTM2_QD_PHA_PA10_PHB_PA11//左电机编码器

 /************OLED引脚定义***************
 PD8- >D0(SCL)                 PD10->CS
 PD9->D1 (SDA)                PD4->DC
                    PD5->RST
 *********************************************/
 
 /*电机管脚定义*/
#define MOTOR_L_Z     FTM1_CH1_PA13     //FTM0_CH3_PA06
#define MOTOR_L_F     FTM1_CH0_PA12

//电机驱动使能

 
 /*电机PWM输出通道定义*/
#define PWM3   HW_FTM_CH0
#define PWM4    HW_FTM_CH0
 
/********电磁传感器引脚*******/
#define Elec_D  ADC1_SE6_PE2    
#define Elec_A  ADC1_SE14_PB10  // zuo
#define Elec_C  ADC1_SE7_PE3    // you 
#define Elec_B  ADC1_SE15_PB11    // zhong//左边第一个

/* 红外引脚定义PTE28 */
#define IR_PORT  HW_GPIOC
#define IR_PIN     (8)
#define IR_DATA  PCin(IR_PIN) 

#endif
