#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Functions.h"

#include "Func_Header.h"


static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Functions.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK exitFunc (int panel, int event, void *callbackData,
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

int CVICALLBACK check (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	char file_name[300];
	int num;
	int status;
				
	switch (event)
	{
		case EVENT_COMMIT:
			
				status = FileSelectPopup ("", "*.*", "", "", VAL_LOAD_BUTTON, 0, 0, 1, 0, file_name);

					num = CSVParser_GetNumberOfRecords(file_name);
					SetCtrlVal (panelHandle, PANEL_NUMERIC, num);
				
		break;
	}
	return 0;
}

int CVICALLBACK add (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	char file_name[100];
	int num = 5000;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panelHandle,PANEL_STRING, file_name);
			CSVParser_MarkAsProcessed(file_name,num);
			
			break;
	}
	return 0;
}
