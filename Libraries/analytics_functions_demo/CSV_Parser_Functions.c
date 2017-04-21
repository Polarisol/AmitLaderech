#include <ansi_c.h>
int CSVParser_GetNumberOfRecords(char filename[]);
int CSVParser_NewRecords(char filename[]);
void CSVParser_MarkAsProcessed(char filename[], int numberOfNewProcessedRecords);
int CSVParser_GetFieldFromRecord(char filename[], int recordNum, char fieldName[], char value[]);
int CSVParser_CountAllRecordsWithFieldValue(char filename[], char fieldName[], char value[]);
char** CSV_Analyzer(char* runner, int* num_of_values);
char* fgetcsvl(char* line,int MAX_SIZE,FILE *Stream);
void HebrewConverter_convertHebrewUTF8toISO(char original[]);




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
	const int BUFFER_SIZE = 20000;
	char buffer[BUFFER_SIZE];
	int counter=0;
	FILE *Stream;
	

	Stream = fopen (filename, "r");
 
	if(Stream)
	{
		fgetcsvl(buffer, BUFFER_SIZE, Stream); // first line in CSV File is a header so it doesnt count as a record.
		while(fgetcsvl(buffer, BUFFER_SIZE, Stream)!=0)
			counter++;
	}
	
	fclose(Stream);
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
	
	int current_records;
	int new_records;
	int saved_records;
	const int BUFFER_SIZE = 400;				//buffer size 
	char buffer[BUFFER_SIZE];					//line buffer
	char old_filename[BUFFER_SIZE];
	char Set_file[] = "processedRecords.txt";	//path name for the file containing other file name processed data
	FILE *Stream;								//Stream for reading/writing to file

	current_records = CSVParser_GetNumberOfRecords(filename);
	new_records = current_records;
	
	Stream = fopen(Set_file, "r");				//open  Set_file in read mode
	
	//code executed only if file name exist.
	if(Stream != NULL)							
	{
		fgets(buffer, BUFFER_SIZE, Stream);		//first line is a header -- not important
	
		//keep looking for file name in Set_file till we reach end of file
		while(fgets(buffer, BUFFER_SIZE, Stream)!=0)
		{
			sscanf(buffer, "%[^,],%d", old_filename,&saved_records);	//retrieving info to buffer
			
			//if we found desired str (str_cmp_red=0) -> execute code
			if(strcmp(old_filename, filename) == 0)  //comparing str  
				new_records = current_records-saved_records;
		}
	}
	 
	fclose(Stream);		//closing the file.

	return	new_records;
	
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
	int num_of_rec;
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
		fgetcsvl(buffer, BUFFER_SIZE, Stream);		//first line is a header -- not important
	
		//keep looking for file name in Set_file till we reach end of file
		while(fgetcsvl(buffer, BUFFER_SIZE, Stream)!=0)
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
		if(str_cmp_res!=0)
		{
			num_of_rec = CSVParser_GetNumberOfRecords(filename);
			fprintf(Stream,"%s,%d\n",filename,num_of_rec);
		}
		
		fclose(Stream);		//closing the file and saving changes made.         	
	}
	
	free(array);		//releasing dynamic memmory
	
	
}


//Copies the value of a specific field from a specific record into the 'value' string
//Returns 1 if the record and field exists (even if the value is an empty string)
//Returns 0 if there is no such record of field
int CSVParser_GetFieldFromRecord(char filename[], int recordNum, char fieldName[], char value[])
{
	//Writen by Dror Kobo
	
	int LINE_SIZE = 20000;
	FILE *Stream;
	char line[LINE_SIZE];
	char** field_header = NULL;
	char** field_data = NULL;
	int num_of_fields_h;
	int num_of_fields_d;
	int result = 0;
	int record_counter=0;
	int field_index=-1;
	int num_of_records;
	
	Stream = fopen(filename, "r");
	if(Stream)
	{
		num_of_records = CSVParser_GetNumberOfRecords(filename);
		
		if(recordNum>=1 && recordNum<=num_of_records)
		{
			fgetcsvl(line,LINE_SIZE,Stream);
			field_header = CSV_Analyzer(line, &num_of_fields_h);
		
			for(int i=0 ; i<num_of_fields_h ; i++)
			{
				if(strcmp(fieldName,field_header[i])==0)
				{
					field_index=i;
					result = 1;
					break;
				}
			}
		
		
			while(fgetcsvl(line,LINE_SIZE,Stream)!='\0')
			{
				record_counter++;
				if(record_counter==recordNum)
				{
					field_data = CSV_Analyzer(line, &num_of_fields_d);
					
					if(field_index>=0 && value != NULL && field_data != NULL)
						strcpy(value,field_data[field_index]);
				}
				/*
				else if(recordNum==0)
				{
					recordNumber[recordNumber_counter]=record_counter;
					recordNumber_counter++;
				}
				*/
			}
			free(field_header);
			free(field_data);
		}
		fclose(Stream);
	}
	
	return result;
}


