#include <ansi_c.h>
#include <cvirte.h>
#include <stdio.h>
#include <userint.h>
#include "date.h"
#include "Func_Header.h"
#include "HebrewConversions.h"

static int panelHandle;
typedef struct
{
	int dd;
	int mm;
	int yy;
} Date;

Date *datearray=NULL;
int num_dates;

void dateswap(int index,Date *pdate)
{
	Date temp;
	temp=pdate[index];
	pdate[index]=pdate[index+1];
	pdate[index+1]=temp;

}
int extract_dates(char filename[], char fieldName[], char value[],char DatefieldName[])
{
	int SIZE = 300;
	int total_num_of_records;
	int date_array_size=0;
	int status;
	char buffer[SIZE],date[300];
	HebrewConverter_convertHebrewISOtoUTF8(value);
	HebrewConverter_convertHebrewISOtoUTF8(DatefieldName);
	HebrewConverter_convertHebrewISOtoUTF8(fieldName);
	total_num_of_records = CSVParser_GetNumberOfRecords(filename);
	status = CSVParser_GetFieldFromRecord(filename, 1, fieldName, buffer);
	if(status>0)
	{
		for(int i=1; i<=total_num_of_records ; i++)
		{
			CSVParser_GetFieldFromRecord(filename, i, fieldName, buffer);
			if(strcmp(value,buffer)==0)
			{
				date_array_size++;
				CSVParser_GetFieldFromRecord(filename,i,DatefieldName,date);
				datearray = (Date *)realloc(datearray, date_array_size* sizeof(Date));
				sscanf(date,"%d/%d/%d",&datearray[date_array_size-1].dd,&datearray[date_array_size-1].mm,&datearray[date_array_size-1].yy);
				printf("%d|%d|%d\n",datearray[date_array_size-1].dd,datearray[date_array_size-1].mm,datearray[date_array_size-1].yy);
			}
		}
	}

	return date_array_size;
}

Date findmostrecent(Date *array,int array_size)
{
	puts("");
	puts("sorting\n");
	for (int i=0 ; i<array_size; i++)
	{
		for (int j=0; j<array_size-i-1; j++)
		{
			if (datearray[j].yy < datearray[j+1].yy)
				dateswap(j,datearray);
			if (datearray[j].yy == datearray[j+1].yy)
				if (datearray[j].mm < datearray[j+1].mm)
					dateswap(j,datearray);
			if ((datearray[j].mm == datearray[j+1].mm)&&(datearray[j].yy == datearray[j+1].yy))
				if (datearray[j].dd < datearray[j+1].dd)
					dateswap(j,datearray);
		}
	}
	puts("");
	for (int i=0 ; i<array_size; i++)
		printf("%d|%d|%d\n",datearray[i].dd,datearray[i].mm,datearray[i].yy);
	return datearray[0];
}
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "date.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int daysbetween(Date givendate)
{
	struct tm given_tm;
	time_t t;
	time_t tgiven;
	double diff_time;
	int day_diff;
	t = time(NULL);
	given_tm.tm_hour=0;
	given_tm.tm_min=0;
	given_tm.tm_sec=0;
	given_tm.tm_mday=givendate.dd;
	given_tm.tm_mon=givendate.mm-1;
	given_tm.tm_year=givendate.yy-1900;
	tgiven=mktime(&given_tm);
	diff_time=difftime(t,tgiven);
	day_diff=(int)diff_time/86400;
	return day_diff=(int)diff_time/86400;
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
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_PATH, path);
			GetCtrlVal (panelHandle, PANEL_NAME, name);
			GetCtrlVal (panelHandle, PANEL_DATE_COLUMN, datefield);
			GetCtrlVal (panelHandle, PANEL_NAMECOLM, namefield);
			num_dates=extract_dates(path, namefield, name,datefield);
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
			break;
	}
	return 0;
}

/*int CVICALLBACK compare (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	struct tm system_tm;
	struct tm given_tm;
	time_t t,tt;
	time_t tg;
	Date sysdate;
	Date givendate;
	double diff_time;
	int day_diff;
	switch (event)
	{
		case EVENT_COMMIT:
			t = time(NULL);
			system_tm = *localtime(&t);
			sysdate.yy=system_tm.tm_year + 1900;
			sysdate.mm= system_tm.tm_mon + 1;
			sysdate.dd= system_tm.tm_mday;
			printf("%d / %d / %d\n",sysdate.dd,sysdate.mm,sysdate.yy);
			givendate.dd=10;
			givendate.mm=2;
			givendate.yy=2017;
			given_tm.tm_hour=0;
			given_tm.tm_min=0;
			given_tm.tm_sec=0;
			given_tm.tm_mday=givendate.dd;
			given_tm.tm_mon=givendate.mm-1;
			given_tm.tm_year=givendate.yy-1900;
			tg=mktime(&given_tm);
			diff_time=difftime(t,tg);
			day_diff=(int)diff_time/86400;
			printf("%f\n%d",diff_time,day_diff);
			break;
	}
	return 0;
}  */

