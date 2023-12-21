#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "NRF24L01.h"
/***************************************************************
����ΪNRF24L01�������ݵ�ģ��

NRF24L01_Get_Value_Flag()����0ʱ������NRF24L01���յ������ݣ���ʱ����
NRF24L01_GetRxBuf�������õ���ֵ������Buf���������

���յ������ݸ�ʽ����

[��һλ���ڶ�λ������λ������λ.....������ʮ��λ]

���У���һλҲ����Buf[0]λ���յ������ݳ���
�ڶ�λ������ʮ��λһ��32���ֽڵ�����λ���ܵ������ݣ�


********************By:����ͨͨOrdinary*************************/


int main(void)
{
	
	uint8_t Buf[32] = {0};
 
	OLED_Init();
	NRF24L01_Init();
	OLED_ShowString(1, 1, "Len:");
	
	while (1)
	{
		if (NRF24L01_Get_Value_Flag() == 0)
		{
			NRF24L01_GetRxBuf(Buf);
		}
		
		OLED_ShowHexNum(1, 5, Buf[0], 2);
		OLED_ShowHexNum(2, 1, Buf[1], 2);
		OLED_ShowHexNum(2, 4, Buf[2], 2);
		OLED_ShowHexNum(3, 1, Buf[3], 2);
		OLED_ShowHexNum(3, 4, Buf[4], 2);
		OLED_ShowHexNum(4, 1, Buf[5], 2);
		OLED_ShowHexNum(4, 4, Buf[6], 2);
	
		
	}
}
