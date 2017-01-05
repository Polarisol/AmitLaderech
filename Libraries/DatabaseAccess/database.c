//==============================================================================
//									database.c							
//							database function file.
//
//									Variables
//						//dbFile - database file path.
//==============================================================================

#include <ansi_c.h>
#include "inifile.h"

#include "database.h"

static IniText iniHandle;
static char dbFile[SIZE];
FILE *fp;

//allows specifying the databases file, it will be saved globally
//to be accessed by other functions
//other functions should check if a database file was defined and not work otherwise
//returns 1 if successful, 0 if not 
int setDatabaseFile(char name[])
{
	char path[SIZE];
	if(strcmp (name, ""))
	{
		sprintf (path, "Database\\%s.ini", name);
		fp = fopen (path, "w");
		fclose(fp);
		getDatabaseFile(path);
		return 1;
	}
	
	return 0;	
}

//changes the value of the provided 'name' to the used database file name.
//the user must make sure an appropriate array is provided
//returns 1 if successful, 0 if not
int getDatabaseFile(char name[])
{
	char file[SIZE];
	char path[SIZE];
	GetFirstFile ("Database\\*.ini", 1, 0, 0, 0, 0, 0, file);
	if(strcmp (file, ""))
	{
		if(!strcmp (file, name))
		{
			sprintf (path, "Database\\%s", name);
			strcpy (dbFile, path);
			return 1;
		}
		while (!GetNextFile (file))
		{
			if(!strcmp (file, name))
			{
				sprintf (path, "Database\\%s", name);
				strcpy (dbFile, path);
				return 1;
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



int search(int iniHandle,char id[], int numOfTags, char * tagName[], char * tagValue[])
{
	int val = recordCheck (iniHandle, id);
	if(val==-1)
		return -1;
	for(int i=0;i<numOfTags;i++)
		{
				Ini_NthItemName (iniHandle, id, i+1, &tagName[i]);
				Ini_GetPointerToRawString (iniHandle, id, tagName[i], &tagValue[i]);
				printf("%s %s\n",tagName[i],tagValue[i]);
		}
		
	return 1;
}

int recordCheck(int iniHandle,char id[])
{
	if(Ini_SectionExists (iniHandle, id)==0)//not exist
		return -1;
	return 1;

}

int countAllRecords(int iniHandle)
{
	int amount = Ini_NumberOfSections (iniHandle);
	return amount;
}

int countAllFields(int iniHandle,char id[])
{
	int fieldAmount = Ini_NumberOfItems (iniHandle, id);
	return fieldAmount; 
}

int getRecordInfo(int iniHandle,char *id,int i)
{
	Ini_NthSectionName (iniHandle, i, &id);
	return id;
}



