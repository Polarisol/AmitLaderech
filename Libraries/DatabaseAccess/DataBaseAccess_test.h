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
#define  PANEL_AMOUNT                     2       /* control type: command, callback function: btnAmout */
#define  PANEL_MENTOR                     3       /* control type: command, callback function: btnMentor */
#define  PANEL_SHOWAMIT                   4       /* control type: command, callback function: btnAmit */
#define  PANEL_SEARCH                     5       /* control type: command, callback function: btnSearch */

#define  PANEL_2                          2       /* callback function: exitFunc */
#define  PANEL_2_TABLE                    2       /* control type: table, callback function: tblFuncSearch */

#define  PANEL_3                          3       /* callback function: exitFunc */
#define  PANEL_3_TABLE                    2       /* control type: table, callback function: tblFunc */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK btnAmit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnAmout(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnMentor(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnSearch(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tblFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tblFuncSearch(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
