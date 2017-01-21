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
#define  PANEL_NUMERIC_3                  2       /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_2                  3       /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_1                  4       /* control type: numeric, callback function: (none) */
#define  PANEL_COMMANDBUTTON_3            5       /* control type: command, callback function: find_new_records */
#define  PANEL_COMMANDBUTTON              6       /* control type: command, callback function: find_num_records */
#define  PANEL_COMMANDBUTTON_2            7       /* control type: command, callback function: add */
#define  PANEL_DECORATION_3               8       /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_2               9       /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION                 10      /* control type: deco, callback function: (none) */
#define  PANEL_TEXTMSG_3                  11      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG                    12      /* control type: textMsg, callback function: (none) */
#define  PANEL_STRING_3                   13      /* control type: string, callback function: (none) */
#define  PANEL_TEXTMSG_2                  14      /* control type: textMsg, callback function: (none) */
#define  PANEL_STRING_2                   15      /* control type: string, callback function: (none) */
#define  PANEL_STRING_1                   16      /* control type: string, callback function: (none) */
#define  PANEL_COMMANDBUTTON_4            17      /* control type: command, callback function: test */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK add(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK find_new_records(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK find_num_records(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK test(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
