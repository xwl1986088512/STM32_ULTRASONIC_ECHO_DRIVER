#ifndef _UltraSonic_H
#define _UltraSonic_H
#include"sys.h"

//------------------------------------------------------���������ר��=.=------------------------------------------------------

#define ULTRA_PORT			GPIOB
#define ULTRA_CLK     			RCC_APB2Periph_GPIOB
#define ULTRA_TRIG			GPIO_Pin_10
#define ULTRA_ECHO			GPIO_Pin_11

/*�ĸ��Ŷ�Ҫ���=.=�������˵*/

#define TRIG_Send   PBout(5)
#define ECHO_Reci  PBin(6)

//--------------------------------------------------------------------------------------------------------------------------------
void UltraSonic_Init(void);
void UltraSonic_Ranging(float *p);

#endif