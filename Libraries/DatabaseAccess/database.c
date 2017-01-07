//==============================================================================
//									database.c							
//							database function file.
//
//									Variables
//						//dbFile - database file path.
//==============================================================================

#include <ansi_c.h>
#include "inifile.h"
#include "HebrewConversions.h" 
#include "database.h"

static IniText iniHandle;
static char dbFile[SIZE];
FILE *fp;

//creates a new empty record (a line in the database, a worker etc.)
//returns 1 if successful, 0 if not 
int addNewRecord(IniText iniHandle,char id[],char * tagName[],int fieldAmount)
{   
	int val = recordCheck(iniHandle,id);
	if(val==1)
		return 0;
	for(int i=0;i<fieldAmount;i++)
	{
		Ini_PutRawString (iniHandle, id, tagName[i], tagName[i]);	
	}
	Ini_WriteToFile (iniHandle, dbFile);
	return 1;
}
//allows specifying the databases file, it will be saved globally
//to be accessed by other functions
//other functions should check if a database file was defined and not work otherwise
//returns 1 if successful, 0 if not 
IniText setDatabaseFile(char name[])
{
	char path[SIZE];
	if(strcmp (name, ""))
	{
		sprintf (path, "Database\\%s.ini", name);
		fp = fopen (path, "w");
		fclose(fp);
		iniHandle = getDatabaseFile(path);
		return iniHandle;
	}
	
	return 0;	
}

//changes the value of the provided 'name' to the used database file name.
//the user must make sure an appropriate array is provided
//returns iniHandle if successful, 0 if not
IniText getDatabaseFile(char name[])
{
	char file[SIZE];
	char path[SIZE];
	/*if(strstr(name,".ini") == NULL)
	{
		  sprintf(file,"%s.ini",name);
		  name = file;
	} */
	GetFirstFile ("Database\\*.ini", 1, 0, 0, 0, 0, 0, file);//file = *.ini
	if(strcmp (file, ""))
	{
		if(!strcmp (file, name))
		{
			sprintf (path, "Database\\%s", name);
			strcpy (dbFile, path);
			iniHandle = Ini_New (0);
			Ini_ReadFromFile (iniHandle, dbFile);
			return iniHandle;
		}
		while (!GetNextFile (file))
		{
			if(!strcmp (file, name))
			{
				sprintf (path, "Database\\%s", name);
				strcpy (dbFile, path);
				iniHandle = Ini_New (0);
				Ini_ReadFromFile (iniHandle, dbFile);
				return iniHandle;
			}
		}
	}
	return 0;
}



int createIniFile()
{
	iniHandle = Ini_New (1);
	Ini_ReadFromFile (iniHandle, dbFile);
	Ini_PutString (iniHandle, "203059936", "last name", "gazit2");
	Ini_WriteToFile (iniHandle, dbFile);
	
	return 1;
	
}


//search for the ID in database.create arrays for name value.
//return -1 if ID is not in the db
int search(IniText iniHandle,char id[], int numOfTags, char * tagName[], char * tagValue[])
{
	int val = recordCheck (iniHandle, id);
	if(val==-1)
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
//if not return -1
int recordCheck(IniText iniHandle,char id[])
{
	if(Ini_SectionExists (iniHandle, id)==0)//not exist
		return -1;
	return 1;

}
//return the amount of records in the db.
int countAllRecords(IniText iniHandle)
{
	int amount = Ini_NumberOfSections (iniHandle);
	return amount;
}
//return the amount of fields in a record
int countAllFields(IniText iniHandle,char id[])
{
	int fieldAmount = Ini_NumberOfItems (iniHandle, id);
	return fieldAmount; 
}

char* getRecordInfo(IniText iniHandle,char *id,int i)
{
	Ini_NthSectionName (iniHandle, i, &id);
	return id;
}



