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

#define  PANEL                            1       /* callback function: main_func */
#define  PANEL_CHECK                      2       /* control type: command, callback function: check_req */
#define  PANEL_TEXTMSG                    3       /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_2                  4       /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_3                  5       /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_4                  6       /* control type: textMsg, callback function: (none) */
#define  PANEL_OUTPUT                     7       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK check_req(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK main_func(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
