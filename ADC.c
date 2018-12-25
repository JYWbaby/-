//***********处理adc读取值（滤波、归一化、获得相对位置）
void adc_deal()
{
	ADC_Filter();//得到4路adc滤波后的有效值
	
}


//***********对ADC读取并进行滤波处理
void ADC_Filter()
{
for(temp2=1;temp2<=4;temp2++)
{
	 char value_buf[N_ADC_Filter]; 
   	char count,i,j,temp; 
   	for ( count=0;count<N_ADC_Filter;count++)           //N可调
   	{ 
      	value_buf[count] = GetADC(temp2)；
      	//delay();    此处需延时很短一段时间，具体后面调试的时候确定
  	 } 
   	for (j=0;j<N_ADC_Filter-1;j++) 
  	 { 
     	 	for (i=0;i<N_ADC_Filter-j;i++) 
      		{ 
         		if ( value_buf[i]>value_buf[i+1] ) 
        	 	{ 
          	  		temp = value_buf[i]; 
			   	value_buf[i] = value_buf[i+1];  
         	    		value_buf[i+1] = temp; 
         		} 
       		 } 
  	 } 
	adc_afterfilter[temp2]=value_buf[(N_ADC_Filter-1)/2];//排序之后输出中间值
}

void GetADC(temp)
{	
	char channel[];
	int number;
	
	switch(temp)
	{	
		case 1:{channel="HW_ADC0";number=1;};break;  //0p1
		case 2:{channel="HW_ADC1";number=1;};break;  //1p1
		case 3:{channel="HW_ADC1";number=3;};break;  //1p3
		case 4:{channel="HW_ADC0";number=3;};break;  //0p3
	}
	
	    /* 启动一次ADC转换 */
    ADC_StartConversion(channel,number, kADC_MuxA);
    
    while(1)
    {
        /* 如果ADC转换完成 */
        if(ADC_IsConversionCompleted(channel, kADC_MuxA) == 0)
        {
            /* 读取ADC的值   */
            return ADC_ReadValue(channel, kADC_MuxA);
        }
       
    }
