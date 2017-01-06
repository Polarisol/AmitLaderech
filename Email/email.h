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

#define  PANEL                            1       /* callback function: exitFunc */
#define  PANEL_SUBJECT                    2       /* control type: string, callback function: subjectFunc */
#define  PANEL_TEXT                       3       /* control type: textBox, callback function: (none) */
#define  PANEL_TO                         4       /* control type: string, callback function: toaddressFunc */
#define  PANEL_ADDRESSBOX                 5       /* control type: command, callback function: (none) */
#define  PANEL_SENDBOTTON                 6       /* control type: pictButton, callback function: sendmessageFunc */
#define  PANEL_PICTURE                    7       /* control type: picture, callback function: (none) */

#define  PANEL_2                          2       /* callback function: justrandomexitFunc */
#define  PANEL_2_PASSWORD                 2       /* control type: string, callback function: (none) */
#define  PANEL_2_MAIL                     3       /* control type: string, callback function: (none) */
#define  PANEL_2_USER                     4       /* control type: string, callback function: (none) */
#define  PANEL_2_OKBOTTON                 5       /* control type: command, callback function: okFunc */
#define  PANEL_2_PICTURE                  6       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK justrandomexitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK okFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK sendmessageFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK subjectFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK toaddressFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
