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
#define  P_ACTIVITY_GUIDE_BUTTON_1        2       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_2        3       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_3        4       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_4        5       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_5        6       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_6        7       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_7        8       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_8        9       /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_9        10      /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_10       11      /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_11       12      /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_GUIDE_BUTTON_12       13      /* control type: pictButton, callback function: openGuidePanel */
#define  P_ACTIVITY_ADDING_GUIDE_BUTTON   14      /* control type: pictButton, callback function: Open_New_Guide */
#define  P_ACTIVITY_LINE                  15      /* control type: deco, callback function: (none) */
#define  P_ACTIVITY_AMITLADERECH          16      /* control type: textMsg, callback function: (none) */
#define  P_ACTIVITY_GOAL                  17      /* control type: textMsg, callback function: (none) */
#define  P_ACTIVITY_LOGO                  18      /* control type: picture, callback function: (none) */
#define  P_ACTIVITY_BACKGROUND            19      /* control type: picture, callback function: (none) */

#define  P_GROUP                          2       /* callback function: exitFunc */
#define  P_GROUP_GROUP_NAME               2       /* control type: string, callback function: (none) */
#define  P_GROUP_GUIDE                    3       /* control type: string, callback function: checkIfExist */
#define  P_GROUP_CITY                     4       /* control type: string, callback function: (none) */
#define  P_GROUP_MONTH                    5       /* control type: string, callback function: (none) */
#define  P_GROUP_YEAR                     6       /* control type: string, callback function: (none) */
#define  P_GROUP_STATUS_RING              7       /* control type: ring, callback function: (none) */
#define  P_GROUP_MENTOR_1                 8       /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_4                 9       /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_7                 10      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_10                11      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_13                12      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_2                 13      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_5                 14      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_8                 15      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_11                16      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_14                17      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_3                 18      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_6                 19      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_9                 20      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_12                21      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_MENTOR_15                22      /* control type: command, callback function: OpenMentor */
#define  P_GROUP_LIST_SOLDIERS_BUTTON     23      /* control type: pictButton, callback function: openSoldierTable */
#define  P_GROUP_EDIT_GROUP_BUTTON        24      /* control type: pictButton, callback function: Edit */
#define  P_GROUP_ID_NUMBER                25      /* control type: string, callback function: (none) */
#define  P_GROUP_SAVE_CHANGES_BUTTON      26      /* control type: pictButton, callback function: SaveChanges */
#define  P_GROUP_EDIT_MENTORS_BUTTON      27      /* control type: pictButton, callback function: editMentorsInGroup */
#define  P_GROUP_DELETE_GROUP_BUTTON      28      /* control type: pictButton, callback function: delRecord */
#define  P_GROUP_LOGO                     29      /* control type: picture, callback function: (none) */
#define  P_GROUP_LINE                     30      /* control type: deco, callback function: (none) */
#define  P_GROUP_MENTORS_TXT              31      /* control type: textMsg, callback function: (none) */
#define  P_GROUP_AMITLADERECH             32      /* control type: textMsg, callback function: (none) */
#define  P_GROUP_GOAL                     33      /* control type: textMsg, callback function: (none) */
#define  P_GROUP_BACKGROUND               34      /* control type: picture, callback function: (none) */

