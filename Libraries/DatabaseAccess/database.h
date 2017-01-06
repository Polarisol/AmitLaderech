//==============================================================================
//									database.h							
//							Header file for the database access
//==============================================================================

#ifndef DATABASE_H
#define DATABASE_H

#include "inifile.h" 
#define SIZE 300



//allows specifying the databases file, it will be saved globally
//to be accessed by other functions
//other functions should check if a database file was defined and not work otherwise
//returns iniHandle if successful, 0 if not 
IniText setDatabaseFile(char name[]);

//changes the value of the provided 'name' to the used database file name.
//the user must make sure an appropriate array is provided
//returns iniHandle if successful, 0 if not
IniText getDatabaseFile(char name[]);

//creates a new empty record (a line in the database, a worker etc.)
//returns 1 if successful, 0 if not 
int addNewRecord(IniText iniHandle,char id[],char * tagName[],int fieldAmount);

//adds a new field (column, like "Cellphone Number") to a specific record
//it is optional to add a value (if 0 is provided than it will be an empty string)
//returns 1 if successful, 0 if not 
int addNewField(IniText iniHandle,char id[], char field[], char value[]);

// sets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
int setFieldVal(IniText iniHandle,char id[], char field[], char value[]);

// gets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
//the user must make sure an appropriate array is provided
int getFieldVal(char id[], char field[], char value[]);

//counts how many records have this value in the specified field 
void getNumberOfIdsFromField(char field[], char value[], int *amount);

//provide a list of all ids with this value in the specified field
//the user must make sure an appropriate array is provided
int getRecordIdsFromField(char field[], char value[], char **ids);

//provides the total amount of records in the database
int countAllRecords(IniText iniHandle);
//provides the total amount of fields in the record
int countAllFields(IniText iniHandle,char id[]);
					 
//checks if the record allready exists
//returns 1 if exists, 0 if not
int recordCheck(IniText iniHandle,char id[]);

//use the ini func ini_numberOfItems
//return ini_numberofItems
int getFieldNum(char id[]);


char* getRecordInfo(IniText iniHandle,char *id,int i);

int createIniFile();

//search id in ini file and put the tagName and tagValue inside an array
//return -1 if not found
int search(IniText iniHandle,char id[], int numOfTags, char ** tagName, char ** tagValue);


#endif

