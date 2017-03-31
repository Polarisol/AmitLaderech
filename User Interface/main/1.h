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
#define  P_ACTIVITY_GUIDE_BUTTON_2        5       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_3        6       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_4        7       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_1        8       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GOAL                  9       /* control type: textMsg, callback function: (none) */
#define  P_ACTIVITY_LOGO                  10      /* control type: picture, callback function: (none) */
#define  P_ACTIVITY_BACKGROUND            11      /* control type: picture, callback function: (none) */

#define  P_EDIT_TL                        2       /* callback function: exitFunc */
#define  P_EDIT_TL_TICK_8                 2       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_TICK_7                 3       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_TICK_6                 4       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_TICK_5                 5       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_TICK_4                 6       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_TICK_3                 7       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_TICK_2                 8       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_TICK_1                 9       /* control type: string, callback function: (none) */
#define  P_EDIT_TL_SAVE_DATA_BUTTON       10      /* control type: pictButton, callback function: (none) */
#define  P_EDIT_TL_HEADLINE               11      /* control type: textMsg, callback function: (none) */
#define  P_EDIT_TL_LINE                   12      /* control type: deco, callback function: (none) */
#define  P_EDIT_TL_AMITLADERECH           13      /* control type: textMsg, callback function: (none) */
#define  P_EDIT_TL_GOAL                   14      /* control type: textMsg, callback function: (none) */
#define  P_EDIT_TL_BACKGROUND             15      /* control type: picture, callback function: (none) */
#define  P_EDIT_TL_LOGO                   16      /* control type: picture, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_8              17      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_7              18      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_6              19      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_5              20      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_4              21      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_3              22      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_2              23      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_BOLD_CB_1              24      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_8           25      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_7           26      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_6           27      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_5           28      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_4           29      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_3           30      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_2           31      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_CB_1           32      /* control type: radioButton, callback function: (none) */
#define  P_EDIT_TL_DISPLAY_TXT            33      /* control type: textMsg, callback function: (none) */
#define  P_EDIT_TL_BOLD_TXT               34      /* control type: textMsg, callback function: (none) */

#define  P_GROUP                          3       /* callback function: exitFunc */
#define  P_GROUP_EDIT_MENTORS_BUTTON      2       /* control type: pictButton, callback function: (none) */
#define  P_GROUP_YEAR                     3       /* control type: string, callback function: (none) */
#define  P_GROUP_MONTH                    4       /* control type: string, callback function: (none) */
#define  P_GROUP_CITY                     5       /* control type: string, callback function: (none) */
#define  P_GROUP_ID_NUMBER                6       /* control type: string, callback function: (none) */
#define  P_GROUP_GROUP_NAME               7       /* control type: string, callback function: (none) */
#define  P_GROUP_GUIDE                    8       /* control type: string, callback function: (none) */
#define  P_GROUP_LOGO                     9       /* control type: picture, callback function: (none) */
#define  P_GROUP_SAVE_CHANGES_BUTTON      10      /* control type: pictButton, callback function: (none) */
#define  P_GROUP_LINE                     11      /* control type: deco, callback function: (none) */
#define  P_GROUP_STATUS_RING              12      /* control type: ring, callback function: (none) */
#define  P_GROUP_DELETE_GROUP_BUTTON      13      /* control type: pictButton, callback function: (none) */
#define  P_GROUP_EDIT_GROUP_BUTTON        14      /* control type: pictButton, callback function: edit */
#define  P_GROUP_MENTOR_15                15      /* control type: command, callback function: (none) */
#define  P_GROUP_LIST_SOLDIERS_BUTTON     16      /* control type: pictButton, callback function: (none) */
#define  P_GROUP_MENTOR_14                17      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_13                18      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_12                19      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_11                20      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_10                21      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_9                 22      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_8                 23      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_7                 24      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_6                 25      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_5                 26      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_2                 27      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_4                 28      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTOR_1                 29      /* control type: command, callback function: (none) */
#define  P_GROUP_MENTORS_TXT              30      /* control type: textMsg, callback function: (none) */
#define  P_GROUP_AMITLADERECH             31      /* control type: textMsg, callback function: (none) */
#define  P_GROUP_GOAL                     32      /* control type: textMsg, callback function: (none) */
#define  P_GROUP_MENTOR_3                 33      /* control type: command, callback function: (none) */
#define  P_GROUP_BACKGROUND               34      /* control type: picture, callback function: (none) */

