#ifndef _PIN_MAP_H
#define _PIN_MAP_H

#include "headdfile.h"

/*三轴角速度传感器管脚定义*/
#define gyro_x_pin   ADC0_SE9_PB1    //ADC0_SE12_PB2 //陀螺仪角速度传感器x
#define gyro_y_pin   ADC0_SE13_PB3         
#define gyro_z_pin   ADC0_SE18_E25 

/*三轴角加速度传感器管脚定义*/
#define MMA_x_pin    ADC0_SE17_E24    // ADC0_SE8_PB0//加速度计传感器 X
#define MMA_y_pin    ADC0_SE12_PB2  
#define MMA_z_pin    ADC0_SE8_PB0  

 /*电机编码器管脚定义*/
#define ENC_L_PIN      FTM2_QD_PHA_PB18_PHB_PB19           //FTM2_QD_PHA_PA10_PHB_PA11//左电机编码器
#define ENC_R_PIN      FTM1_QD_PHA_PA12_PHB_PA13          // FTM1_QD_PHA_PA08_PHB_PA09 

 /************OLED引脚定义***************
 PD8- >D0(SCL)                 PD10->CS
 PD9->D1 (SDA)                PD4->DC
                    PD5->RST
 *********************************************/
 
 /*电机管脚定义*/
#define MOTOR_L_Z     FTM1_CH1_PA13     //FTM0_CH3_PA06
#define MOTOR_L_F     FTM1_CH0_PA12
#define MOTOR_R_Z     FTM2_CH0_PB18        // FTM0_CH4_PD04
#define MOTOR_R_F     FTM2_CH1_PB19       //  FTM0_CH5_PD05
 
 /*电机PWM输出通道定义*/
#define MOTOR_LZ_PUL     HW_FTM_CH1
#define MOTOR_LF_PUL     HW_FTM_CH0
#define MOTOR_RZ_PUL     HW_FTM_CH0
#define MOTOR_RF_PUL     HW_FTM_CH1
 
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
