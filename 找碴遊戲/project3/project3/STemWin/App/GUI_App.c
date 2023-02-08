  /**
  ******************************************************************************
  * @file    GUI_App.c
  * @author  MCD Application Team
  * @brief   Simple demo drawing "Hello world"  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright 蝛?2018 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#include "GUI_App.h"
#include "GUI.h"
#include "stm32746g_discovery_ts.h"
#include "DIALOG.h"
#include "string.h"
#include "stdio.h"
#include "stdbool.h"

#define ONESEC 1000

extern WM_HWIN CreateWindow(void); 
extern WM_HWIN CreateWindow2(void);
extern void delayTime();
extern WM_HWIN page[2], hItem;
extern TIM_HandleTypeDef htim7;
extern volatile int timerTick, timerTick2;
extern char time_str[5];
extern int second, minite, number, finish, gameStart;

WM_HWIN page[2];
char time_str[5] = "00:00";
int second = 0, minite = 0;	

void delayTime() {
		char str1[2], str2[2];
		bool flag = true;
	
		if(timerTick2 == ONESEC && flag == true) {
				second++;
				printf("second : %d",second);
				if(second == 60) minite++;
				
				if(second == 60 && minite == 60) {
						second = 0;
						minite = 0;
				}
				
				if(second == 60) second = 0;
				strcpy(time_str,"");
				if(minite < 10) strcat(time_str, "0");
				sprintf(str1,"%d",second);
				sprintf(str2,"%d",minite);
				strcat(time_str,str2);
				strcat(time_str,":");
				if(second < 10) strcat(time_str, "0");
				strcat(time_str,str1);
				flag = false;
		}else {
				flag = true;
		}		
}

void GRAPHICS_MainTask(void) {
	
  /* 1- Create a FrameWin using GUIBuilder */
	TS_StateTypeDef state_ts;
	GUI_PID_STATE state_pid;
	int touch, set = 0;
  page[0] = CreateWindow2();
	
/* USER CODE BEGIN GRAPHICS_MainTask */
  HAL_TIM_Base_Start_IT(&htim7);
	BSP_TS_Init(480, 272); 
	while(1) {
		
		if(gameStart == 1) {
				page[0] = CreateWindow();
				gameStart = 0;
				set = 1;
		}
		
		if(set && !finish) {
				delayTime();
				EDIT_SetText(hItem, time_str);
		}
		
		BSP_TS_GetState(&state_ts);
		state_pid.Layer = 0;
		
		if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11) || finish) {
				if(finish) HAL_Delay(5000);
				WM_DeleteWindow(page[0]);
				set = 0;
				second = 0;
				minite = 0;	
				strcpy(time_str,"00:00");
				number = 20;
				page[0] = CreateWindow2();
		}else if (state_ts.touchDetected == 1) {
				state_pid.Pressed = 1;
				state_pid.x = (int)(state_ts.touchX[0]);
				state_pid.y = (int)(state_ts.touchY[0]);
				GUI_PID_StoreState(&state_pid);
				touch = 1;				
		}else {
			
				if (touch == 1) {
						state_pid.Pressed = 0;
						GUI_PID_StoreState(&state_pid);
						touch = 0;
				}
				
		}
		
		GUI_Exec();
	}
					
	
/* USER CODE END GRAPHICS_MainTask */
  while(1)
{
      GUI_Delay(100);
}
}

/*************************** End of file ****************************/