#define  P_GUIDE                          3       /* callback function: exitFunc */
#define  P_GUIDE_ID_NUMBER                2       /* control type: string, callback function: (none) */
#define  P_GUIDE_FIRST_NAME               3       /* control type: string, callback function: (none) */
#define  P_GUIDE_LAST_NAME                4       /* control type: string, callback function: (none) */
#define  P_GUIDE_AGE                      5       /* control type: string, callback function: (none) */
#define  P_GUIDE_CELL_PHONE_NUMBER        6       /* control type: string, callback function: (none) */
#define  P_GUIDE_PHONE_NUMBER             7       /* control type: string, callback function: (none) */
#define  P_GUIDE_ADDRESS                  8       /* control type: string, callback function: (none) */
#define  P_GUIDE_CITY                     9       /* control type: string, callback function: (none) */
#define  P_GUIDE_MAIN_OCCUPATION          10      /* control type: string, callback function: (none) */
#define  P_GUIDE_GROUP_1_STRING           11      /* control type: string, callback function: (none) */
#define  P_GUIDE_GROUP_2_STRING           12      /* control type: string, callback function: (none) */
#define  P_GUIDE_MAIL                     13      /* control type: string, callback function: (none) */
#define  P_GUIDE_SUMMARY                  14      /* control type: textBox, callback function: (none) */
#define  P_GUIDE_EXCEPTIONS               15      /* control type: textBox, callback function: (none) */
#define  P_GUIDE_REPORT_BUTTON            16      /* control type: pictButton, callback function: creatReport */
#define  P_GUIDE_LIST_SOLDIERS_BUTTON     17      /* control type: pictButton, callback function: openTable */
#define  P_GUIDE_SEND_EMAIL               18      /* control type: pictButton, callback function: creatReport */
#define  P_GUIDE_EDITING_BUTTON           19      /* control type: pictButton, callback function: Edit */
#define  P_GUIDE_SAVE_CHANGES_BUTTON      20      /* control type: pictButton, callback function: SaveChanges */
#define  P_GUIDE_PICTURE                  21      /* control type: picture, callback function: pic_func_Guide */
#define  P_GUIDE_DELETING_GUIDE_BUTTON    22      /* control type: pictButton, callback function: delRecord */
#define  P_GUIDE_GROUP_2                  23      /* control type: command, callback function: showGroup */
#define  P_GUIDE_GROUP_1                  24      /* control type: command, callback function: showGroup */
#define  P_GUIDE_LINE                     25      /* control type: deco, callback function: (none) */
#define  P_GUIDE_AMITLADERECH             26      /* control type: textMsg, callback function: (none) */
#define  P_GUIDE_BACKGROUND               27      /* control type: picture, callback function: (none) */
#define  P_GUIDE_LOGO                     28      /* control type: picture, callback function: (none) */
#define  P_GUIDE_GOAL                     29      /* control type: textMsg, callback function: (none) */

#define  P_MAIN                           4       /* callback function: exitFunc */
#define  P_MAIN_SUNDAY                    2       /* control type: textBox, callback function: (none) */
#define  P_MAIN_MONDAY                    3       /* control type: textBox, callback function: (none) */
#define  P_MAIN_TUESDAY                   4       /* control type: textBox, callback function: (none) */
#define  P_MAIN_WEDNESDAY                 5       /* control type: textBox, callback function: (none) */
#define  P_MAIN_THURSDAY                  6       /* control type: textBox, callback function: (none) */
#define  P_MAIN_FRIDAY                    7       /* control type: textBox, callback function: (none) */
#define  P_MAIN_MY_TASKS                  8       /* control type: textBox, callback function: (none) */
#define  P_MAIN_STATISTICS                9       /* control type: textBox, callback function: (none) */
#define  P_MAIN_SEARCH_STRING             10      /* control type: string, callback function: changeVal */
#define  P_MAIN_ADDING_MENTOR_BUTTON      11      /* control type: pictButton, callback function: Open_P_NEW_MENTOR */
#define  P_MAIN_CLOCK_STRING              12      /* control type: string, callback function: (none) */
#define  P_MAIN_DATE_STRING               13      /* control type: string, callback function: (none) */
#define  P_MAIN_BLESSING                  14      /* control type: string, callback function: (none) */
#define  P_MAIN_NEW_SOLDIER_BUTTON        15      /* control type: pictButton, callback function: Open_P_NEW_SOLD */
#define  P_MAIN_AMITLADERECH              16      /* control type: textMsg, callback function: (none) */
#define  P_MAIN_NEW_GROUP_BUTTON          17      /* control type: pictButton, callback function: OpenPanelNewGroup */
#define  P_MAIN_ACTIVITY_PANEL_BUTTON     18      /* control type: pictButton, callback function: OPEN_P_Activity */
#define  P_MAIN_GOAL                      19      /* control type: textMsg, callback function: (none) */
#define  P_MAIN_LOGO                      20      /* control type: picture, callback function: (none) */
#define  P_MAIN_LINE                      21      /* control type: deco, callback function: (none) */
#define  P_MAIN_LIST_SOLDIERS_BUTTO_2     22      /* control type: pictButton, callback function: openMentorTable */
#define  P_MAIN_LIST_SOLDIERS_BUTTON      23      /* control type: pictButton, callback function: openSoldierTable */
#define  P_MAIN_BACKGROUND                24      /* control type: picture, callback function: (none) */
#define  P_MAIN_SEARCH_RING               25      /* control type: ring, callback function: changeVal */
#define  P_MAIN_SEARCH_BY_RING            26      /* control type: ring, callback function: changeVal */
#define  P_MAIN_CLOCK_DATE_TIMER          27      /* control type: timer, callback function: TimeUpdate */

