#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include <stdio.h>
#include "oled.h"
/************************************************    
 ALIENTEK精英STM32开发板       
 作者：唯恋殊雨      
 CSDN博客：https://blog.csdn.net/tichimi3375      
 12864_SPI_OLED_STM32驱动
 OLED显示驱动模块：SSD1306
 四线SPI:SCL,SDA
 对应接口：PC2,PC1
************************************************/   
extern unsigned char hanzi1[];
int main(void)
{
  delay_init();		  	 //延时初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 
	OLED_Init();		    //初始化OLED
  initial_olcd();		  //初始化
	clear_screen();			//清屏
	while(1)
		{
				disp_string_8x16_16x16(1,1,"转速给定:");//显示16x16点阵汉字串或8x16点阵的字符串，括号里的参数分别为（页,列,字符串指针）
				display_number_16x8(1,73,2900);
				display_graphic_32x32 (1,1+32*3,hanzi1); 					//显示单个32x32点阵的汉字，括号里的参数分别为（PAGE,列,字符指针）
		} 
}
