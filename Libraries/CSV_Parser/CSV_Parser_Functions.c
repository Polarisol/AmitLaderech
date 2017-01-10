#include <ansi_c.h>
int CSVParser_GetNumberOfRecords(char filename[])
{
	/*
	written By Dror Kobo 08/01/16
	this function recieves file path name (pointer to string) and returns number of records (lines)
	if the function recieves invalid file path name it returns 0;
	*/
	const int BUFFER_SIZE = 10000;
	char buffer[BUFFER_SIZE];
	int counter=0;
	FILE *Stream;

	Stream = fopen (filename, "r");
 
	if(Stream)
	{
		fgets(buffer, BUFFER_SIZE, Stream); // first line in CSV File is a header so it doesnt count as a record.
		while(fgets(buffer, BUFFER_SIZE, Stream)!=0)
			counter++;
	}

	return counter;
}