#define  P_MENTOR                         5       /* callback function: exitFunc */
#define  P_MENTOR_ID_NUMBER               2       /* control type: string, callback function: (none) */
#define  P_MENTOR_FIRST_NAME              3       /* control type: string, callback function: (none) */
#define  P_MENTOR_LAST_NAME               4       /* control type: string, callback function: (none) */
#define  P_MENTOR_AGE                     5       /* control type: string, callback function: (none) */
#define  P_MENTOR_PHONE_NUMBER            6       /* control type: string, callback function: (none) */
#define  P_MENTOR_CELL_PHONE_NUMBER       7       /* control type: string, callback function: (none) */
#define  P_MENTOR_ADDRESS                 8       /* control type: string, callback function: (none) */
#define  P_MENTOR_CITY                    9       /* control type: string, callback function: (none) */
#define  P_MENTOR_MAIN_OCCUPATION         10      /* control type: string, callback function: (none) */
#define  P_MENTOR_MAIL                    11      /* control type: string, callback function: (none) */
#define  P_MENTOR_GUIDE                   12      /* control type: string, callback function: checkIfExist */
#define  P_MENTOR_SOLDIER_BUTTON          13      /* control type: command, callback function: openSoldier */
#define  P_MENTOR_COMMENTS_FROM_MEETING   14      /* control type: textBox, callback function: (none) */
#define  P_MENTOR_DATA_BUTTON             15      /* control type: command, callback function: OPEN_DATA */
#define  P_MENTOR_REPORT_BUTTON           16      /* control type: pictButton, callback function: creatReport */
#define  P_MENTOR_SEND_EMAIL              17      /* control type: pictButton, callback function: creatReport */
#define  P_MENTOR_EDITING_BUTTON          18      /* control type: pictButton, callback function: Edit */
#define  P_MENTOR_SAVE_CHANGES_BUTTON     19      /* control type: pictButton, callback function: SaveChanges */
#define  P_MENTOR_DELETING_MENTO_BUTTON   20      /* control type: pictButton, callback function: delRecord */
#define  P_MENTOR_TOTAL_MEETINGS_2        21      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_TOTAL_MEETINGS          22      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_TOTAL_SUBJECTS_2        23      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_LAST_MEETING_4          24      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_LAST_MEETING_2          25      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_TOTAL_SUBJECTS          26      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_TABLE                   27      /* control type: table, callback function: (none) */
#define  P_MENTOR_LAST_MEETING_3          28      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_LAST_MEETING            29      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_PICTURE                 30      /* control type: picture, callback function: pic_func_Ment */
#define  P_MENTOR_LINE                    31      /* control type: deco, callback function: (none) */
#define  P_MENTOR_AMITLADERECH            32      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_GOAL                    33      /* control type: textMsg, callback function: (none) */
#define  P_MENTOR_LOGO                    34      /* control type: picture, callback function: (none) */
#define  P_MENTOR_BACKGROUND              35      /* control type: picture, callback function: (none) */

#define  P_NEW_GROU                       6       /* callback function: exitFunc */
#define  P_NEW_GROU_GUIDE                 2       /* control type: string, callback function: checkIfExist */
#define  P_NEW_GROU_CITY                  3       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_MONTH                 4       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_YEAR                  5       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_ID_NUMBER             6       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_STATUS_RING           7       /* control type: ring, callback function: (none) */
#define  P_NEW_GROU_GROUP_NAME            8       /* control type: string, callback function: (none) */
#define  P_NEW_GROU_AMITLADERECH          9       /* control type: textMsg, callback function: (none) */
#define  P_NEW_GROU_GOAL                  10      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GROU_LOGO                  11      /* control type: picture, callback function: (none) */
#define  P_NEW_GROU_HEADLINE              12      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GROU_LINE                  13      /* control type: deco, callback function: (none) */
#define  P_NEW_GROU_BACKGROUND            14      /* control type: picture, callback function: (none) */
#define  P_NEW_GROU_SAVE_GROUP_BUTTON     15      /* control type: pictButton, callback function: Save_Sol_Func */

