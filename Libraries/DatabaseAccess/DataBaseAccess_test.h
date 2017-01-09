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
#define  PANEL_MENTOR                     2       /* control type: command, callback function: btnMentor */
#define  PANEL_SHOWAMIT                   3       /* control type: command, callback function: btnAmit */
#define  PANEL_SEARCH                     4       /* control type: command, callback function: btnSearch */

#define  PANEL_2                          2       /* callback function: exitFunc */
#define  PANEL_2_TABLE                    2       /* control type: table, callback function: (none) */
#define  PANEL_2_SBFIELDVAL               3       /* control type: string, callback function: (none) */
#define  PANEL_2_SBFIELD                  4       /* control type: string, callback function: (none) */
#define  PANEL_2_SBYID                    5       /* control type: string, callback function: (none) */
#define  PANEL_2_BTNFIELD                 6       /* control type: command, callback function: searchBy */
#define  PANEL_2_BTNID                    7       /* control type: command, callback function: searchBy */

#define  PANEL_3                          3       /* callback function: exitFunc */
#define  PANEL_3_TABLE                    2       /* control type: table, callback function: tblFunc */
#define  PANEL_3_DEL                      3       /* control type: command, callback function: btnDelRecord */
#define  PANEL_3_ADD                      4       /* control type: command, callback function: btnNewRec */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK btnAmit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnDelRecord(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnMentor(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnNewRec(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK btnSearch(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK searchBy(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tblFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