#define  P_GUIDE                          4       /* callback function: exitFunc */
#define  P_GUIDE_MAIN_OCCUPATION          2       /* control type: string, callback function: (none) */
#define  P_GUIDE_CELL_PHONE_NUMBER        3       /* control type: string, callback function: (none) */
#define  P_GUIDE_CITY                     4       /* control type: string, callback function: (none) */
#define  P_GUIDE_ADDRESS                  5       /* control type: string, callback function: (none) */
#define  P_GUIDE_PHONE_NUMBER             6       /* control type: string, callback function: (none) */
#define  P_GUIDE_AGE                      7       /* control type: string, callback function: (none) */
#define  P_GUIDE_LAST_NAME                8       /* control type: string, callback function: (none) */
#define  P_GUIDE_FIRST_NAME               9       /* control type: string, callback function: (none) */
#define  P_GUIDE_IMAGE                    10      /* control type: string, callback function: (none) */
#define  P_GUIDE_GROUP_1_STRING           11      /* control type: string, callback function: (none) */
#define  P_GUIDE_GROUP_2_STRING           12      /* control type: string, callback function: (none) */
#define  P_GUIDE_ID_NUMBER                13      /* control type: string, callback function: (none) */
#define  P_GUIDE_IMAGE_BOX                14      /* control type: picture, callback function: (none) */
#define  P_GUIDE_DELETING_GUIDE_BUTTON    15      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_SAVE_CHANGES_BUTTON      16      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_EDITING_BUTTON           17      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_SEND_EMAIL               18      /* control type: pictButton, callback function: (none) */
#define  P_GUIDE_LIST_SOLDIERS_BUTTON     19      /* control type: pictButton, callback function: openTable */
#define  P_GUIDE_GROUP_2                  20      /* control type: command, callback function: (none) */
#define  P_GUIDE_GROUP_1                  21      /* control type: command, callback function: (none) */
#define  P_GUIDE_SUMMARY                  22      /* control type: textBox, callback function: (none) */
#define  P_GUIDE_EXCEPTIONS               23      /* control type: textBox, callback function: (none) */
#define  P_GUIDE_LINE                     24      /* control type: deco, callback function: (none) */
#define  P_GUIDE_AMITLADERECH             25      /* control type: textMsg, callback function: (none) */
#define  P_GUIDE_BACKGROUND               26      /* control type: picture, callback function: (none) */
#define  P_GUIDE_LOGO                     27      /* control type: picture, callback function: (none) */
#define  P_GUIDE_GOAL                     28      /* control type: textMsg, callback function: (none) */

