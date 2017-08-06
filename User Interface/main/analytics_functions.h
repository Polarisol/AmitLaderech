#ifndef ANALYTICS_FUNCTIONS.H
#define ANALYTICS_FUNCTIONS.H
#include "HebrewConversions.h"  
typedef struct
{
	int dd;
	int mm;
	int yy;
} Date;
void dateswap(int index,Date *pdate); //utility function for bubble sorting dates
Date *extract_dates(char filename[], char fieldName[], char value[],char DatefieldName[],int *date_array_size); //extracts dates for given name. filename=path, fieldName=column in which the name exists, value= name of the subject, DatefieldName= column in which the date data exists, date_array_size= address to return array size(number of dates extracted). 
Date findmostrecent(Date *datearray,int array_size);// bouble sorts Date type array
int daysbetween(Date givendate); //calculates days between given date and local system time
char **extractnames(char filename[],char fieldName[], int *name_array_size); 
char **removeduplicates (char **org,int org_size,int *sorted_size);
int *extractrecorednum(char filename[], char fieldName[], char value[],int *array_size); //extracts dates for given name. filename=path, fieldName=column in which the name exists, value= name of the subject, DatefieldName= column in which the date data exists, date_array_size= address to return array size(number of dates extracted). 
Date *SpecificDateExtract(char filename[], int *recordarray,int arraysize, char DatefieldName[],int *date_array_size);
char **ExtractSpecificNames(char filename[],int *recordarray,int arraysize, char fieldName[], int *name_array_size); 
char *DateStucToString(Date date);
int *ExtractRecordsWithinRecords(char filename[],int *records,int records_size, char fieldName[], char value[],int *array_size);
char *request_check(char filename[],char soldierfield[],char mentorfield[],char requestfield[],int rec_num);
char *last_request_check(char filename[],char soldierfield[],char mentorfield[],char requestfield[]);
void analysisEx (int panel, char name[]);  
void analysisExSoldier (int panel, char name[]); 
#endif
