#ifndef DATAFUNCTION.H
#define DATAFUNCTION.H
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
#endif