#define  P_NEW_GUID                       7       /* callback function: exitFunc */
#define  P_NEW_GUID_ID_NUMBER             2       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_FIRST_NAME            3       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_CELL_PHONE_NUMBER     4       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_ADDRESS               5       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_CITY                  6       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_AGE                   7       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_LAST_NAME             8       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_PHONE_NUMBER          9       /* control type: string, callback function: (none) */
#define  P_NEW_GUID_MAIL                  10      /* control type: string, callback function: (none) */
#define  P_NEW_GUID_MAIN_OCCUPATION       11      /* control type: string, callback function: (none) */
#define  P_NEW_GUID_SELECT_IMAGE_BUTTON   12      /* control type: command, callback function: pic_func_Guide */
#define  P_NEW_GUID_SAVE_DATA_BUTTON      13      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_GUID_PICTURE               14      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_HEADLINE              15      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_LINE                  16      /* control type: deco, callback function: (none) */
#define  P_NEW_GUID_AMITLADERECH          17      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_GOAL                  18      /* control type: textMsg, callback function: (none) */
#define  P_NEW_GUID_BACKGROUND            19      /* control type: picture, callback function: (none) */
#define  P_NEW_GUID_LOGO                  20      /* control type: picture, callback function: (none) */

#define  P_NEW_MENT                       8       /* callback function: exitFunc */
#define  P_NEW_MENT_ID_NUMBER             2       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_FIRST_NAME            3       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_CELL_PHONE_NUMBER     4       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_ADDRESS               5       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_CITY                  6       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_AGE                   7       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_GUIDE                 8       /* control type: string, callback function: checkIfExist */
#define  P_NEW_MENT_LAST_NAME             9       /* control type: string, callback function: (none) */
#define  P_NEW_MENT_PHONE_NUMBER          10      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIL                  11      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_MAIN_OCCUPATION       12      /* control type: string, callback function: (none) */
#define  P_NEW_MENT_SELECT_IMAGE_BUTTON   13      /* control type: command, callback function: pic_func_Ment */
#define  P_NEW_MENT_SAVE_DATA_BUTTON      14      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_MENT_PICTURE               15      /* control type: picture, callback function: pic_func_Ment */
#define  P_NEW_MENT_HEADLINE              16      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_LINE                  17      /* control type: deco, callback function: (none) */
#define  P_NEW_MENT_AMITLADERECH          18      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_GOAL                  19      /* control type: textMsg, callback function: (none) */
#define  P_NEW_MENT_BACKGROUND            20      /* control type: picture, callback function: (none) */
#define  P_NEW_MENT_LOGO                  21      /* control type: picture, callback function: (none) */

#define  P_NEW_SOLD                       9       /* callback function: exitFunc */
#define  P_NEW_SOLD_FIRST_NAME            2       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_LAST_NAME             3       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ID_NUMBER             4       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_CELL_PHONE_NUMBER     5       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_PHONE_NUMBER          6       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ADDRESS               7       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_CITY                  8       /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_RESIDENCE_STATUS_RING 9       /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_ECONOMIC_STATUS_RING  10      /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_LEGAL_STATUS_RING     11      /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_EMPLOYMENT_STATU_RING 12      /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_EDUCATION_STATUS_RING 13      /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_STATUS_RING           14      /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_DIRECTING_RING        15      /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_GENDER_RING           16      /* control type: ring, callback function: changeValSold */
#define  P_NEW_SOLD_GENDER_OTHER          17      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_MAIL                  18      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_AGE                   19      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_DATE            20      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_DIRECTING_OTHER       21      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_EDUCATION_STATU_OTHER 22      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_EMPLOYMENT_STAT_OTHER 23      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_LEGAL_STATUS_OTHER    24      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_ECONOMIC_STATUS_OTHER 25      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_RESIDENCE_STATU_OTHER 26      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_STATUS_OTHER          27      /* control type: string, callback function: (none) */
#define  P_NEW_SOLD_HEADLINE              28      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_SELECT_IMAGE_BUTTON   29      /* control type: command, callback function: pic_func_Sold */
#define  P_NEW_SOLD_SAVE_DATA_BUTTON      30      /* control type: pictButton, callback function: Save_Sol_Func */
#define  P_NEW_SOLD_PICTURE               31      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_LINE                  32      /* control type: deco, callback function: (none) */
#define  P_NEW_SOLD_AMITLADERECH          33      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_GOAL                  34      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_LOGO                  35      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_DATE_HL         36      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DAY_BD_RING           37      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_MONTH_BD_RING         38      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_SLASH_MY        39      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_BIRTH_SLASH_DM        40      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_YEAR_BD_RING          41      /* control type: ring, callback function: (none) */
#define  P_NEW_SOLD_BACKGROUND            42      /* control type: picture, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_1           43      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_2           44      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_3           45      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_4           46      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_5           47      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_6           48      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_7           49      /* control type: textMsg, callback function: (none) */
#define  P_NEW_SOLD_DETAIL_HL_8           50      /* control type: textMsg, callback function: (none) */

