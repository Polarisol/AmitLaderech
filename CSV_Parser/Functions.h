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

#define  PANEL                            1       /* callback function: exitFunc */
#define  PANEL_NUMERIC_3                  2       /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_2                  3       /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_1                  4       /* control type: numeric, callback function: (none) */
#define  PANEL_COMMANDBUTTON_3            5       /* control type: command, callback function: find_new_records */
#define  PANEL_COMMANDBUTTON              6       /* control type: command, callback function: find_num_records */
#define  PANEL_COMMANDBUTTON_2            7       /* control type: command, callback function: add */
#define  PANEL_DECORATION_3               8       /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_5               9       /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_4               10      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_2               11      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION                 12      /* control type: deco, callback function: (none) */
#define  PANEL_TEXTMSG_3                  13      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_5                  14      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_4                  15      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG                    16      /* control type: textMsg, callback function: (none) */
#define  PANEL_STRING_3                   17      /* control type: string, callback function: (none) */
#define  PANEL_TEXTMSG_2                  18      /* control type: textMsg, callback function: (none) */
#define  PANEL_STRING_2                   19      /* control type: string, callback function: (none) */
#define  PANEL_STRING_1                   20      /* control type: string, callback function: (none) */
#define  PANEL_TABLE                      21      /* control type: table, callback function: (none) */
#define  PANEL_COMMANDBUTTON_6            22      /* control type: command, callback function: CountAllRecordsWithFieldValue */
#define  PANEL_COMMANDBUTTON_5            23      /* control type: command, callback function: GetFieldFromRecord */
#define  PANEL_S_VAL                      24      /* control type: string, callback function: (none) */
#define  PANEL_S_FIELD_NAME_2             25      /* control type: string, callback function: (none) */
#define  PANEL_S_FILE_NAME_2              26      /* control type: string, callback function: (none) */
#define  PANEL_RECORD_NUM_2               27      /* control type: numeric, callback function: (none) */
#define  PANEL_RECORD_NUM                 28      /* control type: numeric, callback function: (none) */
#define  PANEL_S_FILE_NAME                29      /* control type: string, callback function: (none) */
#define  PANEL_TEXTBOX                    30      /* control type: textBox, callback function: (none) */
#define  PANEL_RING                       31      /* control type: ring, callback function: (none) */
#define  PANEL_COMMANDBUTTON_4            32      /* control type: command, callback function: Load_headers */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK add(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CountAllRecordsWithFieldValue(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK find_new_records(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK find_num_records(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GetFieldFromRecord(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Load_headers(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
