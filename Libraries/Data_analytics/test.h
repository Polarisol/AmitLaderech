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

#define  USERINT                          1       /* callback function: globalfunc */
#define  USERINT_PICTURE                  2       /* control type: picture, callback function: (none) */
#define  USERINT_PICTURE_6                3       /* control type: picture, callback function: (none) */
#define  USERINT_PICTURE_2                4       /* control type: picture, callback function: (none) */
#define  USERINT_PICTURE_3                5       /* control type: picture, callback function: (none) */
#define  USERINT_PICTURE_5                6       /* control type: picture, callback function: (none) */
#define  USERINT_PICTURE_4                7       /* control type: picture, callback function: (none) */
#define  USERINT_SPLITTER                 8       /* control type: splitter, callback function: (none) */
#define  USERINT_BUTTON                   9       /* control type: command, callback function: button */
#define  USERINT_TEXT1                    10      /* control type: textMsg, callback function: (none) */
#define  USERINT_TEXTMSG_2                11      /* control type: textMsg, callback function: (none) */
#define  USERINT_RING                     12      /* control type: ring, callback function: (none) */
#define  USERINT_CHOOSE_ROW               13      /* control type: numeric, callback function: (none) */
#define  USERINT_FIELD_RING3              14      /* control type: ring, callback function: (none) */
#define  USERINT_FIELD_RING2              15      /* control type: ring, callback function: (none) */
#define  USERINT_FIELD_RING1              16      /* control type: ring, callback function: (none) */
#define  USERINT_TABLE                    17      /* control type: table, callback function: (none) */
#define  USERINT_TEXTMSG                  18      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK button(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK globalfunc(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
