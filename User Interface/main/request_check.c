#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "request_check.h"
#include "analytics_functions.h"
#include "func_Header.h" 
static int panelHandlecheck;
#define SIZE 300

int CVICALLBACK main_func (int panel, int event, void *callbackData,
						   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK check_req (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	char *string,path[SIZE],soldierfield[SIZE],mentorfield[SIZE],requestfield[SIZE];
	int rec_num;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panel, PANEL_NUMERIC, &rec_num);
			GetCtrlVal (panel, PANEL_TEXTMSG, soldierfield);
			HebrewConverter_convertHebrewISOtoUTF8(soldierfield);
			GetCtrlVal (panel, PANEL_TEXTMSG_2, mentorfield);
			HebrewConverter_convertHebrewISOtoUTF8(mentorfield);
			GetCtrlVal (panel, PANEL_TEXTMSG_3, requestfield);
			HebrewConverter_convertHebrewISOtoUTF8(requestfield);
			GetCtrlVal (panel, PANEL_TEXTMSG_4, path);
			string=request_check(path,soldierfield,mentorfield,requestfield,rec_num);
			HebrewConverter_convertHebrewUTF8toISO(string);
			SetCtrlVal (panel, PANEL_OUTPUT, string);
			break;
	}
	return 0;
}

int CVICALLBACK check_last (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	char *string,path[SIZE],soldierfield[SIZE],mentorfield[SIZE],requestfield[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panel, PANEL_TEXTMSG, soldierfield);
			HebrewConverter_convertHebrewISOtoUTF8(soldierfield);
			GetCtrlVal (panel, PANEL_TEXTMSG_2, mentorfield);
			HebrewConverter_convertHebrewISOtoUTF8(mentorfield);
			GetCtrlVal (panel, PANEL_TEXTMSG_3, requestfield);
			HebrewConverter_convertHebrewISOtoUTF8(requestfield);
			GetCtrlVal (panel, PANEL_TEXTMSG_4, path);
			string=last_request_check(path,soldierfield,mentorfield,requestfield);
			HebrewConverter_convertHebrewUTF8toISO(string);
			SetCtrlVal (panel, PANEL_OUTPUT, string);
			break;
	}
	return 0;
}
