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
#define  P_ACTIVITY_ADDING_GUIDE_BUTTON   2       /* control type: pictButton, callback function: Open_New_Guide */
#define  P_ACTIVITY_LINE                  3       /* control type: deco, callback function: (none) */
#define  P_ACTIVITY_AMITLADERECH          4       /* control type: textMsg, callback function: (none) */
#define  P_ACTIVITY_GUIDE_2_BUTTON        5       /* control type: pictButton, callback function: (none) */
#define  P_ACTIVITY_GUIDE_3_BUTTON        6       /* control type: pictButton, callback function: (none) */
#define  P_ACTIVITY_GUIDE_4_BUTTON        7       /* control type: pictButton, callback function: (none) */
#define  P_ACTIVITY_GUIDE_1_BUTTON        8       /* control type: pictButton, callback function: (none) */
#define  P_ACTIVITY_GOAL                  9       /* control type: textMsg, callback function: (none) */
#define  P_ACTIVITY_LOGO                  10      /* control type: picture, callback function: (none) */
#define  P_ACTIVITY_BACKGROUND            11      /* control type: picture, callback function: (none) */

#define  P_GUIDE                          2       /* callback function: exitFunc */
#define  P_GUIDE_ADDING_MENTOR_BUTTON     2       /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_MAIN_OCCUPATION          3       /* control type: string, callback function: (none) */
#define  P_GUIDE_ADDRESS                  4       /* control type: string, callback function: (none) */
#define  P_GUIDE_PHONE_NUMBER             5       /* control type: string, callback function: (none) */
#define  P_GUIDE_AGE                      6       /* control type: string, callback function: (none) */
#define  P_GUIDE_LAST_NAME                7       /* control type: string, callback function: (none) */
#define  P_GUIDE_FIRST_NAME               8       /* control type: string, callback function: (none) */
#define  P_GUIDE_ID_NUMBER                9       /* control type: string, callback function: (none) */
#define  P_GUIDE_IMAGE                    10      /* control type: picture, callback function: (none) */
#define  P_GUIDE_DELETING_GUIDE_BUTTON    11      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_SAVE_CHANGES_BUTTON      12      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_EDITING_BUTTON           13      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_SEND_EMAIL               14      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_LIST_SOLDIERS_BUTTON     15      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_MENTOR_15                16      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_14                17      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_13                18      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_12                19      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_11                20      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_10                21      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_9                 22      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_8                 23      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_7                 24      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_6                 25      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_5                 26      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_4                 27      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_3                 28      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_2                 29      /* control type: command, callback function: (none) */
#define  P_GUIDE_MENTOR_1                 30      /* control type: command, callback function: (none) */
#define  P_GUIDE_SUMMARY                  31      /* control type: textBox, callback function: (none) */
#define  P_GUIDE_EXCEPTIONS               32      /* control type: textBox, callback function: (none) */
#define  P_GUIDE_LINE                     33      /* control type: deco, callback function: (none) */
#define  P_GUIDE_AMITLADERECH             34      /* control type: textMsg, callback function: (none) */
#define  P_GUIDE_GOAL                     35      /* control type: textMsg, callback function: (none) */
#define  P_GUIDE_LOGO                     36      /* control type: picture, callback function: (none) */
#define  P_GUIDE_BACKGROUND               37      /* control type: picture, callback function: (none) */