//Returns the number of records that have a specific value in a specific field
int CSVParser_CountAllRecordsWithFieldValue(char filename[], char fieldName[], char value[])
{
	//writen by Dror Kobo
	
	int SIZE = 300;
	int total_num_of_records;
	int num_of_records=0;
	int status;
	char buffer[SIZE];
	
	total_num_of_records = CSVParser_GetNumberOfRecords(filename);
	
	status = CSVParser_GetFieldFromRecord(filename, 1, fieldName, buffer);
	if(status>0)
	{
		for(int i=1; i<=total_num_of_records ; i++)
		{
			CSVParser_GetFieldFromRecord(filename, i, fieldName, buffer);
			if(strcmp(value,buffer)==0)
				num_of_records++;
		}
	}
	
	return num_of_records;
}


//Goes over the data and find the first 'number' of records with a specific value in a specific field
//put their record numbers (line numbers) in the 'recordNumbers' array
//put the values of the 'fieldToGet' field (strings) in the 2D array called 'recordValues'
//example: first string value will be in recordValues[0] (the first character will be in recordValues[0][0] second in recordValues[0][1] etc.)
void CSVParser_GetRecordsWithFieldValue(char filename[], char fieldName[], char value[], int number, int recordNumbers[])
{
	
}


char** CSV_Analyzer(char* runner, int* num_of_values)
{
	/*
	Writen by Dror Kobo
	function inputs: 1. address of csv string (char* runner) 2. address of field counter (int* num_of_values) 
	function output: 2d array of field values strings.
	Enjoy.
	*/
	int buffer_size = 300;
	int buf_counter=0;
	int field_size=10;
	int value_length;
	
	*num_of_values=0;
	char* buffer =  calloc(buffer_size, sizeof(char));
	char** pointer =  calloc(field_size,sizeof(char*));
	
	
	while(*runner != '\0') //run on string till it encounter \0
	{
		
		if(*num_of_values==field_size)
		{
			//dynamic memory allocation for pointer
			field_size*=2;
			pointer = realloc(pointer, sizeof(char*)*field_size);
		}
		
		
		if(*runner==',' && *num_of_values==0)
		{
			//found first blank cell
			pointer[*num_of_values] =  malloc(sizeof(char)*2);
			strcpy(pointer[*num_of_values],"0");
			*num_of_values = *num_of_values+1;
			runner++;
		}
		
		
		if(*runner=='"') //dealing with value that padded with "" 
		{
			runner++;
			while(1)
			{
				if(*runner=='"' && *(runner+1)!=',')
					runner++;
				
				if(buf_counter==buffer_size)
				{
					buffer_size*=2;
					buffer = realloc(buffer, sizeof(char)*buffer_size);
				}
				
				buffer[buf_counter]=*runner;
				buf_counter++;
				runner++;
				
				if(*(runner)=='\0')
				{
					buffer[buf_counter]='\0';
					buf_counter = 0;
					
					value_length = strlen(buffer)+1;
					pointer[*num_of_values] = malloc(sizeof(char)*value_length);
					strcpy(pointer[*num_of_values],buffer);
					
					break;					
				}				
				if((*runner=='"' && *(runner+1)==',') || (*runner=='"' && *(runner+1)==10))
				{
					buffer[buf_counter]='\0';
					buf_counter = 0;
					runner = runner+2;
					
					value_length = strlen(buffer)+1;
					pointer[*num_of_values] = malloc(sizeof(char)*value_length);
					strcpy(pointer[*num_of_values],buffer);
					break;
				}
				
			}
		}//  end if(*runner=='"')
		
		else //dealing with normal value 
		{
			while(1)
			{
				if(*runner=='"' && *(runner+1)!=',')
					runner++;
				if(buf_counter==buffer_size)
				{
					buffer_size*=2;
					buffer = realloc(buffer, sizeof(char)*buffer_size);
				}
			
				
				if(*(runner)=='\0')
				{
					buffer[buf_counter]='\0';
					buf_counter = 0;
					
					value_length = strlen(buffer)+1;
					pointer[*num_of_values] = malloc(sizeof(char)*value_length);
					strcpy(pointer[*num_of_values],buffer);
					break;					
				}
				if(*(runner)==',' || *(runner)==10 || *(runner)==13)
				{
					buffer[buf_counter]='\0';
					buf_counter = 0;
					runner++;
					
					value_length = strlen(buffer)+1;
					pointer[*num_of_values] = malloc(sizeof(char)*value_length);
					strcpy(pointer[*num_of_values],buffer);
					break;
				}
				
				buffer[buf_counter]=*runner;
				buf_counter++;
				runner++;
				
			}								
		}// end else 
		*num_of_values = *num_of_values+1;
		
		if(*num_of_values==field_size)
		{
			//dynamic memory allocation for pointer
			field_size*=2;
			pointer = realloc(pointer, sizeof(char*)*field_size);
		}
		
		//new eddition for empty last cells
		if(*runner==',' || *runner==10 || *runner=='\n')
		{
			//found blank cell
			
			pointer[*num_of_values] =  malloc(sizeof(char)*2);
			strcpy(pointer[*num_of_values],"0");
			*num_of_values = *num_of_values+1;
			runner++;
		}

	}// end while(*runner != '\0')
	
	free(buffer);	
	return pointer;
}


