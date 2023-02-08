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
#include "WM.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_sdram.h"
#include "stm32746g_discovery_ts.h"
#include "ft5336.h"
#include "DIALOG.h"
#include "stdbool.h"
#include "stdio.h"

#define WINDOW 0
#define PHOTO 1

extern  WM_HWIN CreateWindow(void);  
extern void getBmpFile(void);
extern void showPhoto(void);
extern int start;
extern int number;
extern  WM_HWIN page[2];
WM_HWIN page[2];

void GRAPHICS_MainTask(void) {
/* USER CODE BEGIN GRAPHICS_MainTask */
	TS_StateTypeDef state_ts;
	GUI_PID_STATE state_pid;
	int touch,time = 0;
	int state = 0;
	bool flag = true, release = true;
	
	page[0] = CreateWindow();
	GUI_Clear();
  	GUI_SetColor(GUI_WHITE);
  	GUI_SetFont(&GUI_Font32_1);  
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());  
	getBmpFile();
	
	while(1) {
			if(start) {
					state++;
					start = 0;
			}
		
			switch(state) {
					case WINDOW : 
							BSP_TS_GetState(&state_ts);
							state_pid.Layer = 0;
							if (state_ts.touchDetected == 1) {
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
					break;
					
					case PHOTO :
							while(time <= 20 * number) {
									BSP_TS_GetState(&state_ts);
									if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11)) {
											HAL_Delay(100);
											state++;
											goto SKIP;
									}else if(state_ts.touchDetected == 1) {
											flag = (release) ? !flag : flag;
											release = false;
									}else {
											HAL_Delay(40);
											time = (!flag)? time : time + 1;
											release = true;
									}
							}
							time = 0;
							showPhoto();
							SKIP:
					break;
					
					default:
							time = 0;
							state = 0;
							number = 5;
							flag = true;
							release = true;
							GUI_Clear();
							page[0] = CreateWindow();	
					break;
			}
					
			GUI_Exec();
	}
/* USER CODE END GRAPHICS_MainTask */
}

/*************************** End of file ****************************/
