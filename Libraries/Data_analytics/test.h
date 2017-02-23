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

#define  MAIN_PANEL                       1       /* callback function: main_func */
#define  MAIN_PANEL_PICTURE               2       /* control type: picture, callback function: (none) */
#define  MAIN_PANEL_PICTURE_6             3       /* control type: picture, callback function: (none) */
#define  MAIN_PANEL_PICTURE_2             4       /* control type: picture, callback function: (none) */
#define  MAIN_PANEL_PICTURE_3             5       /* control type: picture, callback function: (none) */
#define  MAIN_PANEL_PICTURE_5             6       /* control type: picture, callback function: (none) */
#define  MAIN_PANEL_PICTURE_4             7       /* control type: picture, callback function: (none) */
#define  MAIN_PANEL_SPLITTER              8       /* control type: splitter, callback function: (none) */
#define  MAIN_PANEL_COMMANDBUTTON         9       /* control type: command, callback function: (none) */
#define  MAIN_PANEL_COMMANDBUTTON_2       10      /* control type: command, callback function: (none) */
#define  MAIN_PANEL_CSV_TABLE             11      /* control type: table, callback function: (none) */
#define  MAIN_PANEL_LOAD                  12      /* control type: command, callback function: load_csv */
#define  MAIN_PANEL_RING                  13      /* control type: ring, callback function: (none) */
#define  MAIN_PANEL_CSV_PATH              14      /* control type: string, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK load_csv(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK main_func(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
