#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include <stdio.h>
#include "oled.h"
/************************************************    
 ALIENTEK��ӢSTM32������       
 ���ߣ�Ψ������      
 CSDN���ͣ�https://blog.csdn.net/tichimi3375      
 12864_SPI_OLED_STM32����
 OLED��ʾ����ģ�飺SSD1306
 ����SPI:SCL,SDA
 ��Ӧ�ӿڣ�PC2,PC1
************************************************/   
extern unsigned char hanzi1[];
int main(void)
{
  delay_init();		  	 //��ʱ��ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 
	OLED_Init();		    //��ʼ��OLED
  initial_olcd();		  //��ʼ��
	clear_screen();			//����
	while(1)
		{
				disp_string_8x16_16x16(1,1,"ת�ٸ���:");//��ʾ16x16�����ִ���8x16������ַ�����������Ĳ����ֱ�Ϊ��ҳ,��,�ַ���ָ�룩
				display_number_16x8(1,73,2900);
				display_graphic_32x32 (1,1+32*3,hanzi1); 					//��ʾ����32x32����ĺ��֣�������Ĳ����ֱ�Ϊ��PAGE,��,�ַ�ָ�룩
		} 
}
