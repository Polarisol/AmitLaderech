//==============================================================================
//									database.h							
//							Header file for the database access
//==============================================================================

#ifndef DATABASE_H
#define DATABASE_H

#include <ansi_c.h>
#include "HebrewConversions.h" 
#include "inifile.h" 
#define SIZE 300



//allows specifying the databases file, it will be saved globally
//to be accessed by other functions
//other functions should check if a database file was defined and not work otherwise
//returns iniHandle if successful, 0 if not 
int Database_SetDatabaseFile(char name[]);

//changes the value of the provided 'name' to the used database file name.
//the user must make sure an appropriate array is provided
//returns iniHandle if successful, 0 if not
int Database_GetDatabaseFile(char name[]);

//creates a new empty record (a line in the database, a worker etc.)
//returns 1 if successful, 0 if not 
int Database_AddNewRecord(char id[],char * tagName[],int fieldAmount);

//adds a new field (column, like "Cellphone Number") to a specific record
//it is optional to add a value (if 0 is provided than it will be an empty string)
//returns 1 if successful, 0 if not 
int Database_AddNewField(char id[], char field[], char value[]);

//add a new field to all the records in the database.
int Database_AddNewFieldAll(char field[],char value[]);

// sets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
int Database_SetFieldVal(char id[], char field[], char value[]);

// gets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
//the user must make sure an appropriate array is provided
int Database_GetFieldVal(char id[], char field[], char value[]);

//counts how many records have this value in the specified field 
void Database_GetNumberOfIdsFromField(char field[], char value[], int *count);

//provide a list of all ids with this value in the specified field
//the user must make sure an appropriate array is provided
int Database_GetRecordIdsFromField(char field[], char value[], char **ids);

//provides the total amount of records in the database
int Database_CountAllRecords(int *amout);

//provides the total amount of fields in the record
int Database_CountAllFields(char id[], int *amount);
					 
//checks if the record allready exists
//returns 1 if exists, 0 if not
int Database_RecordCheck(char id[]);

//get record name from the index provided.
//when called use the following:
//sprintf(id,"%s",getRecordInfo(iniHandle,id,i));
int Database_GetRecordInfo(char *id,int i);

//search id in ini file and put the tagName and tagValue inside an array
//return -1 if not found
int Database_GetRecordValues(char id[], int numOfTags, char ** tagName, char ** tagValue);

//remove record from db file.
//return 1 if successful, 0 if record does no exist
int Database_RemoveRecord(char id[]);

//set the values that partially include tag string in output array
//return the number of elements in output
int Database_GetAutofill(int amount, char *tag,char **output);

#endif

