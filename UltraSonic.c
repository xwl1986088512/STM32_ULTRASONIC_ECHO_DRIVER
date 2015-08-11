#include "stm32f10x.h"
#include "UltraSonic.h"
#include"delay.h"

/********************************************************************************************************************************************
�ɿص��ֵܣ�������Ҫ���ҵ�Դ�룡��������������Ҫ���Լ�ȥ����ĺ�������Ҫ˦�ҹ���������������
FunctionUsage:void UltraSonic_Init(void);
Author:RenNever
��ʼ��
*********************************************************************************************************************************************/
void UltraSonic_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(ULTRA_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin =ULTRA_TRIG;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(ULTRA_PORT,ULTRA_TRIG);

	GPIO_InitStructure.GPIO_Pin =ULTRA_ECHO;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);	
}
/********************************************************************************************************************************************
FunctionUsage: void UltraSonic_Ranging(float *p);
���ֵ��������*p���棬��ȡʱ��Ҫ�Ķ�ָ��Thx
��������࣬10��ȡ��ֵ
*********************************************************************************************************************************************/
void UltraSonic_Ranging(float *p)
{
	u8 i;
	u32 j;
	float Ultr_Temp;
	for(i=0;i<10;i++)
	{
		TRIG_Send=1;
		delay_ms(10);
		TRIG_Send=0;
		while(!ECHO_Reci);
		while(ECHO_Reci)
		{
			delay_us(10);
			j++;
		}
		Ultr_Temp+=340/2*j*10;
		j=0;
		delay_ms(60);
	}
	*p=Ultr_Temp/10/1000000;
}
