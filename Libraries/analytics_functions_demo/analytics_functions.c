#include <ansi_c.h>
#include <stdio.h>
#include <userint.h>
#include "Func_Header.h"
#include "HebrewConversions.h"
#include "analytics_functions.h"
#define SIZE 300
void dateswap(int index,Date *pdate)
{
	Date temp;
	temp=pdate[index];
	pdate[index]=pdate[index+1];
	pdate[index+1]=temp;

}

Date *extract_dates(char filename[], char fieldName[], char value[],char DatefieldName[],int *date_array_size)
{
	int total_num_of_records;
	Date *datearray=NULL;
	int status;			    
	char buffer[SIZE],date[SIZE];
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
				CSVParser_GetFieldFromRecord(filename,i,DatefieldName,date);
				if (strlen(date)>2)
				{
					(*date_array_size)++;
					datearray = (Date *)realloc(datearray, *date_array_size* sizeof(Date));
					sscanf(date,"%d/%d/%d",&(datearray[*date_array_size-1]).dd,&(datearray[*date_array_size-1]).mm,&(datearray[*date_array_size-1]).yy);
				}
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



char **extractnames(char filename[],char fieldName[], int *name_array_size)
{
	int total_num_of_records;
	char **namearray=NULL;
	int status;
	char name[SIZE];
	*name_array_size=0;
	HebrewConverter_convertHebrewISOtoUTF8(fieldName);
	total_num_of_records = CSVParser_GetNumberOfRecords(filename);
	status = CSVParser_GetFieldFromRecord(filename, 1, fieldName, name);
	if(status>0)
	{
		namearray = (char**)malloc(total_num_of_records * sizeof(char *));
		for(int i=1; i<=total_num_of_records ; i++)
		{
			CSVParser_GetFieldFromRecord(filename, i, fieldName, name);
			{
				(*name_array_size)++;
				CSVParser_GetFieldFromRecord(filename,i,fieldName,name);
				namearray[i-1] = (char *)malloc(strlen(name)+1);
				strcpy(namearray[i-1], name);;
			}
		}
	}
	return namearray;
}

char **removeduplicates (char **org,int org_size,int *sorted_size)
{
	char **sortedarray=NULL;
	*sorted_size=0;
	for (int i=0; i<org_size; i++)
	{
		for (int j=0; j<=*sorted_size; j++)
		{
			if(j==*sorted_size)
			{
				sortedarray = (char**)realloc(sortedarray,(*sorted_size+1) * sizeof(char *));
				sortedarray[*sorted_size] = (char *)malloc(strlen(org[i])+1);
				strcpy(sortedarray[*sorted_size],org[i]);
				(*sorted_size)++;
				break;
			}
			else
			{
				if(strcmp(sortedarray[j],org[i])==0)
					break;
			}
		}
	}
	return sortedarray;
}




int *extractrecorednum(char filename[], char fieldName[], char value[],int *array_size)
{
	int total_num_of_records;
	int *recordarray=NULL;
	int status;
	int j=0;
	char buffer[SIZE];
	*array_size=0;
	HebrewConverter_convertHebrewISOtoUTF8(value);
	HebrewConverter_convertHebrewISOtoUTF8(fieldName);
	total_num_of_records = CSVParser_GetNumberOfRecords(filename);
	status = CSVParser_GetFieldFromRecord(filename, 1, fieldName, buffer);
	if(status>0)
	{
		*array_size=CSVParser_CountAllRecordsWithFieldValue(filename,fieldName,value);
		recordarray = (int *)malloc(*array_size* sizeof(int));
		for(int i=1; i<=total_num_of_records ; i++)
		{
			CSVParser_GetFieldFromRecord(filename, i, fieldName, buffer);
			if(strcmp(value,buffer)==0)
			{
				recordarray[j]=i;
				j++;
			}
		}
	}
	return recordarray;
}



Date *SpecificDateExtract(char filename[], int *recordarray,int arraysize, char DatefieldName[],int *date_array_size)
{
	Date *datearray=NULL;
	int status;
	char buffer[SIZE],date[SIZE];
	*date_array_size=0;
	HebrewConverter_convertHebrewISOtoUTF8(DatefieldName);
	status = CSVParser_GetFieldFromRecord(filename, 1, DatefieldName, buffer);
	*date_array_size=0;
	if(status>0)
	{
		for(int i=0; i<arraysize ; i++)
		{
			CSVParser_GetFieldFromRecord(filename,recordarray[i],DatefieldName,date);
			if (strlen(date)>1)
			{
				(*date_array_size)++;
				datearray = (Date *)realloc(datearray, *date_array_size* sizeof(Date));
				sscanf(date,"%d/%d/%d",&(datearray[*date_array_size-1]).dd,&(datearray[*date_array_size-1]).mm,&(datearray[*date_array_size-1]).yy);
				//printf("%d|%d|%d\n",datearray[*date_array_size-1].dd,datearray[*date_array_size-1].mm,datearray[*date_array_size-1].yy);
			}
		}
	}
	//printf("size=%d\n",*date_array_size);
	return datearray;
}



char **ExtractSpecificNames(char filename[],int *recordarray,int arraysize, char fieldName[], int *name_array_size)
{
	char **namearray=NULL;
	int status;
	char name[SIZE];
	*name_array_size=0;
	HebrewConverter_convertHebrewISOtoUTF8(fieldName);
	status = CSVParser_GetFieldFromRecord(filename, 1, fieldName, name);
	if(status>0)
	{
		namearray = (char**)malloc(arraysize * sizeof(char *));
		for(int i=0; i<arraysize ; i++)
		{
			CSVParser_GetFieldFromRecord(filename,recordarray[i], fieldName, name);
			{
				(*name_array_size)++;
				CSVParser_GetFieldFromRecord(filename,recordarray[i],fieldName,name);
				namearray[i] = (char *)malloc(strlen(name)+1);
				strcpy(namearray[i], name);
			}
		}
	}
	return namearray;
}


char *DateStucToString(Date date)
{
	char fullstring[200]= {0};
	char *string=NULL;
	sprintf(fullstring,"%d/%d/%d",date.dd,date.mm,date.yy);
	string=(char *)malloc(strlen(fullstring)+1);
	strcpy(string,fullstring);
	return string;
}



int *ExtractRecordsWithinRecords(char filename[],int *records,int records_size, char fieldName[], char value[],int *array_size)
{
	int *recordarray=NULL;
	int status;
	char buffer[SIZE];
	int j=0;
	(*array_size)=0;
	HebrewConverter_convertHebrewISOtoUTF8(value);
	HebrewConverter_convertHebrewISOtoUTF8(fieldName);
	status = CSVParser_GetFieldFromRecord(filename, 1, fieldName, buffer);
	if(status>0)
	{
		*array_size=CSVParser_CountAllRecordsWithFieldValue(filename,fieldName,value);
		recordarray = (int *)malloc(*array_size* sizeof(int));
		for(int i=0; i<records_size ; i++)
		{
			CSVParser_GetFieldFromRecord(filename, records[i], fieldName, buffer);
			if(strcmp(value,buffer)==0)
			{
				recordarray[j]=records[i];
				//printf("recordarray[%d]=%d\n",j,recordarray[j]);
				j++;

			}
		}
	}
	//printf("\nj=%d,RRsize=%d\n",j,*array_size);
	(*array_size)=j;
	return recordarray;
}



char *request_check(char filename[],char soldierfield[],char mentorfield[],char requestfield[],int rec_num)
{
	char value[3][5*SIZE],buffer[3*SIZE];
	CSVParser_GetFieldFromRecord(filename,rec_num, requestfield, buffer);
	if (strlen(buffer)>3)
	{
		strcpy(value[0],buffer);
		CSVParser_GetFieldFromRecord(filename,rec_num, soldierfield, value[1]);
		CSVParser_GetFieldFromRecord(filename,rec_num, mentorfield, value[2]);
		sprintf(buffer,"mentor:%s ,soldier:%s, request:%s",value[2],value[1],value[0]);
		return buffer;
	}
	else
	{
		strcpy(buffer,"-1");
		return buffer;
	}
}

char *last_request_check(char filename[],char soldierfield[],char mentorfield[],char requestfield[])
{
	char value[3][5*SIZE],buffer[3*SIZE];
	int rec_num;
	if (CSVParser_NewRecords(filename))
	{
		rec_num=CSVParser_GetNumberOfRecords(filename);
		CSVParser_GetFieldFromRecord(filename,rec_num, requestfield, buffer);
		if (strlen(buffer)>3)
		{
			strcpy(value[0],buffer);
			CSVParser_GetFieldFromRecord(filename,rec_num, soldierfield, value[1]);
			CSVParser_GetFieldFromRecord(filename,rec_num, mentorfield, value[2]);
			sprintf(buffer,"mentor:%s ,soldier:%s, request:%s",value[2],value[1],value[0]);
			//CSVParser_MarkAsProcessed(filename,1);//this function crashes the program,also the bug regarding extracting data from last record persists, thats why -1 is returned. to return value for illustration subtract 2 from rec_num.
			return buffer;
		}
		else
		{
			strcpy(buffer,"-1");
			return buffer;
		}

	}
	else
	{
		strcpy(buffer,"-1");
		return buffer;
	}

}

