
//==============================================================================
//									database.c							
//							database function file.
//
//									Variables
//						//dbFile - database file FULL path
//==============================================================================

 
#include "database.h"



static IniText iniHandle;
static char *dbFile;
static char *tagName[SIZE],*tagValue[SIZE];
FILE *fp;



//allows specifying the databases file, it will be saved globally
//to be accessed by other functions
//other functions should check if a database file was defined and not work otherwise
//returns 1 if successful, 0 if not 
int Database_SetDatabaseFile(char name[])
{
	
	if(strstr(name,".ini"))
	{
		dbFile = malloc(sizeof(char)*strlen(name)+1);
		sprintf(dbFile,"%s",name);
		iniHandle = Ini_New (0);
		Ini_ReadFromFile (iniHandle, dbFile);
		return 1;
	}
	else
		return 0;
}

//changes the value of the provided 'name' to the used database file name.
//the user must make sure an appropriate array is provided
//returns iniHandle if successful, 0 if not
int Database_GetDatabaseFile(char name[])
{
	
	if(dbFile != NULL)
	{
		sprintf(name,"%s",dbFile);
		return 1;
	}
	else
		return 0;
}

//creates a new empty record (a line in the database, a worker etc.)
//returns 1 if successful, 0 if not 
int Database_AddNewRecord(char id[],char * tagName[],int fieldAmount)
{   
	int val = Database_RecordCheck(id);
	if(val==1)
		return 0;
	for(int i=0;i<fieldAmount;i++)
	{
		Ini_PutRawString (iniHandle,id, tagName[i], tagName[i]);	
	}
	Ini_WriteToFile (iniHandle,dbFile);
	return 1;
}

//remove record from db file.
//return 1 if successful, 0 if record does no exist
int Database_RemoveRecord(char id[])
{
	if(Ini_RemoveSection (iniHandle, id)==0)
		return 0;
	else
		Ini_WriteToFile (iniHandle, dbFile);
	return 1;
}


//search for the ID in database.create arrays for name value.
//return -1 if ID is not in the db
int Database_GetRecordValues(char id[], int numOfTags, char * tagName[], char * tagValue[])
{
	int val = Database_RecordCheck (id);
	if(val==0)
		return -1;
	for(int i=0;i<numOfTags;i++)
	{
		
		Ini_NthItemName (iniHandle, id, i+1, &tagName[i]);
		HebrewConverter_convertHebrewUTF8toISO(tagName[i]);
		Ini_GetPointerToRawString (iniHandle, id, tagName[i], &tagValue[i]);
		HebrewConverter_convertHebrewUTF8toISO(tagValue[i]);
	}
		
	return 1;
}

//check if the record exist in the db.
//if not return 0
int Database_RecordCheck(char id[])
{
	if(Ini_SectionExists (iniHandle, id)==0)//not exist
		return 0;
	return 1;

}

//return the amount of records in the db.
int Database_CountAllRecords(int *amount)
{
	if(dbFile !=NULL)
	{
		*amount = Ini_NumberOfSections (iniHandle);
		return 1;
	}
	else
		return 0;
}

//return the amount of fields in a record
int Database_CountAllFields(char id[],int *amount)
{
	if(dbFile !=NULL)
	{
		*amount = Ini_NumberOfItems (iniHandle, id);
		return 1;
	}
	else
		return 0;
}

//get record name from the index provided.
//when called use the following:
//sprintf(id,"%s",getRecordInfo(iniHandle,id,i));
char* Database_GetRecordInfo(char *id,int i)
{
	//char** id2 = "0"; 
	Ini_NthSectionName (iniHandle, i, &id);//id2);
	//sprintf(id,"%s",id2[0]);
	//return 0;
	return id;
}


// sets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
int Database_SetFieldVal(char id[], char field[], char value[])
{
	if(field != NULL && value != NULL && dbFile != NULL)
	{
		Ini_PutRawString (iniHandle, id, field, value);
		Ini_WriteToFile (iniHandle, dbFile);
	return 1;
	}
	return 0;
}

//return the index of the field in the iniText
//if the field does not exist return -1
static int Database_GetIndexofField(char id[],char field[])
{
	if(Database_RecordCheck(id)!=0) 
	{			  
		int fieldAmount;
		 Database_CountAllFields(id,&fieldAmount);
		 for(int i=1;i<=fieldAmount;i++) 
		 {
			if(!strcmp(tagName[i-1],field))
			{
				return (i-1);
			}
		 }
		 
	} 
	 return -1;
}

// gets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
//the user must make sure an appropriate array is provided
int Database_GetFieldVal(char id[], char field[], char value[])
{
	if(Database_RecordCheck(id)!=0)
	{
		Ini_GetRawStringIntoBuffer (iniHandle, id, field, value, SIZE);
	}
	return 0;
}

//Compare the value recived to the value of the specific field and record.
//return 1 if equal. 0 if not.
static int Database_CmpGetFieldVal(char id[], char field[], char value[])
{
	int i;
	if(Database_RecordCheck(id)!=0)
	{
		int fieldAmount;
		Database_CountAllFields(id,&fieldAmount);
		Database_GetRecordValues(id,fieldAmount,tagName,tagValue);
		i = Database_GetIndexofField(id,field);
		if(i!=-1)
		{
				if(!strcmp(tagValue[i],value))
					return 1;
		}
	}
	return 0;
}

//counts how many records have this value in the specified field 
void Database_GetNumberOfIdsFromField(char field[], char value[], int *count)
{
	int amount;
	char id[SIZE];
	Database_CountAllRecords(&amount);
	for(int i=1;i<=amount;i++)
	{
		sprintf(id,"%s",Database_GetRecordInfo(id,i));
		if(Database_CmpGetFieldVal(id,field,value)==1)
		{
			(*count)++;
		}
	}
}							

//provide a list of all ids with this value in the specified field
//the user must make sure an appropriate array is provided
char** Database_GetRecordIdsFromField(char field[], char value[], char **ids)
{
	int amount;
	int count =0;
	char id[SIZE];
	Database_CountAllRecords(&amount);
	for(int i=1;i<=amount;i++)
	{
		sprintf(id,"%s",Database_GetRecordInfo(id,i));
		if(Database_CmpGetFieldVal(id,field,value)==1)
		{
			ids[count] = malloc(sizeof(char)*(strlen(id)+1));
			sprintf(ids[count],"%s",id);
			count++;
		}
	}
	return ids;
}

//work in progress
int Database_GetAutofill(int amount, char *tag,char **output)
{
	char **lib;
	int i,j=0;
	int a ;
	Database_CountAllRecords(&a);
	lib = malloc(sizeof(char*)*a);
	for(int i=0;i<a;i++)
	{
		Ini_NthSectionName (iniHandle,i+1, &lib[i]);
	}
	for(i=0;i<amount;i++)
	{
		
		if(strstr(lib[i],tag)!=NULL)
		{
			if(lib[i][0] == tag[0])
			{
			output[j] = malloc(sizeof(char*)*SIZE);
			sprintf(output[j],"%s",lib[i]);
			j++;
			}
		}
	}
	
	return j;
	
}

