#include <ansi_c.h>

//Some definitions first: 
//'Record' refers to a specific line in the data (a row)
//'Field' refers to a specific column name (for example 'Age')
//Every record might have values inside the various fields. some fields might be empty
//No function in this library should ever change the files it read (read only!)
//the library should have a utility text file called "processedRecords.txt" in which it keeps
//file names and the number of processed records for each of them.
//all functions should check to see if the file exists before trying to access it

//Returns the number of records in a database
//0 if the file does not exits
int CSVParser_GetNumberOfRecords(char filename[])
{
	/*
	written By Dror Kobo 08/01/17
	this function recieve data base file path name (pointer to string) and returns number of records (lines)
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

//return the number of new records since the file was last marked as 'processed'
//Should refer to the utility file "processedRecords.txt"
//if the file name cannot be found in "processedRecords.txt" the function return the number
//of records in the database
//this function does not update "processedRecords.txt"
int CSVParser_NewRecords(char filename[])
{
	/*
	Written By Dror Kobo 14/01/17
	This function recieve database file name and checks how many records the file have
	then the function check the same database file name in processedRecords file for amount of records
	if their is a match with the name, the function return the difference.
	*/
	
	int records;
	int temp;
	const int BUFFER_SIZE = 400;				//buffer size 
	char buffer[BUFFER_SIZE];					//line buffer
	char old_filename[BUFFER_SIZE];
	char Set_file[] = "processedRecords.txt";	//path name for the file containing other file name processed data
	int str_cmp_res;							//result for strcmp, should be 0 if the file name was found on file
	FILE *Stream;								//Stream for reading/writing to file

	records = CSVParser_GetNumberOfRecords(filename);
	
	Stream = fopen(Set_file, "r");				//open  Set_file in read mode
	
	//code executed only if file name exist.
	if(Stream != NULL)							
	{
		fgets(buffer, BUFFER_SIZE, Stream);		//first line is a header -- not important
	
		//keep looking for file name in Set_file till we reach end of file
		while(fgets(buffer, BUFFER_SIZE, Stream)!=0)
		{
			sscanf(buffer, "%[^,],%d", old_filename,&temp);	//retrieving info to buffer
			str_cmp_res = strcmp(old_filename, filename);				//comparing str
			
			//if we found desired str (str_cmp_red=0) -> execute code
			if(str_cmp_res == 0)
				records = records-temp;
		}
	}
	 
	fclose(Stream);		//closing the file.

	return	records;
	
}


//Adds the 'numberOfNewProcessedRecords' to the previous number in the utility text file "processedRecords.txt"
void CSVParser_MarkAsProcessed(char filename[], int numberOfNewProcessedRecords)
{
	/*
	Written By Dror Kobo 11/01/17
	This function recieve a file name (char filename[]) and a number of new processed records (int numberOfNewProcessedRecords)
	then the function look up for this file name in a file called processedRecords.txt (Set_file[])
	if the function find the file name at that file, she add numberOfNewProcessedRecords to current val associated with it. 
	*/
	char Set_file[] = "processedRecords.txt";	//path name for the file containing other file name processed data
	const int BUFFER_SIZE = 10000;				//buffer size
	const int PATH_SIZE = 400;					//path name size
	int dyn_arr_size = 10;						//dynamic allocation size
	char buffer[BUFFER_SIZE];					//line buffer 
	int str_cmp_res;							//result for strcmp, should be 0 if the file name was found on file
	FILE *Stream;								//Stream for reading/writing to file
	int counter=0;								//index of record
	
	//struct array
	struct temp_arr
	{
		char path[PATH_SIZE];
		int processed;
	}typedef t_arr;
	
	//dynamic allocation
	t_arr *array;
	array = calloc(dyn_arr_size,sizeof(t_arr));
	
	Stream = fopen(Set_file, "r");				//open  Set_file at read mode
	
	//code executed only if file name exist.
	if(Stream != NULL)							
	{
		fgets(buffer, BUFFER_SIZE, Stream);		//first line is a header -- not important
	
		//keep looking for file name in Set_file till we reach end of file
		while(fgets(buffer, BUFFER_SIZE, Stream)!=0)
		{
			
			if(counter == dyn_arr_size) //re allocating dynamic memmory
			{
				dyn_arr_size = 2*dyn_arr_size;
				array = realloc(array,sizeof(t_arr)*dyn_arr_size);
			}
			
			sscanf(buffer, "%[^,],%d", array[counter].path,&array[counter].processed);	//retrieving info to buffer
			str_cmp_res = strcmp(array[counter].path, filename);				//comparing str
			
			//if we found desired str (str_cmp_red=0) -> execute code
			if(str_cmp_res == 0)
				array[counter].processed = array[counter].processed+numberOfNewProcessedRecords;
			
			counter++;	
		}
		
		Stream = freopen(Set_file,"w",Stream);
		fprintf(Stream,"path name,processed\n");
		for(int i=0; i<counter ; i++)
		{
			fprintf(Stream,"%s,%d\n",array[i].path,array[i].processed); 
		}
	}
	fclose(Stream);		//closing the file and saving changes made.
	free(array);		//releasing dynamic memmory
	
	
}


//Copies the value of a specific field from a specific record into the 'value' string
//Returns 1 if the record and field exists (even if the value is an empty string)
//Returns 0 if there is no such record of field
int CSVParser_GetFieldFromRecord(char filename[], int recordNum, char fieldName[], char value[]);


//Returns the number of records that have a specific value in a specific field
int CSVParser_CountAllRecordsWithFieldValue(char filename[], char fieldName[], char value[]);


//Goes over the data and find the first 'number' of records with a specific value in a specific field
//put their record numbers (line numbers) in the 'recordNumbers' array
//put the values of the 'fieldToGet' field (strings) in the 2D array called 'recordValues'
//example: first string value will be in recordValues[0] (the first character will be in recordValues[0][0] second in recordValues[0][1] etc.)
void CSVParser_GetRecordsWithFieldValue(char filename[], char fieldName[], char value[], int number, int recordNumbers[],char fieldToGet[], char **recordValues)
{
	int LINE_SIZE = 300;
	char line[LINE_SIZE];
	char buffer[LINE_SIZE];
	FILE *Stream;
	int buffer_counter;
	int line_counter=0;
	int g_counter=0;
	int start;
	char *token;
	char s[2]=",";
	
	Stream = fopen(filename,"r");
	if(Stream)
	{
		fgets(line,LINE_SIZE,Stream);
		while(fgets(line,LINE_SIZE,Stream)!=0)
		{
			token = strtok(line,s);
			while(token!=NULL)
			{
				token = strtok(NULL,s);
				strcpy(buffer, token);
				
				
			}
			
		}
	}
}
