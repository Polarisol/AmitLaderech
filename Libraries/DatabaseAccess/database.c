
//==============================================================================
//									database.c							
//							database function file.
//
//									Variables
//						//dbFile - database file path.
//==============================================================================

 
#include "database.h"



static IniText iniHandle;
static char dbFile[SIZE];
static char *tagName[SIZE],*tagValue[SIZE];
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

//remove record from db file.
//return 1 if successful, 0 if record does no exist
int removeRecord(IniText iniHandle, char id[])
{
	if(Ini_RemoveSection (iniHandle, id)==0)
		return 0;
	else
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


//search for the ID in database.create arrays for name value.
//return -1 if ID is not in the db
int search(IniText iniHandle,char id[], int numOfTags, char * tagName[], char * tagValue[])
{
	int val = recordCheck (iniHandle, id);
	if(val==-1)
		return -1;
	//tagName = malloc(sizeof(char*)*countAllFields(iniHandle,id));
	//tagValue = malloc(sizeof(char*)*countAllFields(iniHandle,id));
	for(int i=0;i<numOfTags;i++)
	{
		
		Ini_NthItemName (iniHandle, id, i+1, &tagName[i]);
		//HebrewConverter_convertHebrewUTF8toISO(tagName[i]);
		Ini_GetPointerToRawString (iniHandle, id, tagName[i], &tagValue[i]);
		//HebrewConverter_convertHebrewUTF8toISO(tagValue[i]);
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

//get record name from the index provided.
//when called use the following:
//sprintf(id,"%s",getRecordInfo(iniHandle,id,i));
char* getRecordInfo(IniText iniHandle,char *id,int i)
{
	Ini_NthSectionName (iniHandle, i, &id);
	return id;
}


// sets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
int setFieldVal(IniText iniHandle,char id[], char field[], char value[])
{
	//HebrewConverter_convertHebrewISOtoUTF8(id);  
	//HebrewConverter_convertHebrewISOtoUTF8(field);  
	//HebrewConverter_convertHebrewISOtoUTF8(value); 
	
	Ini_PutRawString (iniHandle, id, field, value);
	Ini_WriteToFile (iniHandle, dbFile);
	return 1;
}

//return the index of the field in the iniText
//if the field does not exist return 0
int getIndexofField(IniText iniHandle,char id[],char field[])
{
	if(recordCheck(iniHandle,id)!=-1) 
	{
		 int fieldAmount = countAllFields(iniHandle,id);
		 for(int i=1;i<=fieldAmount;i++) 
		 {
			if(!strcmp(tagName[i-1],field))
				return (i-1);
		 }
	}
	 return 0;
}

// gets the value of an existing field of an existing record
//returns 1 if successful, 0 if not (for example if the field or record are not known)
//the user must make sure an appropriate array is provided
int getFieldVal(IniText iniHandle,char id[], char field[], char value[])
{
	int fieldAmount,i;
	if(recordCheck(iniHandle,id)!=-1)
	{
		fieldAmount = countAllFields(iniHandle,id);
		search(iniHandle,id,fieldAmount,tagName,tagValue);
		i = getIndexofField(iniHandle,id,field);
				if(!strcmp(tagValue[i],value))
					return 1;
	}
	return 0;
}

//counts how many records have this value in the specified field 
int getNumberOfIdsFromField(IniText iniHandle,char field[], char value[])
{
	int amount,count =0;
	char id[SIZE];
	amount = countAllRecords(iniHandle);
	for(int i=1;i<=amount;i++)
	{
		sprintf(id,"%s",getRecordInfo(iniHandle,id,i));
		if(getFieldVal(iniHandle,id,field,value)==1)
		{
			count++;
		}
	}
	return count;
}

//provide a list of all ids with this value in the specified field
//the user must make sure an appropriate array is provided
char** getRecordIdsFromField(IniText iniHandle,char field[], char value[], char **ids)
{
	int amount,count =0;
	char id[SIZE];
	amount = countAllRecords(iniHandle);
	ids = malloc(sizeof(char*)*getNumberOfIdsFromField(iniHandle,field,value));
	for(int i=1;i<=amount;i++)
	{
		sprintf(id,"%s",getRecordInfo(iniHandle,id,i));
		if(getFieldVal(iniHandle,id,field,value)==1)
		{
			ids[count] = malloc(sizeof(char)*(strlen(id)+1));
			sprintf(ids[count],"%s",id);
			count++;
		}
		
	}
	return ids;
}

//work in progress
int getAutofill(IniText iniHandle,int amount, char *tag, char** lib,char **output)
{
	int i,j=0;
	for(i=0;i<amount;i++)
	{
		
		if(strstr(lib[i],tag)!=NULL)
		{
			output[i] = malloc(sizeof(char*)*SIZE);
			sprintf(output[i],"%s",lib[i]);
			j++;
		}
	}
	
	return j;
	
}

