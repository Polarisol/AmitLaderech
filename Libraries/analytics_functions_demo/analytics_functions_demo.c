#include <cvirte.h>	
#include <stdio.h>    
#include <userint.h>
#include "analytics_functions_demo.h"
#include "analytics_functions.h"
#define SIZE 300
static int panelHandle;


char path[SIZE],mentor_colm[SIZE],soldier_colm[SIZE],date_colm[SIZE];
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
	char **names=NULL,**sorted=NULL;
	int array_size;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_PATH, path);
			GetCtrlVal (panelHandle, PANEL_DATE_COLM, date_colm);
			GetValueFromIndex (panelHandle, PANEL_EXTRACT_DATA, 0, soldier_colm);
			GetValueFromIndex (panelHandle, PANEL_EXTRACT_DATA, 1, mentor_colm);
			names=extractnames(path,mentor_colm, &array_size); 
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

int CVICALLBACK analysis (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	int *records=NULL,array_size;
	int name_array_size;
	char mentor[SIZE],string[SIZE],*datestring=NULL;
	char **names=NULL,**sorted=NULL;
	Date *dates=NULL,date;
	int date_array_size,day_passed;
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			GetCtrlVal (panelHandle, PANEL_MENTORS, mentor);
			records=extractrecorednum(path,mentor_colm,mentor,&array_size);
			dates=SpecificDateExtract(path, records,array_size, date_colm, &date_array_size);
			date=findmostrecent(dates,date_array_size);
			day_passed=daysbetween(date);
			datestring=DateStucToString(date); 
			sprintf(string,"Total meeting for mentor = %d",date_array_size);
			SetCtrlVal (panelHandle, PANEL_TOTAL_MEETINGS,string);
			names=ExtractSpecificNames(path,records,array_size,soldier_colm,&name_array_size); 
			sorted=removeduplicates (names,array_size,&array_size);
			sprintf(string,"Total soldiers for mentor = %d",array_size);
			SetCtrlVal (panelHandle, PANEL_TOTAL_SUBJECTS,string);
			sprintf(string,"Last meeting was on %s ,days passed since = %d",datestring,day_passed);
			SetCtrlVal (panelHandle, PANEL_LAST_MEETING,string);
			break;
	}
	return 0;
}
