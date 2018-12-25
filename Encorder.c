#include <headdfile.h>
#define ENC_L_PIN FTM1_QD_PHA_PB00_PHB_PB01

void PIT_ISR(void);//定时器中断回调函数


void  encoder_init()
{
//（只有一个编码器）	FTM_QD_QuickInit(ENC_R_PIN, kFTM_QD_InvertedPolarity, kQD_CountDirectionEncoding);
  FTM_QD_QuickInit(ENC_L_PIN, kFTM_QD_NormalPolarity, kQD_CountDirectionEncoding);
	
	
	//	\
//	PIT_QuickInit(HW_PIT_CH1, 4000);//定时器配置1ms中断一次
//	/* 注册PIT 中断回调函数 */
//  PIT_CallbackInstall(HW_PIT_CH1, PIT1_CallBack); //0号定时器的中断处理
//    /* 开启PIT0定时器中断 */
//  PIT_ITDMAConfig(HW_PIT_CH1, kPIT_IT_TOF,true);
//	/* 初始化正交解码通道方向脉冲型PB0为方向PB1为脉冲*/       


//（只有一个编码器）	FTM_QD_ClearCount(HW_FTM1);
	FTM_QD_ClearCount(HW_FTM2);
	
}


void GetSpeed()
{
	int value;
	uint8_t  direction;
	
	FTM_QD_GetData(HW_FTM1, &value, &direction);
	FTM_QD_ClearCount(HW_FTM1);
	return value;
}

