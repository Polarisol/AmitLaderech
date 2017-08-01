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

#define  PANEL                            1       /* callback function: anotherExitFun */
#define  PANEL_MENTOR_PICTURE             2       /* control type: picture, callback function: (none) */
#define  PANEL_LOCAL_DATE                 3       /* control type: textMsg, callback function: (none) */
#define  PANEL_CITY                       4       /* control type: textMsg, callback function: (none) */
#define  PANEL_CELLPHONE                  5       /* control type: textMsg, callback function: (none) */
#define  PANEL_PHONE                      6       /* control type: textMsg, callback function: (none) */
#define  PANEL_MAIL                       7       /* control type: textMsg, callback function: (none) */
#define  PANEL_AMITIM                     8       /* control type: textMsg, callback function: (none) */
#define  PANEL_CONTACT_INFO               9       /* control type: textMsg, callback function: (none) */
#define  PANEL_ADDRESS                    10      /* control type: textMsg, callback function: (none) */
#define  PANEL_AGE                        11      /* control type: textMsg, callback function: (none) */
#define  PANEL_ID                         12      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_NAME                13      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_MAIL                14      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_PHONE               15      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_CELLPHONE           16      /* control type: textMsg, callback function: (none) */
#define  PANEL_AMIT3                      17      /* control type: textMsg, callback function: (none) */
#define  PANEL_AMIT2                      18      /* control type: textMsg, callback function: (none) */
#define  PANEL_AMIT1                      19      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_CITY                20      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_ADDRESS             21      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_AGE                 22      /* control type: textMsg, callback function: (none) */
#define  PANEL_MENTOR_ID                  23      /* control type: textMsg, callback function: (none) */
#define  PANEL_OK_BUTTON                  24      /* control type: command, callback function: creatPDF */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK anotherExitFun(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK creatPDF(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