#define  P_MAIN                           5       /* callback function: exitFunc */
#define  P_MAIN_ADDING_MENTOR_BUTTON      2       /* control type: pictButton, callback function: Open_P_NEW_MENTOR */
#define  P_MAIN_CLOCK_STRING              3       /* control type: string, callback function: (none) */
#define  P_MAIN_DATE_STRING               4       /* control type: string, callback function: (none) */
#define  P_MAIN_BLESSING                  5       /* control type: string, callback function: (none) */
#define  P_MAIN_FRIDAY                    6       /* control type: textBox, callback function: (none) */
#define  P_MAIN_THURSDAY                  7       /* control type: textBox, callback function: (none) */
#define  P_MAIN_WEDNESDAY                 8       /* control type: textBox, callback function: (none) */
#define  P_MAIN_TUESDAY                   9       /* control type: textBox, callback function: (none) */
#define  P_MAIN_MONDAY                    10      /* control type: textBox, callback function: (none) */
#define  P_MAIN_SUNDAY                    11      /* control type: textBox, callback function: (none) */
#define  P_MAIN_SEARCH_BY_RING            12      /* control type: ring, callback function: changeVal */
#define  P_MAIN_SEARCH_RING               13      /* control type: ring, callback function: changeVal */
#define  P_MAIN_MY_TASKS                  14      /* control type: textBox, callback function: (none) */
#define  P_MAIN_STATISTICS                15      /* control type: textBox, callback function: (none) */
#define  P_MAIN_NEW_SOLDIER_BUTTON        16      /* control type: pictButton, callback function: Open_P_NEW_SOLD */
#define  P_MAIN_AMITLADERECH              17      /* control type: textMsg, callback function: (none) */
#define  P_MAIN_NEW_GROUP_BUTTON          18      /* control type: pictButton, callback function: OpenPanelNewGroup */
#define  P_MAIN_ACTIVITY_PANEL_BUTTON     19      /* control type: pictButton, callback function: OPEN_P_Activity */
#define  P_MAIN_ANALYSIS_PANEL_BUTTO2     20      /* control type: pictButton, callback function: (none) */
#define  P_MAIN_GOAL                      21      /* control type: textMsg, callback function: (none) */
#define  P_MAIN_LOGO                      22      /* control type: picture, callback function: (none) */
#define  P_MAIN_LINE                      23      /* control type: deco, callback function: (none) */
#define  P_MAIN_LIST_SOLDIERS_BUTTON      24      /* control type: pictButton, callback function: (none) */
#define  P_MAIN_BACKGROUND                25      /* control type: picture, callback function: (none) */
#define  P_MAIN_SEARCH_STRING             26      /* control type: string, callback function: changeVal */

#define  P_MENTOR                         6       /* callback function: exitFunc */
#define  P_MENTOR_MAIN_OCCUPATION         2       /* control type: string, callback function: (none) */
#define  P_MENTOR_CELL_PHONE_NUMBER       3       /* control type: string, callback function: (none) */
#define  P_MENTOR_CITY                    4       /* control type: string, callback function: (none) */
#define  P_MENTOR_ADDRESS                 5       /* control type: string, callback function: (none) */
#define  P_MENTOR_PHONE_NUMBER            6       /* control type: string, callback function: (none) */
#define  P_MENTOR_AGE                     7       /* control type: string, callback function: (none) */
#define  P_MENTOR_GUIDE                   8       /* control type: string, callback function: (none) */
#define  P_MENTOR_NEXT_MEETING_DATE       9       /* control type: string, callback function: (none) */
#define  P_MENTOR_SOLDIER_NAME_S          10      /* control type: string, callback function: (none) */
#define  P_MENTOR_PROGRESS_STRING         11      /* control type: string, callback function: (none) */
#define  P_MENTOR_IMAGE                   12      /* control type: string, callback function: (none) */
#define  P_MENTOR_LAST_MEETING_DATE       13      /* control type: string, callback function: (none) */
#define  P_MENTOR_LAST_NAME               14      /* control type: string, callback function: (none) */
#define  P_MENTOR_FIRST_NAME              15      /* control type: string, callback function: (none) */
#define  P_MENTOR_ID_NUMBER               16      /* control type: string, callback function: (none) */
#define  P_MENTOR_IMAGE_BOX               17      /* control type: picture, callback function: (none) */
#define  P_MENTOR_DELETING_MENTO_BUTTON   18      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_MEETING_LED             19      /* control type: LED, callback function: (none) */
#define  P_MENTOR_SAVE_CHANGES_BUTTON     20      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_EDITING_BUTTON          21      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_SEND_EMAIL              22      /* control type: pictButton, callback function: (none) */
#define  P_MENTOR_COMMENTS_FROM_MEETING   23      /* control type: textBox, callback function: (none) */
#define  P_MENTOR_LINE                    24      /* control type: deco, callback function: (none) */
#define  P_MENTOR_PROGRESS_RING           25      /* control type: slide, callback function: (none) */
#define  P_MENTOR_AMITLADERECH            26      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_SOLDIER_TEXT            27      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_GOAL                    28      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_LOGO                    29      /* control type: picture, callback function: (none) */
#define  P_MENTOR_BACKGROUND              30      /* control type: picture, callback function: (none) */
#define  P_MENTOR_SOLDIER_BUTTON          31      /* control type: command, callback function: (none) */

