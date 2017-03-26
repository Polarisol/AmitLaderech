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

#define  PANEL                            1       /* callback function: demo */
#define  PANEL_PATH                       2       /* control type: string, callback function: (none) */
#define  PANEL_MENTORS                    3       /* control type: ring, callback function: (none) */
#define  PANEL_EXTRACT_DATA               4       /* control type: ring, callback function: extract */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK demo(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK extract(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
