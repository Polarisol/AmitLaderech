#include <cvirte.h>	
#include <stdio.h>    
#include <userint.h>
#include "analytics_functions_demo.h"
#include "analytics_functions.h"
#define SIZE 300
static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "analytics_functions_demo.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK demo (int panel, int event, void *callbackData,
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

int CVICALLBACK extract (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	char **names=NULL,**sorted=NULL,path[SIZE],name_column[SIZE];
	int array_size;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_PATH, path);
			GetCtrlVal (panelHandle, PANEL_EXTRACT_DATA, name_column);
			names=extractnames(path,name_column, &array_size); 
			sorted=removeduplicates (names,array_size,&array_size);
			DeleteListItem (panelHandle, PANEL_MENTORS, 0, -1);
			for (int i=0;i<array_size;i++)
			{
				HebrewConverter_convertHebrewUTF8toISO(sorted[i]);
				InsertListItem (panelHandle, PANEL_MENTORS, -1, sorted[i],sorted[i]);
			}
			break;
	}
	return 0;
}
