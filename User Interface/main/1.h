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

#define  P_ACTIVITY                       1       /* callback function: exitFunc */
#define  P_ACTIVITY_GUIDE_4_BUTTON        2       /* control type: command, callback function: (none) */
#define  P_ACTIVITY_GUIDE_3_BUTTON        3       /* control type: command, callback function: (none) */
#define  P_ACTIVITY_GUIDE_2_BUTTON        4       /* control type: command, callback function: (none) */
#define  P_ACTIVITY_GUIDE_1_BUTTON        5       /* control type: command, callback function: (none) */
#define  P_ACTIVITY_ADDING_GUIDE_BUTTON   6       /* control type: command, callback function: (none) */

#define  P_GUIDE                          2       /* callback function: exitFunc */
#define  P_GUIDE_AGE                      2       /* control type: string, callback function: (none) */
#define  P_GUIDE_MAIN_OCCUPATION          3       /* control type: string, callback function: (none) */
#define  P_GUIDE_ADDRESS                  4       /* control type: string, callback function: (none) */
#define  P_GUIDE_PHONE_NUMBER             5       /* control type: string, callback function: (none) */
#define  P_GUIDE_LAST_NAME                6       /* control type: string, callback function: (none) */
#define  P_GUIDE_DELETING_GUIDE_BUTTON    7       /* control type: command, callback function: (none) */
#define  P_GUIDE_FIRST_NAME               8       /* control type: string, callback function: (none) */
#define  P_GUIDE_ID_NUMBER                9       /* control type: string, callback function: (none) */
#define  P_GUIDE_IMAGE                    10      /* control type: picture, callback function: (none) */
#define  P_GUIDE_EDITING_BUTTON           11      /* control type: command, callback function: (none) */
#define  P_GUIDE_LIST_SOLDIERS_BUTTON     12      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_15                13      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_9                 14      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_8                 15      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_10                16      /* control type: command, callback function: (none) */
#define  P_GUIDE_SEND_EMAIL               17      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_MENTOR_7                 18      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_14                19      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_6                 20      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_5                 21      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_12                22      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_4                 23      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_13                24      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_3                 25      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_2                 26      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_11                27      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_1                 28      /* control type: command, callback function: (none) */
#define  P_GUIDE_ADDING_MENTOR_BUTTON     29      /* control type: command, callback function: (none) */
#define  P_GUIDE_SUMMARY                  30      /* control type: textBox, callback function: (none) */
#define  P_GUIDE_EXCEPTIONS               31      /* control type: textBox, callback function: (none) */

#define  P_MAIN                           3       /* callback function: exitFunc */
#define  P_MAIN_CLOCK_STRING              2       /* control type: string, callback function: (none) */
#define  P_MAIN_DATE_STRING               3       /* control type: string, callback function: (none) */
#define  P_MAIN_BLESSING                  4       /* control type: string, callback function: (none) */
#define  P_MAIN_LIST_SOLDIERS_BUTTON      5       /* control type: command, callback function: (none) */
#define  P_MAIN_ANALYSIS_PANEL_BUTTON     6       /* control type: command, callback function: (none) */
#define  P_MAIN_ACTIVITY_PANEL_BUTTON     7       /* control type: command, callback function: OPEN_P_Activity */
#define  P_MAIN_FRIDAY                    8       /* control type: textBox, callback function: (none) */
#define  P_MAIN_THURSDAY                  9       /* control type: textBox, callback function: (none) */
#define  P_MAIN_WEDNESDAY                 10      /* control type: textBox, callback function: (none) */
#define  P_MAIN_TUESDAY                   11      /* control type: textBox, callback function: (none) */
#define  P_MAIN_MONDAY                    12      /* control type: textBox, callback function: (none) */
#define  P_MAIN_SUNDAY                    13      /* control type: textBox, callback function: (none) */
#define  P_MAIN_MY_TASKS                  14      /* control type: textBox, callback function: (none) */
#define  P_MAIN_STATISTICS                15      /* control type: textBox, callback function: (none) */
#define  P_MAIN_PICTURE                   16      /* control type: picture, callback function: (none) */
#define  P_MAIN_PICTUREBUTTON             17      /* control type: pictButton, callback function: Open_P_NEW_SOLD */

