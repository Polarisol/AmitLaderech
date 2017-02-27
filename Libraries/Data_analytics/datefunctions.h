#include <ansi_c.h>
#include <stdio.h>
#include <userint.h>
#include "Func_Header.h"
#include "HebrewConversions.h"
 
typedef struct
{
	int dd;
	int mm;
	int yy;
} Date;

void dateswap(int index,Date *pdate)
{
	Date temp;
	temp=pdate[index];
	pdate[index]=pdate[index+1];
	pdate[index+1]=temp;

}
Date *extract_dates(char filename[], char fieldName[], char value[],char DatefieldName[],int *date_array_size)
{
	int SIZE = 300;
	int total_num_of_records;
	Date *datearray=NULL;
	int status;
	char buffer[SIZE],date[300];
	*date_array_size=0;
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
				(*date_array_size)++;
				CSVParser_GetFieldFromRecord(filename,i,DatefieldName,date);
				datearray = (Date *)realloc(datearray, *date_array_size* sizeof(Date));
				sscanf(date,"%d/%d/%d",&(datearray[*date_array_size-1]).dd,&(datearray[*date_array_size-1]).mm,&(datearray[*date_array_size-1]).yy);
			}
		}
	}

	return datearray;
}

Date findmostrecent(Date *datearray,int array_size)
{
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
	return datearray[0];
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

