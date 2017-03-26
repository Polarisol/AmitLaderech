#include <ansi_c.h>
#include <cvirte.h>
#include <stdio.h>
#include <userint.h>
#include "date.h"
#include "analytics_functions.h"

int panelHandle;
int num_dates;
Date *datearray=NULL;
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "date.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	free(datearray);
	return 0;
}

int CVICALLBACK mainfunc (int panel, int event, void *callbackData,
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
	char path[300];
	char name[300];
	char namefield[300];
	char datefield[300];
	int *records=NULL,array_size;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_PATH, path);
			GetCtrlVal (panelHandle, PANEL_NAME, name);
			GetCtrlVal (panelHandle, PANEL_DATE_COLUMN, datefield);
			GetCtrlVal (panelHandle, PANEL_NAMECOLM, namefield);
			datearray=extract_dates(path, namefield, name,datefield, &num_dates);
			for (int i=0; i< num_dates; i++)
				printf("%d|%d|%d\n",(datearray[i]).dd,(datearray[i]).mm,(datearray[i]).yy);
			records=extractrecorednum(path,namefield, name,&array_size);
			for (int i=0;i<array_size;i++)
				printf("record num - %d\n",records[i]);
			break;
	}
	return 0;
}

int CVICALLBACK find_recent (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	Date most_resent;
	char lastdate[200];
	int days;
	switch (event)
	{
		case EVENT_COMMIT:
			most_resent=findmostrecent(datearray,num_dates);
			days=daysbetween(most_resent);
			sprintf (lastdate,"%d/%d/%d\ndays passed - %d",most_resent.dd,most_resent.mm,most_resent.yy,days);
			MessagePopup ("Most Recent",lastdate);
			puts("");
			puts("sorted date array");
			puts("");
			for (int i=0 ; i<num_dates; i++)
				printf("%d|%d|%d\n",datearray[i].dd,datearray[i].mm,datearray[i].yy);
			break;
	}
	return 0;
}

int CVICALLBACK extract_arrayname (int panel, int control, int event,
								   void *callbackData, int eventData1, int eventData2)
{
	char **name_array=NULL,**sorted=NULL;
	char path[300],name_colm[300];
	int name_array_size=0,sorted_size=0;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_PATH, path);
			GetCtrlVal (panelHandle, PANEL_RING, name_colm);
			name_array=extractnames(path,name_colm,&name_array_size);
			for (int i=0 ; i<name_array_size ; i++)
				printf("%s\n",name_array[i]);
			sorted=removeduplicates (name_array,name_array_size,&sorted_size);
			printf("sorting\n\n");
			DeleteTextBoxLines (panelHandle, PANEL_TEXTBOX, 0, -1);
			for (int i=0 ; i<sorted_size ; i++)
			{
				printf("%s\n",sorted[i]);
				HebrewConverter_convertHebrewUTF8toISO(sorted[i]);
				InsertTextBoxLine (panelHandle, PANEL_TEXTBOX,-1 ,sorted[i] );
			}
			free(name_array);
			free(sorted);
			break;
	}
	return 0;
}