#define  P_NEW_GROU                       7       /* callback function: exitFunc */
#define  P_NEW_GROU_YEAR                  2       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_MONTH                 3       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_AMITLADERECH          4       /* control type: textMsg, callback function: (none) */
#define  P_NEW_GROU_CITY                  5       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_GROUP_NAME            6       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_ID_NUMBER             7       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_GUIDE                 8       /* control type: string, callback function: checkIfExcist */
#define  P_NEW_GROU_GOAL                  9       /* control type: textMsg, callback function: (none) */
#define  P_NEW_GROU_LOGO                  10      /* control type: picture, callback function: (none) */
#define  P_NEW_GROU_HEADLINE              11      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GROU_LINE                  12      /* control type: deco, callback function: (none) */
#define  P_NEW_GROU_STATUS_RING           13      /* control type: ring, callback function: (none) */
#define  P_NEW_GROU_BACKGROUND            14      /* control type: picture, callback function: (none) */
#define  P_NEW_GROU_SAVE_GROUP_BUTTON     15      /* control type: pictButton, callback function: Save_Sol_Func */

#define  P_NEW_GUID                       8       /* callback function: exitFunc */
#define  P_NEW_GUID_IMAGE                 2       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_CELL_PHONE_NUMBER     3       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_MAIN_OCCUPATION       4       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_CITY                  5       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_ADDRESS               6       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_PHONE_NUMBER          7       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_MAIL                  8       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_AGE                   9       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_IMAGE_BOX             10      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_LAST_NAME             11      /* control type: string, callback function: (none) */
#define  P_NEW_GUID_FIRST_NAME            12      /* control type: string, callback function: (none) */
#define  P_NEW_GUID_ID_NUMBER             13      /* control type: string, callback function: (none) */
#define  P_NEW_GUID_SAVE_DATA_BUTTON      14      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_GUID_HEADLINE              15      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_LINE                  16      /* control type: deco, callback function: (none) */
#define  P_NEW_GUID_AMITLADERECH          17      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_GOAL                  18      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_BACKGROUND            19      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_LOGO                  20      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_SELECT_IMAGE_BUTTON   21      /* control type: command, callback function: (none) */

#define  P_NEW_MENT                       9       /* callback function: exitFunc */
#define  P_NEW_MENT_GUIDE                 2       /* control type: string, callback function: checkIfExcist */
#define  P_NEW_MENT_CELL_PHONE_NUMBER     3       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIN_OCCUPATION       4       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_CITY                  5       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_ADDRESS               6       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_PHONE_NUMBER          7       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIL                  8       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_AGE                   9       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_IMAGE                 10      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_LAST_NAME             11      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_FIRST_NAME            12      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_ID_NUMBER             13      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_IMAGE_BOX             14      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_SAVE_DATA_BUTTON      15      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_MENT_HEADLINE              16      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_LINE                  17      /* control type: deco, callback function: (none) */
#define  P_NEW_MENT_AMITLADERECH          18      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_GOAL                  19      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_BACKGROUND            20      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_LOGO                  21      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_SELECT_IMAGE_BUTTON   22      /* control type: command, callback function: (none) */

