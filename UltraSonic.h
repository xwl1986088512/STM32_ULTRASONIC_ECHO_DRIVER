#ifndef _UltraSonic_H
#define _UltraSonic_H
#include"sys.h"

//------------------------------------------------------这里是天坑专区=.=------------------------------------------------------

#define ULTRA_PORT			GPIOB
#define ULTRA_CLK     			RCC_APB2Periph_GPIOB
#define ULTRA_TRIG			GPIO_Pin_10
#define ULTRA_ECHO			GPIO_Pin_11

/*四个脚都要填坑=.=好讨厌的说*/

#define TRIG_Send   PBout(5)
#define ECHO_Reci  PBin(6)

//--------------------------------------------------------------------------------------------------------------------------------
void UltraSonic_Init(void);
void UltraSonic_Ranging(float *p);

#endif