#define  P_SOLDIER                        10      /* callback function: exitFunc */
#define  P_SOLDIER_FIRST_NAME             2       /* control type: string, callback function: (none) */
#define  P_SOLDIER_LAST_NAME              3       /* control type: string, callback function: (none) */
#define  P_SOLDIER_ID_NUMBER              4       /* control type: string, callback function: (none) */
#define  P_SOLDIER_CELL_PHONE_NUMBER      5       /* control type: string, callback function: (none) */
#define  P_SOLDIER_PHONE_NUMBER           6       /* control type: string, callback function: (none) */
#define  P_SOLDIER_ADDRESS                7       /* control type: string, callback function: (none) */
#define  P_SOLDIER_CITY                   8       /* control type: string, callback function: (none) */
#define  P_SOLDIER_RESIDENCE_STATUS_RING  9       /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_ECONOMIC_STATUS_RING   10      /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_LEGAL_STATUS_RING      11      /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_EMPLOYMENT_STATU_RING  12      /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_EDUCATION_STATUS_RING  13      /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_STATUS_RING            14      /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_DIRECTING_RING         15      /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_GENDER_OTHER           16      /* control type: string, callback function: (none) */
#define  P_SOLDIER_BIRTH_DATE             17      /* control type: string, callback function: (none) */
#define  P_SOLDIER_AGE                    18      /* control type: string, callback function: (none) */
#define  P_SOLDIER_MAIL                   19      /* control type: string, callback function: (none) */
#define  P_SOLDIER_COMMENTS_FROM_MEETING  20      /* control type: textBox, callback function: (none) */
#define  P_SOLDIER_GROUP                  21      /* control type: string, callback function: (none) */
#define  P_SOLDIER_GUIDE                  22      /* control type: string, callback function: checkIfExist */
#define  P_SOLDIER_MENTOR                 23      /* control type: string, callback function: checkIfExist */
#define  P_SOLDIER_SAVE_CHANGES_BUTTON    24      /* control type: pictButton, callback function: SaveChanges */
#define  P_SOLDIER_MOVING_ARCHIVE_BUTTON  25      /* control type: pictButton, callback function: (none) */
#define  P_SOLDIER_TOTAL_MEETINGS_2       26      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_TOTAL_MEETINGS         27      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_TOTAL_SUBJECTS_2       28      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_LAST_MEETING_4         29      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_LAST_MEETING_2         30      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_TOTAL_SUBJECTS         31      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_TABLE                  32      /* control type: table, callback function: (none) */
#define  P_SOLDIER_LAST_MEETING_3         33      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_LAST_MEETING           34      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DIRECTING_OTHER        35      /* control type: string, callback function: (none) */
#define  P_SOLDIER_EDUCATION_STATU_OTHER  36      /* control type: string, callback function: (none) */
#define  P_SOLDIER_EMPLOYMENT_STAT_OTHER  37      /* control type: string, callback function: (none) */
#define  P_SOLDIER_LEGAL_STATUS_OTHER     38      /* control type: string, callback function: (none) */
#define  P_SOLDIER_ECONOMIC_STATUS_OTHER  39      /* control type: string, callback function: (none) */
#define  P_SOLDIER_RESIDENCE_STATU_OTHER  40      /* control type: string, callback function: (none) */
#define  P_SOLDIER_STATUS_OTHER           41      /* control type: string, callback function: (none) */
#define  P_SOLDIER_REPORT_BUTTON          42      /* control type: pictButton, callback function: creatReport */
#define  P_SOLDIER_EDITING_BUTTON         43      /* control type: pictButton, callback function: Edit */
#define  P_SOLDIER_GENDER_RING            44      /* control type: ring, callback function: changeValSold */
#define  P_SOLDIER_SEND_EMAIL             45      /* control type: pictButton, callback function: creatReport */
#define  P_SOLDIER_MENTOR_BTN             46      /* control type: command, callback function: chooseMentForSol */
#define  P_SOLDIER_GROUP_BTN              47      /* control type: command, callback function: chooseGroupForSol */
#define  P_SOLDIER_EDIT_TL_BUTTON         48      /* control type: command, callback function: editTL */
#define  P_SOLDIER_LINE                   49      /* control type: deco, callback function: (none) */
#define  P_SOLDIER_AMITLADERECH           50      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_GOAL                   51      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_LOGO                   52      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_DAY_BD_RING            53      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_MONTH_BD_RING          54      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_BIRTH_SLASH_MY         55      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_YEAR_BD_RING           56      /* control type: ring, callback function: (none) */
#define  P_SOLDIER_BACKGROUND             57      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_1            58      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_2            59      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_4            60      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_5            61      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_6            62      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_7            63      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_8            64      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_TIME_LINE_PIC          65      /* control type: picture, callback function: (none) */
#define  P_SOLDIER_BIRTH_DATE_HL          66      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_DETAIL_HL_3            67      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_BIRTH_SLASH_DM         68      /* control type: textMsg, callback function: (none) */
#define  P_SOLDIER_PICTURE                69      /* control type: picture, callback function: (none) */

