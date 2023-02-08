/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
#include <stdio.h>
#include <stdbool.h>
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_0  (GUI_ID_USER + 0x01)
#define ID_BUTTON_1  (GUI_ID_USER + 0x02)
#define ID_BUTTON_2  (GUI_ID_USER + 0x03)
#define ID_BUTTON_3  (GUI_ID_USER + 0x04)
#define ID_BUTTON_4  (GUI_ID_USER + 0x05)
#define ID_BUTTON_5  (GUI_ID_USER + 0x06)
#define ID_BUTTON_6  (GUI_ID_USER + 0x07)
#define ID_BUTTON_7  (GUI_ID_USER + 0x08)
#define ID_BUTTON_8  (GUI_ID_USER + 0x09)
#define ID_BUTTON_9  (GUI_ID_USER + 0x0A)
#define ID_BUTTON_10  (GUI_ID_USER + 0x0B)
#define ID_BUTTON_11  (GUI_ID_USER + 0x0C)
#define ID_EDIT_0  (GUI_ID_USER + 0x0D)
#define ID_TEXT_0  (GUI_ID_USER + 0x0E)


// USER START (Optionally insert additional defines)
extern  WM_HWIN page[2];
extern void showPhoto(void);
extern int number;
extern int start;
bool init = true;
int number = 5;
int start = 0;
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
int insert(int key) {
		if(init) number = 0;
		number = (number * 10 + key) % 100;	
		init = false;
		return number;
}
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "1", ID_BUTTON_0, 34, 52, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "2", ID_BUTTON_1, 125, 54, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "3", ID_BUTTON_2, 218, 52, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "0", ID_BUTTON_3, 309, 55, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "4", ID_BUTTON_4, 35, 84, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "6", ID_BUTTON_5, 128, 84, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "6", ID_BUTTON_6, 221, 83, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "C", ID_BUTTON_7, 311, 85, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "7", ID_BUTTON_8, 37, 116, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "8", ID_BUTTON_9, 136, 116, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "9", ID_BUTTON_10, 229, 117, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "E", ID_BUTTON_11, 321, 117, 80, 20, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_0, 74, 9, 264, 34, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 173, 203, 80, 20, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)

// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
	char show[5];
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of '1'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "1");
    //
    // Initialization of '2'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetFont(hItem, GUI_FONT_13_1);
    BUTTON_SetText(hItem, "2");
    //
    // Initialization of '3'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetText(hItem, "3");
    //
    // Initialization of '0'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
    BUTTON_SetText(hItem, "0");
    //
    // Initialization of '4'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
    BUTTON_SetText(hItem, "4");
    //
    // Initialization of '6'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
    BUTTON_SetText(hItem, "5");
    //
    // Initialization of '6'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
    BUTTON_SetText(hItem, "6");
    //
    // Initialization of 'C'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
    BUTTON_SetText(hItem, "C");
    //
    // Initialization of '7'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
    BUTTON_SetText(hItem, "7");
    //
    // Initialization of '8'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
    BUTTON_SetText(hItem, "8");
    //
    // Initialization of '9'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10);
    BUTTON_SetText(hItem, "9");
    //
    // Initialization of 'E'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11);
    BUTTON_SetText(hItem, "E");
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetText(hItem, "5");
    EDIT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
    EDIT_SetFont(hItem, GUI_FONT_16B_1);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, GUI_MAKE_COLOR(0x00408000));
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "NTUST");
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0xFF0000));
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by '1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
				sprintf(show, "%d", insert(1));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by '2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
				sprintf(show, "%d", insert(2));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by '3'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        sprintf(show, "%d", insert(3));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by '0'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        sprintf(show, "%d", insert(0));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_4: // Notifications sent by '4'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        sprintf(show, "%d", insert(4));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_5: // Notifications sent by '6'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        sprintf(show, "%d", insert(5));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_6: // Notifications sent by '6'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        sprintf(show, "%d", insert(6));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_7: // Notifications sent by 'C'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        number = 0;
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, "");
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_8: // Notifications sent by '7'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
				sprintf(show, "%d", insert(7));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_9: // Notifications sent by '8'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        sprintf(show, "%d", insert(8));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_10: // Notifications sent by '9'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        sprintf(show, "%d", insert(9));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				EDIT_SetText(hItem, show);
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_11: // Notifications sent by 'E'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        if(number != 0) {
						init = true;
						start = 1;
						WM_DeleteWindow(page[0]);
						showPhoto();
				} 
				// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_0: // Notifications sent by 'Edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
