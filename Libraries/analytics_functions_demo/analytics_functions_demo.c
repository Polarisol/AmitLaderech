#include <ansi_c.h>
#include <cvirte.h>
#include <stdio.h>
#include <userint.h>
#include "analytics_functions_demo.h"
#include "analytics_functions.h"
#define SIZE 300
static int panelHandle;
int selection;

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
			GetCtrlIndex (panelHandle, PANEL_EXTRACT_DATA,&selection );
			if (selection)
				names=extractnames(path,mentor_colm, &array_size);
			else
				names=extractnames(path,soldier_colm, &array_size);
			sorted=removeduplicates (names,array_size,&array_size);
			DeleteListItem (panelHandle, PANEL_MENTORS, 0, -1);
			for (int i=0; i<array_size; i++)
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
	int *records=NULL,*recordswithin=NULL,array_size,sorted_array_size;
	int name_array_size,RRarray_size;
	char subject[SIZE],string[SIZE],*datestring=NULL;
	char **names=NULL,**sorted=NULL;
	Date *dates=NULL,date,*dates_sp=NULL;
	int date_array_size,day_passed;
	char *date_string=NULL;
	char men[]="mentor",sol[]="soldier";
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			GetCtrlVal (panelHandle, PANEL_MENTORS, subject);
			if (selection)
				records=extractrecorednum(path,mentor_colm,subject,&array_size);
			else
				records=extractrecorednum(path,soldier_colm,subject,&array_size);
			dates=SpecificDateExtract(path,records,array_size,date_colm,&date_array_size);
			if (!date_array_size)
				break;
			date=findmostrecent(dates,date_array_size);
			day_passed=daysbetween(date);
			datestring=DateStucToString(date);
			if (selection)
				sprintf(string,"Total meetings for %s = %d",men,date_array_size);
			else
				sprintf(string,"Total meetings for %s = %d",sol,date_array_size);
			SetCtrlVal (panelHandle,PANEL_TOTAL_MEETINGS,string);
			if (selection)
				names=ExtractSpecificNames(path,records,array_size,soldier_colm,&name_array_size);
			else
				names=ExtractSpecificNames(path,records,array_size,mentor_colm,&name_array_size);
			sorted=removeduplicates (names,array_size,&sorted_array_size);
			if (selection)
				sprintf(string,"Total %s for %s = %d",sol,men,sorted_array_size);
			else
				sprintf(string,"Total %s for %s = %d",men,sol,sorted_array_size);
			SetCtrlVal (panelHandle, PANEL_TOTAL_SUBJECTS,string);
			sprintf(string,"Last meeting was on %s ,days passed since = %d",datestring,day_passed);
			SetCtrlVal (panelHandle, PANEL_LAST_MEETING,string);
			names=NULL;
			if (selection)
				names=ExtractSpecificNames(path,records,array_size, soldier_colm, &name_array_size);
			else
				names=ExtractSpecificNames(path,records,array_size, mentor_colm, &name_array_size);
			sorted=NULL;
			sorted=removeduplicates (names,name_array_size,&sorted_array_size);
			for (int i=0; i<sorted_array_size; i++)
			{
				if (selection)
					recordswithin=ExtractRecordsWithinRecords(path,records,array_size,soldier_colm,sorted[i],&RRarray_size);
				else
					recordswithin=ExtractRecordsWithinRecords(path,records,array_size,mentor_colm,sorted[i],&RRarray_size);
				HebrewConverter_convertHebrewUTF8toISO(sorted[i]);
				SetTableCellVal (panelHandle, PANEL_TABLE, MakePoint(1,i+1),sorted[i] );
				dates_sp=SpecificDateExtract(path, recordswithin,RRarray_size,date_colm,&date_array_size);
				if (date_array_size)
				{
					date=findmostrecent(dates_sp,date_array_size);
					date_string=DateStucToString(date);
					SetTableCellVal (panelHandle, PANEL_TABLE, MakePoint(2,i+1),date_string);
					SetTableCellVal (panelHandle, PANEL_TABLE, MakePoint(3,i+1),daysbetween(date));
				}
				SetTableCellVal (panelHandle, PANEL_TABLE, MakePoint(4,i+1),date_array_size );
			}
			break;
	}
	return 0;
}