#define  P_TABLE                          11      /* callback function: exitFunc */
#define  P_TABLE_LINE                     2       /* control type: deco, callback function: (none) */
#define  P_TABLE_AMITLADERECH             3       /* control type: textMsg, callback function: (none) */
#define  P_TABLE_GOAL                     4       /* control type: textMsg, callback function: (none) */
#define  P_TABLE_BACKGROUND               5       /* control type: picture, callback function: (none) */
#define  P_TABLE_LOGO                     6       /* control type: picture, callback function: (none) */
#define  P_TABLE_LIST_S_OR_M              7       /* control type: table, callback function: tblFunction */
#define  P_TABLE_GNAME                    8       /* control type: string, callback function: (none) */
#define  P_TABLE_TABLE_HEADLINE           9       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

#define  CA_GROUP_EDIT                    1
#define  CA_GUIDE_ACTION                  2
#define  CA_GUIDE_VIS                     3
#define  CA_MENTOR_ACTION                 4
#define  CA_MENTOR_BTN                    5
#define  CA_MENTOR_VIS                    6
#define  CA_SOLDIER_ACTION                7
#define  CA_SOLDIER_HORI                  8
#define  CA_SOLDIER_OTHERS                9
#define  CA_SOLDIER_VIS                   10
#define  CTRLARRAY                        11
#define  CTRLARRAY_10                     12
#define  CTRLARRAY_11                     13
#define  CTRLARRAY_12                     14
#define  CTRLARRAY_13                     15
#define  CTRLARRAY_14                     16
#define  CTRLARRAY_15                     17
#define  CTRLARRAY_16                     18
#define  CTRLARRAY_17                     19
#define  CTRLARRAY_18                     20
#define  CTRLARRAY_2                      21
#define  CTRLARRAY_3                      22
#define  CTRLARRAY_4                      23
#define  CTRLARRAY_5                      24
#define  CTRLARRAY_6                      25
#define  CTRLARRAY_7                      26
#define  CTRLARRAY_8                      27
#define  CTRLARRAY_9                      28
#define  LBLCTRL                          29

     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK changeVal(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK changeValSold(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK checkIfExist(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK chooseGroupForSol(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK chooseMentForSol(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK creatReport(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK delRecord(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Edit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK editMentorsInGroup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK editTL(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OPEN_DATA(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_New_Guide(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OPEN_P_Activity(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_P_NEW_MENTOR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Open_P_NEW_SOLD(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK openGuidePanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OpenMentor(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK openMentorTable(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OpenPanelNewGroup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK openSoldier(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK openSoldierTable(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK openTable(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pic_func_Guide(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pic_func_Ment(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pic_func_Sold(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Save_Sol_Func(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveChanges(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK showGroup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tblFunction(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TimeUpdate(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
