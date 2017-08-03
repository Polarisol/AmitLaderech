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

#define  P_EMAIL                          1       /* callback function: exitFuncEmail */
#define  P_EMAIL_TO                       2       /* control type: string, callback function: toaddressFunc */
#define  P_EMAIL_SUBJECT                  3       /* control type: string, callback function: subjectFunc */
#define  P_EMAIL_TEXT                     4       /* control type: textBox, callback function: (none) */
#define  P_EMAIL_SENDBOTTON               5       /* control type: pictButton, callback function: sendmessageFunc */
#define  P_EMAIL_USERDATA                 6       /* control type: command, callback function: userinfoFunc */
#define  P_EMAIL_ADDRESSBOX               7       /* control type: command, callback function: (none) */
#define  P_EMAIL_FILESELECT               8       /* control type: pictButton, callback function: fileselectFunc */
#define  P_EMAIL_PICTURE                  9       /* control type: picture, callback function: (none) */

#define  P_EMAILD                         2       /* callback function: justrandomexitFunc */
#define  P_EMAILD_MAIL                    2       /* control type: string, callback function: (none) */
#define  P_EMAILD_USER                    3       /* control type: string, callback function: (none) */
#define  P_EMAILD_OKBOTTON                4       /* control type: command, callback function: okFunc */
#define  P_EMAILD_PASSWORD                5       /* control type: string, callback function: (none) */
#define  P_EMAILD_PORT                    6       /* control type: string, callback function: (none) */
#define  P_EMAILD_SERVER                  7       /* control type: string, callback function: (none) */
#define  P_EMAILD_PICTURE                 8       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK exitFuncEmail(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK fileselectFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK justrandomexitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK okFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK sendmessageFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK subjectFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK toaddressFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK userinfoFunc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void initialize_mail(int p,int p2);

#ifdef __cplusplus
    }
#endif
