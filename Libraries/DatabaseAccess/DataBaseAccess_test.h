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
#define  PANEL_TABLE                      2       /* control type: table, callback function: tblFunc */
#define  PANEL_NEWFIELD                   3       /* control type: command, callback function: btnField */
#define  PANEL_NEWRECORED                 4       /* control type: command, callback function: btnRecored */
#define  PANEL_RING                       5       /* control type: ring, callback function: ringFunc */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK btnField(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnRecored(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ringFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tblFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
