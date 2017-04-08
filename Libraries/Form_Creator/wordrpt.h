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

#define  PANEL                            1
#define  PANEL_TABLE                      2       /* control type: table, callback function: (none) */
#define  PANEL_RUN                        3       /* control type: command, callback function: RunTests */
#define  PANEL_GENERATE                   4       /* control type: command, callback function: GenerateReport */
#define  PANEL_INSERT_TABLE               5       /* control type: command, callback function: InsertTable */
#define  PANEL_INSERT_GRAPH               6       /* control type: command, callback function: InsertGraph */
#define  PANEL_PRINT                      7       /* control type: command, callback function: PrintReport */
#define  PANEL_SAVEASHTML                 8       /* control type: command, callback function: SaveAsHTML */
#define  PANEL_QUIT                       9       /* control type: command, callback function: Quit */
#define  PANEL_GRAPH                      10      /* control type: graph, callback function: (none) */
#define  PANEL_STRING                     11      /* control type: string, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK GenerateReport(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InsertGraph(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InsertTable(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PrintReport(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RunTests(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveAsHTML(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