#define  P_MAIN                           3       /* callback function: exitFunc */
#define  P_MAIN_CLOCK_STRING              2       /* control type: string, callback function: (none) */
#define  P_MAIN_DATE_STRING               3       /* control type: string, callback function: (none) */
#define  P_MAIN_BLESSING                  4       /* control type: string, callback function: (none) */
#define  P_MAIN_FRIDAY                    5       /* control type: textBox, callback function: (none) */
#define  P_MAIN_THURSDAY                  6       /* control type: textBox, callback function: (none) */
#define  P_MAIN_WEDNESDAY                 7       /* control type: textBox, callback function: (none) */
#define  P_MAIN_TUESDAY                   8       /* control type: textBox, callback function: (none) */
#define  P_MAIN_MONDAY                    9       /* control type: textBox, callback function: (none) */
#define  P_MAIN_SUNDAY                    10      /* control type: textBox, callback function: (none) */
#define  P_MAIN_MY_TASKS                  11      /* control type: textBox, callback function: (none) */
#define  P_MAIN_STATISTICS                12      /* control type: textBox, callback function: (none) */
#define  P_MAIN_NEW_SOLDIER_BUTTON        13      /* control type: pictButton, callback function: Open_P_NEW_SOLD */
#define  P_MAIN_AMITLADERECH              14      /* control type: textMsg, callback function: (none) */
#define  P_MAIN_ACTIVITY_PANEL_BUTTON     15      /* control type: pictButton, callback function: OPEN_P_Activity */
#define  P_MAIN_ANALYSIS_PANEL_BUTTO2     16      /* control type: pictButton, callback function: (none) */
#define  P_MAIN_GOAL                      17      /* control type: textMsg, callback function: (none) */
#define  P_MAIN_LOGO                      18      /* control type: picture, callback function: (none) */
#define  P_MAIN_LINE                      19      /* control type: deco, callback function: (none) */
#define  P_MAIN_LIST_SOLDIERS_BUTTON      20      /* control type: pictButton, callback function: (none) */
#define  P_MAIN_BACKGROUND                21      /* control type: picture, callback function: (none) */

#define  P_MENTOR                         4       /* callback function: exitFunc */
#define  P_MENTOR_ADDING_SOLDIER_BUTTON   2       /* control type: pictButton, callback function: Open_P_NEW_SOLD */
#define  P_MENTOR_MAIN_OCCUPATION         3       /* control type: string, callback function: (none) */
#define  P_MENTOR_ADDRESS                 4       /* control type: string, callback function: (none) */
#define  P_MENTOR_PHONE_NUMBER            5       /* control type: string, callback function: (none) */
#define  P_MENTOR_AGE                     6       /* control type: string, callback function: (none) */
#define  P_MENTOR_GUIDE                   7       /* control type: string, callback function: (none) */
#define  P_MENTOR_NEXT_MEETING_DATE       8       /* control type: string, callback function: (none) */
#define  P_MENTOR_LAST_MEETING_DATE       9       /* control type: string, callback function: (none) */
#define  P_MENTOR_LAST_NAME               10      /* control type: string, callback function: (none) */
#define  P_MENTOR_FIRST_NAME              11      /* control type: string, callback function: (none) */
#define  P_MENTOR_ID_NUMBER               12      /* control type: string, callback function: (none) */
#define  P_MENTOR_IMAGE                   13      /* control type: picture, callback function: (none) */
#define  P_MENTOR_DELETING_MENTO_BUTTON   14      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_MEETING_LED             15      /* control type: LED, callback function: (none) */
#define  P_MENTOR_SAVE_CHANGES_BUTTON     16      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_EDITING_BUTTON          17      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_SEND_EMAIL              18      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_EXCEPTIONS              19      /* control type: textBox, callback function: (none) */
#define  P_MENTOR_LINE                    20      /* control type: deco, callback function: (none) */
#define  P_MENTOR_PROGRESS_RING           21      /* control type: slide, callback function: (none) */
#define  P_MENTOR_AMITLADERECH            22      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_SOLDIER_TEXT            23      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_GOAL                    24      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_LOGO                    25      /* control type: picture, callback function: (none) */
#define  P_MENTOR_BACKGROUND              26      /* control type: picture, callback function: (none) */
#define  P_MENTOR_SOLDIER_BUTTON          27      /* control type: command, callback function: (none) */

#define  P_NEW_GUID                       5       /* callback function: exitFunc */
#define  P_NEW_GUID_MAIN_OCCUPATION       2       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_ADDRESS               3       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_PHONE_NUMBER          4       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_MAIL                  5       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_AGE                   6       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_IMAGE                 7       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_LAST_NAME             8       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_FIRST_NAME            9       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_ID_NUMBER             10      /* control type: string, callback function: (none) */
#define  P_NEW_GUID_IMAGE_BOX             11      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_SAVE_DATA_BUTTON      12      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_GUID_HEADLINE              13      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_LINE                  14      /* control type: deco, callback function: (none) */
#define  P_NEW_GUID_AMITLADERECH          15      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_GOAL                  16      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_BACKGROUND            17      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_LOGO                  18      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_SELECT_IMAGE_BUTTON   19      /* control type: command, callback function: (none) */

