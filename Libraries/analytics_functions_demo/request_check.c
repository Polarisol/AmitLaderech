#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "request_check.h"
#include "analytics_functions.h"
#include "func_Header.h" 
static int panelHandle;
#define SIZE 300
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "request_check.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

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
			GetCtrlVal (panelHandle, PANEL_NUMERIC, &rec_num);
			GetCtrlVal (panelHandle, PANEL_TEXTMSG, soldierfield);
			HebrewConverter_convertHebrewISOtoUTF8(soldierfield);
			GetCtrlVal (panelHandle, PANEL_TEXTMSG_2, mentorfield);
			HebrewConverter_convertHebrewISOtoUTF8(mentorfield);
			GetCtrlVal (panelHandle, PANEL_TEXTMSG_3, requestfield);
			HebrewConverter_convertHebrewISOtoUTF8(requestfield);
			GetCtrlVal (panelHandle, PANEL_TEXTMSG_4, path);
			string=request_check(path,soldierfield,mentorfield,requestfield,rec_num);
			HebrewConverter_convertHebrewUTF8toISO(string);
			SetCtrlVal (panelHandle, PANEL_OUTPUT, string);
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
			GetCtrlVal (panelHandle, PANEL_TEXTMSG, soldierfield);
			HebrewConverter_convertHebrewISOtoUTF8(soldierfield);
			GetCtrlVal (panelHandle, PANEL_TEXTMSG_2, mentorfield);
			HebrewConverter_convertHebrewISOtoUTF8(mentorfield);
			GetCtrlVal (panelHandle, PANEL_TEXTMSG_3, requestfield);
			HebrewConverter_convertHebrewISOtoUTF8(requestfield);
			GetCtrlVal (panelHandle, PANEL_TEXTMSG_4, path);
			string=last_request_check(path,soldierfield,mentorfield,requestfield);
			HebrewConverter_convertHebrewUTF8toISO(string);
			SetCtrlVal (panelHandle, PANEL_OUTPUT, string);
			break;
	}
	return 0;
}
