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

#define  PANEL                            1       /* callback function: Exit_Func */
#define  PANEL_STRING                     2       /* control type: string, callback function: (none) */
#define  PANEL_STRING_2                   3       /* control type: string, callback function: (none) */
#define  PANEL_COMMANDBUTTON_3            4       /* control type: command, callback function: (none) */
#define  PANEL_COMMANDBUTTON_2            5       /* control type: command, callback function: (none) */
#define  PANEL_COMMANDBUTTON              6       /* control type: command, callback function: (none) */
#define  PANEL_TEXTBOX_2                  7       /* control type: textBox, callback function: (none) */
#define  PANEL_TEXTBOX                    8       /* control type: textBox, callback function: (none) */
#define  PANEL_PICTURE                    9       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Exit_Func(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