#define  P_MENTOR                         4       /* callback function: exitFunc */
#define  P_MENTOR_GUIDE                   2       /* control type: string, callback function: (none) */
#define  P_MENTOR_MAIN_OCCUPATION         3       /* control type: string, callback function: (none) */
#define  P_MENTOR_NEXT_MEETING_DATE       4       /* control type: string, callback function: (none) */
#define  P_MENTOR_LAST_MEETING_DATE       5       /* control type: string, callback function: (none) */
#define  P_MENTOR_AGE                     6       /* control type: string, callback function: (none) */
#define  P_MENTOR_DELETING_MENTO_BUTTON   7       /* control type: command, callback function: (none) */
#define  P_MENTOR_ADDRESS                 8       /* control type: string, callback function: (none) */
#define  P_MENTOR_PHONE_NUMBER            9       /* control type: string, callback function: (none) */
#define  P_MENTOR_LAST_NAME               10      /* control type: string, callback function: (none) */
#define  P_MENTOR_FIRST_NAME              11      /* control type: string, callback function: (none) */
#define  P_MENTOR_ID_NUMBER               12      /* control type: string, callback function: (none) */
#define  P_MENTOR_IMAGE                   13      /* control type: picture, callback function: (none) */
#define  P_MENTOR_EDITING_BUTTON          14      /* control type: command, callback function: (none) */
#define  P_MENTOR_MEETING_LED             15      /* control type: LED, callback function: (none) */
#define  P_MENTOR_SOLDIER_BUTTON          16      /* control type: command, callback function: (none) */
#define  P_MENTOR_ADDING_SOLDIER_BUTTON   17      /* control type: command, callback function: (none) */
#define  P_MENTOR_SEND_EMAIL              18      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_EXCEPTIONS              19      /* control type: textBox, callback function: (none) */
#define  P_MENTOR_PROGRESS_RING           20      /* control type: slide, callback function: (none) */
#define  P_MENTOR_SOLDIER_TEXT            21      /* control type: textMsg, callback function: (none) */

#define  P_NEW_GUID                       5       /* callback function: exitFunc */
#define  P_NEW_GUID_AGE                   2       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_MAIN_OCCUPATION       3       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_ADDRESS               4       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_PHONE_NUMBER          5       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_MAIL                  6       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_LAST_NAME             7       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_FIRST_NAME            8       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_ID_NUMBER             9       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_SELECT_IMAGE_BUTTON   10      /* control type: command, callback function: (none) */
#define  P_NEW_GUID_SAVE_DATA_BUTTON      11      /* control type: command, callback function: (none) */
#define  P_NEW_GUID_IMAGE                 12      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_HEADLINE              13      /* control type: textMsg, callback function: (none) */

#define  P_NEW_MENT                       6       /* callback function: exitFunc */
#define  P_NEW_MENT_AGE                   2       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_GUIDE                 3       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIN_OCCUPATION       4       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_ADDRESS               5       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_PHONE_NUMBER          6       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIL                  7       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_LAST_NAME             8       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_FIRST_NAME            9       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_ID_NUMBER             10      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_SELECT_IMAGE_BUTTON   11      /* control type: command, callback function: (none) */
#define  P_NEW_MENT_SAVE_DATA_BUTTON      12      /* control type: command, callback function: (none) */
#define  P_NEW_MENT_IMAGE                 13      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_HEADLINE              14      /* control type: textMsg, callback function: (none) */

#define  P_NEW_SOLD                       7       /* callback function: exitFunc */
#define  P_NEW_SOLD_GUIDE                 2       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_MENTOR                3       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_AGE                   4       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ADDRESS               5       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_PHONE_NUMBER          6       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_MAIL                  7       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_LAST_NAME             8       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_FIRST_NAME            9       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ID_NUMBER             10      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_SELECT_IMAGE_BUTTON   11      /* control type: command, callback function: (none) */
#define  P_NEW_SOLD_SAVE_DATA_BUTTON      12      /* control type: command, callback function: Save_Sol_Func */
#define  P_NEW_SOLD_HEADLINE              13      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_IMAGEBOX              14      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_IMAGE                 15      /* control type: string, callback function: (none) */

#define  P_SOLDIER                        8       /* callback function: exitFunc */
#define  P_SOLDIER_GUIDE                  2       /* control type: string, callback function: (none) */
#define  P_SOLDIER_MENTOR                 3       /* control type: string, callback function: (none) */
#define  P_SOLDIER_NEXT_MEETING_DATE      4       /* control type: string, callback function: (none) */
#define  P_SOLDIER_LAST_MEETING_DATE      5       /* control type: string, callback function: (none) */
#define  P_SOLDIER_AGE                    6       /* control type: string, callback function: (none) */
#define  P_SOLDIER_ADDRESS                7       /* control type: string, callback function: (none) */
#define  P_SOLDIER_PHONE_NUMBER           8       /* control type: string, callback function: (none) */
#define  P_SOLDIER_LAST_NAME              9       /* control type: string, callback function: (none) */
#define  P_SOLDIER_FIRST_NAME             10      /* control type: string, callback function: (none) */
#define  P_SOLDIER_ID_NUMBER              11      /* control type: string, callback function: (none) */
#define  P_SOLDIER_IMAGE                  12      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_EDITING_BUTTON         13      /* control type: command, callback function: (none) */
#define  P_SOLDIER_MEETING_LED            14      /* control type: LED, callback function: (none) */
#define  P_SOLDIER_COMMENTS               15      /* control type: textBox, callback function: (none) */
#define  P_SOLDIER_MOVING_ARCHIVE_BUTTON  16      /* control type: command, callback function: (none) */
#define  P_SOLDIER_PROGRESS_RING          17      /* control type: slide, callback function: (none) */
#define  P_SOLDIER_SEND_EMAIL             18      /* control type: pictButton, callback function: (none) */


     /* Control Arrays: */

#define  CTRLARRAY        		          1

     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OPEN_P_Activity(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_P_NEW_SOLD(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Save_Sol_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
