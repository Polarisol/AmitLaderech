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

#define  PANEL_INFO                       1       /* callback function: myexitFunc */
#define  PANEL_INFO_AMIT_PICTURE          2       /* control type: picture, callback function: (none) */
#define  PANEL_INFO_LOCAL_DATE            3       /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_JOB                   4       /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_LEGAL_STATUS          5       /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_LIVING_STATUS         6       /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_CITY                  7       /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_CELLPHONE             8       /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_PHONE                 9       /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_MAIL                  10      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_MENTOR                11      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_PERIOD                12      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_EDUCATION             13      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_CONTACT_INFO          14      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_ECONOMY               15      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_GENDER                16      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_ADDRESS               17      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_BIRTH_DATE            18      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AGE                   19      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_ID                    20      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_LAST_NAME        21      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_FIRST_NAME       22      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_MAIL             23      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_PHONE            24      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_CELLPHONE        25      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_MENTOR           26      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_PERIOD           27      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_EDUCATION        28      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_ECONOMY          29      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_JOB              30      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_LEGAL_STATUS     31      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_LIVING_STATUS    32      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_CITY             33      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_ADDRESS          34      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_BIRTH_DATE       35      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_AGE              36      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_ID               37      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_AMIT_GENDER           38      /* control type: textMsg, callback function: (none) */
#define  PANEL_INFO_COMMANDBUTTON         39      /* control type: command, callback function: okFunc */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK myexitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK okFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