char* fgetcsvl(char* line,int MAX_SIZE,FILE *Stream)
{	
	/*
	Written by Dror Kobo 25/01/17
	
	*/
	char buffer[MAX_SIZE];
	char buffer2[MAX_SIZE];
	char* runner = buffer;
	char* result=NULL;
	int numofcom=0;
	
	result = fgets(buffer,MAX_SIZE,Stream);
	while(result!=NULL && *runner!='\0')
	{
		if(*runner=='"') //dealing with value that padded with "" 
		{
			numofcom++;
			runner++;
			while(1)
			{
				if(*runner=='\n')
				{
					while(*runner=='\n' || *buffer2=='\n')
					{
						*runner = ' ';
						runner++;
						result = fgets(buffer2,MAX_SIZE,Stream);
					}
					if(result == NULL) //we reach end of file no need with buffer 2
					{
						strcpy(line,buffer);
						return result;
					}
					else //found more data
					{
						*runner = '\0';
						strcat(buffer,buffer2);	
					}
				}
				
				else if(*runner=='"' && *(runner+1)=='"')//found " -> advancing runner
				{
					runner = runner+2;
					numofcom= numofcom+2;
				}
				
				else if(*runner=='"' && *(runner+1)!='"')//found " -> advancing runner
				{
					numofcom++;
					runner++;
					if(*runner==',' && numofcom%2==0)//end of field
					{
						numofcom=0;
						runner++;
						break;	
					}
					else if(*runner=='\n' && numofcom%2==0)//end of line
					{
						//*runner=' ';
						//runner = runner+2;
						strcpy(line,buffer);
						return line;	
					}
					else if(*runner=='\0') //end of file
					{
						//*(runner+1)=' ';
						//runner = runner+2;
						strcpy(line,buffer);
						return line;	
					}
					
				}
				else //its a valid note that is part of the field
				{
					runner++;	
				}
				
			}//end while (1)
		}//  end if(*runner=='"')
		else // dealling with normal values
		{
			while(1)
			{
				if(*runner==',') //end of field
				{
					runner++;
					break;
				}
				else if(*runner=='\n' || *runner==10 || *runner==12 || *runner==13)// end of a line -> its a csv line
				{
					//*runner=' ';
					strcpy(line,buffer);
					runner++;
					return line;
				}
				else if(*runner=='\0')// end of a line -> its a csv line
				{
					//*runner=' ';
					strcpy(line,buffer);
					return line;
				}
				else //its a valid note
				{
					runner++;	
				}
			}// end while(1) 								
		}// end else
		
		if(*runner==',') //found empty cell
			runner++;
		
	}//end while(result != NULL)
	strcpy(line,buffer);
	return result;	
}//end function