#define  P_NEW_MENT                       6       /* callback function: exitFunc */
#define  P_NEW_MENT_GUIDE                 2       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIN_OCCUPATION       3       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_ADDRESS               4       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_PHONE_NUMBER          5       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIL                  6       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_AGE                   7       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_IMAGE                 8       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_LAST_NAME             9       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_FIRST_NAME            10      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_ID_NUMBER             11      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_IMAGE_BOX             12      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_SAVE_DATA_BUTTON      13      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_MENT_HEADLINE              14      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_LINE                  15      /* control type: deco, callback function: (none) */
#define  P_NEW_MENT_AMITLADERECH          16      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_GOAL                  17      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_BACKGROUND            18      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_LOGO                  19      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_SELECT_IMAGE_BUTTON   20      /* control type: command, callback function: (none) */

#define  P_NEW_SOLD                       7       /* callback function: exitFunc */
#define  P_NEW_SOLD_MENTOR                2       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_GUIDE                 3       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_AGE                   4       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ADDRESS               5       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_PHONE_NUMBER          6       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_MAIL                  7       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_IMAGE                 8       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_LAST_NAME             9       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_FIRST_NAME            10      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ID_NUMBER             11      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_IMAGEBOX              12      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_SAVE_DATA_BUTTON      13      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_SOLD_HEADLINE              14      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_LINE                  15      /* control type: deco, callback function: (none) */
#define  P_NEW_SOLD_AMITLADERECH          16      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_GOAL                  17      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_BACKGROUND            18      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_LOGO                  19      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_SELECT_IMAGE_BUTTON   20      /* control type: command, callback function: (none) */

#define  P_SOLDIER                        8       /* callback function: exitFunc */
#define  P_SOLDIER_ADDRESS                2       /* control type: string, callback function: (none) */
#define  P_SOLDIER_PHONE_NUMBER           3       /* control type: string, callback function: (none) */
#define  P_SOLDIER_AGE                    4       /* control type: string, callback function: (none) */
#define  P_SOLDIER_MENTOR                 5       /* control type: string, callback function: (none) */
#define  P_SOLDIER_GUIDE                  6       /* control type: string, callback function: (none) */
#define  P_SOLDIER_NEXT_MEETING_DATE      7       /* control type: string, callback function: (none) */
#define  P_SOLDIER_LAST_MEETING_DATE      8       /* control type: string, callback function: (none) */
#define  P_SOLDIER_LAST_NAME              9       /* control type: string, callback function: (none) */
#define  P_SOLDIER_FIRST_NAME             10      /* control type: string, callback function: (none) */
#define  P_SOLDIER_PROGRESS_STRING        11      /* control type: string, callback function: (none) */
#define  P_SOLDIER_IMAGE                  12      /* control type: string, callback function: (none) */
#define  P_SOLDIER_ID_NUMBER              13      /* control type: string, callback function: (none) */
#define  P_SOLDIER_IMAGE_BOX              14      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_MOVING_ARCHIVE_BUTTON  15      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_MEETING_LED            16      /* control type: LED, callback function: (none) */
#define  P_SOLDIER_SAVE_CHANGES_BUTTON    17      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_EDITING_BUTTON         18      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_SEND_EMAIL             19      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_COMMENTS               20      /* control type: textBox, callback function: (none) */
#define  P_SOLDIER_LINE                   21      /* control type: deco, callback function: (none) */
#define  P_SOLDIER_PROGRESS_RING          22      /* control type: slide, callback function: (none) */
#define  P_SOLDIER_AMITLADERECH           23      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_GOAL                   24      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_LOGO                   25      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_BACKGROUND             26      /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_New_Guide(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OPEN_P_Activity(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_P_NEW_SOLD(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Save_Sol_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