#define  P_NEW_SOLD                       10      /* callback function: exitFunc */
#define  P_NEW_SOLD_CYCLE                 2       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_DATE            3       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_CITY                  4       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ADDRESS               5       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_CELL_PHONE_NUMBER     6       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_PHONE_NUMBER          7       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_AGE                   8       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_MAIL                  9       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_DIRECTING_OTHER       10      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_EDUCATION_STATU_OTHER 11      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_EMPLOYMENT_STAT_OTHER 12      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_LEGAL_STATUS_OTHER    13      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ECONOMIC_STATUS_OTHER 14      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_RESIDENCE_STATU_OTHER 15      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_STATUS_OTHER_2        16      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_HEADLINE              17      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_GENDER_OTHER          18      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_MENTOR                19      /* control type: string, callback function: checkIfExcist */
#define  P_NEW_SOLD_GROUP                 20      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_GUIDE                 21      /* control type: string, callback function: checkIfExcist */
#define  P_NEW_SOLD_NEXT_MEETING_DATE     22      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_SELECT_IMAGE_BUTTON   23      /* control type: command, callback function: (none) */
#define  P_NEW_SOLD_LAST_MEETING_DATE     24      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_LAST_NAME             25      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_FIRST_NAME            26      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_IMAGE                 27      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ID_NUMBER             28      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_SAVE_DATA_BUTTON      29      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_SOLD_IMAGE_BOX             30      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_GENDER_RING           31      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_STATUS_RING           32      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_LINE                  33      /* control type: deco, callback function: (none) */
#define  P_NEW_SOLD_AMITLADERECH          34      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_EDUCATION_STATUS_RING 35      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_GOAL                  36      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_EMPLOYMENT_STATU_RING 37      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_LEGAL_STATUS_RING     38      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_LOGO                  39      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_ECONOMIC_STATUS_RING  40      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_DIRECTING_RING        41      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_RESIDENCE_STATUS_RING 42      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_CYCLE_YEAR_RING       43      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_CYCLE_MONTH_RING      44      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_AREA_RING             45      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_DATE_HL         46      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DAY_BD_RING           47      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_MONTH_BD_RING         48      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_SLASH_MY        49      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_SLASH_DM        50      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_YEAR_BD_RING          51      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_BACKGROUND            52      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_1           53      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_2           54      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_3           55      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_4           56      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_5           57      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_6           58      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_7           59      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_8           60      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_CYCLE_HL              61      /* control type: textMsg, callback function: (none) */

