/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelFunc */
#define  PANEL_MENTOR_BUTTON_4            2       /* control type: command, callback function: mentor_4_Func */
#define  PANEL_MENTOR_BUTTON_3            3       /* control type: command, callback function: mentor_3_Func */
#define  PANEL_MENTOR_BUTTON_2            4       /* control type: command, callback function: mentor_2_Func */
#define  PANEL_MENTOR_BUTTON_1            5       /* control type: command, callback function: mentor_1_Func */
#define  PANEL_PICTUREBUTTON              6       /* control type: pictButton, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK mentor_1_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK mentor_2_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK mentor_3_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK mentor_4_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