#define  P_SOLDIER                        11      /* callback function: exitFunc */
#define  P_SOLDIER_CYCLE                  2       /* control type: string, callback function: (none) */
#define  P_SOLDIER_BIRTH_DATE             3       /* control type: string, callback function: (none) */
#define  P_SOLDIER_CITY                   4       /* control type: string, callback function: (none) */
#define  P_SOLDIER_ADDRESS                5       /* control type: string, callback function: (none) */
#define  P_SOLDIER_CELL_PHONE_NUMBER      6       /* control type: string, callback function: (none) */
#define  P_SOLDIER_PHONE_NUMBER           7       /* control type: string, callback function: (none) */
#define  P_SOLDIER_AGE                    8       /* control type: string, callback function: (none) */
#define  P_SOLDIER_DIRECTING_OTHER        9       /* control type: string, callback function: (none) */
#define  P_SOLDIER_EDUCATION_STATU_OTHER  10      /* control type: string, callback function: (none) */
#define  P_SOLDIER_EMPLOYMENT_STAT_OTHER  11      /* control type: string, callback function: (none) */
#define  P_SOLDIER_LEGAL_STATUS_OTHER     12      /* control type: string, callback function: (none) */
#define  P_SOLDIER_ECONOMIC_STATUS_OTHER  13      /* control type: string, callback function: (none) */
#define  P_SOLDIER_RESIDENCE_STATU_OTHER  14      /* control type: string, callback function: (none) */
#define  P_SOLDIER_STATUS_OTHER_2         15      /* control type: string, callback function: (none) */
#define  P_SOLDIER_GENDER_OTHER           16      /* control type: string, callback function: (none) */
#define  P_SOLDIER_MENTOR                 17      /* control type: string, callback function: (none) */
#define  P_SOLDIER_GROUP                  18      /* control type: string, callback function: (none) */
#define  P_SOLDIER_GUIDE                  19      /* control type: string, callback function: (none) */
#define  P_SOLDIER_NEXT_MEETING_DATE      20      /* control type: string, callback function: (none) */
#define  P_SOLDIER_LAST_MEETING_DATE      21      /* control type: string, callback function: (none) */
#define  P_SOLDIER_LAST_NAME              22      /* control type: string, callback function: (none) */
#define  P_SOLDIER_FIRST_NAME             23      /* control type: string, callback function: (none) */
#define  P_SOLDIER_PROGRESS_STRING        24      /* control type: string, callback function: (none) */
#define  P_SOLDIER_IMAGE                  25      /* control type: string, callback function: (none) */
#define  P_SOLDIER_ID_NUMBER              26      /* control type: string, callback function: (none) */
#define  P_SOLDIER_IMAGE_BOX              27      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_MOVING_ARCHIVE_BUTTON  28      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_MEETING_LED            29      /* control type: LED, callback function: (none) */
#define  P_SOLDIER_SAVE_CHANGES_BUTTON    30      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_EDITING_BUTTON         31      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_GENDER_RING            32      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_SEND_EMAIL             33      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_COMMENTS_FROM_MEETING  34      /* control type: textBox, callback function: (none) */
#define  P_SOLDIER_STATUS_RING            35      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_EDIT_TL_BUTTON         36      /* control type: command, callback function: (none) */
#define  P_SOLDIER_PROGRESS_RING          37      /* control type: slide, callback function: (none) */
#define  P_SOLDIER_LINE                   38      /* control type: deco, callback function: (none) */
#define  P_SOLDIER_AMITLADERECH           39      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_EDUCATION_STATUS_RING  40      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_GOAL                   41      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_EMPLOYMENT_STATU_RING  42      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_LEGAL_STATUS_RING      43      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_LOGO                   44      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_ECONOMIC_STATUS_RING   45      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_DIRECTING_RING         46      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_RESIDENCE_STATUS_RING  47      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_CYCLE_YEAR_RING        48      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_CYCLE_MONTH_RING       49      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_AREA_RING              50      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_BIRTH_DATE_HL          51      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DAY_BD_RING            52      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_MONTH_BD_RING          53      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_BIRTH_SLASH_MY         54      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_BIRTH_SLASH_DM         55      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_YEAR_BD_RING           56      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_BACKGROUND             57      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_1            58      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_2            59      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_4            60      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_5            61      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_6            62      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_7            63      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_CYCLE_HL               64      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_8            65      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_3            66      /* control type: textMsg, callback function: (none) */

#define  P_TABLE                          12      /* callback function: exitFunc */
#define  P_TABLE_LINE                     2       /* control type: deco, callback function: (none) */
#define  P_TABLE_AMITLADERECH             3       /* control type: textMsg, callback function: (none) */
#define  P_TABLE_GOAL                     4       /* control type: textMsg, callback function: (none) */
#define  P_TABLE_BACKGROUND               5       /* control type: picture, callback function: (none) */
#define  P_TABLE_LOGO                     6       /* control type: picture, callback function: (none) */
#define  P_TABLE_LIST_S_OR_M              7       /* control type: table, callback function: (none) */
#define  P_TABLE_EXCEL_BUTTON             8       /* control type: pictButton, callback function: (none) */


     /* Control Arrays: */

#define  CTRLARRAY                        1
#define  CTRLARRAY_2                      2
#define  CTRLARRAY_3                      3
#define  CTRLARRAY_4                      4
#define  CTRLARRAY_5                      5
#define  CTRLARRAY_6                      6
#define  CTRLARRAY_7                      7
#define  CTRLARRAY_8                      8
#define  CTRLARRAY_9                      9

     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK changeVal(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK checkIfExcist(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK edit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_New_Guide(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OPEN_P_Activity(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_P_NEW_MENTOR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_P_NEW_SOLD(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK openGuidePanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OpenPanelNewGroup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK openTable(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Save_Sol_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
