#include <userint.h>
#include "DataBaseAccess_test.h"

//==============================================================================
//									database.c							
//							database function file.
//==============================================================================

 
#include "database.h"



static IniText iniHandle;
static char *dbFile;
static char *tagName[SIZE],*tagValue[SIZE];
FILE *fp;

//==============================================================================
//									Staic functions							
//==============================================================================


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

//==============================================================================
//								End	Staic functions							
//==============================================================================

//==============================================================================
//								Database functions						
//==============================================================================

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
//==============================================================================
//								End Database functions						
//==============================================================================
//==============================================================================
//								Record functions						
//==============================================================================
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

int Database_RemoveRecord(char id[])
{
	if(Ini_RemoveSection (iniHandle, id)==0)
		return 0;
	else
		Ini_WriteToFile (iniHandle, dbFile);
	return 1;
}

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

int Database_GetRecordIdsFromField(char field[], char value[], char **ids)
{
	int amount;
	int count =0;
	char id[SIZE];
	Database_CountAllRecords(&amount);
	for(int i=1;i<=amount;i++)
	{
		Database_GetRecordInfo(id,i);
		if(Database_CmpGetFieldVal(id,field,value)==1)
		{
			ids[count] = malloc(sizeof(char)*(strlen(id)+1));
			sprintf(ids[count],"%s",id);
			count++;
		}
	}
	
	return 0;
}

int Database_RecordCheck(char id[])
{
	if(Ini_SectionExists (iniHandle, id)==0)//not exist
		return 0;
	return 1;

}

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

int Database_GetRecordInfo(char *id,int i)
{
	char *str;
	Ini_NthSectionName (iniHandle, i, &str);
	sprintf(id,"%s",str);
	if(id == NULL)
		return 0;
	return 1;
}

//==============================================================================
//							End Record functions						
//==============================================================================

//==============================================================================
//								Field functions						
//==============================================================================

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

int Database_GetFieldVal(char id[], char field[], char value[])
{
	if(Database_RecordCheck(id)!=0)
	{
		Ini_GetRawStringIntoBuffer (iniHandle, id, field, value, SIZE);
	}
	return 0;
}

void Database_GetNumberOfIdsFromField(char field[], char value[], int *count)
{
	int amount;
	char id[SIZE];
	Database_CountAllRecords(&amount);
	for(int i=1;i<=amount;i++)
	{
		Database_GetRecordInfo(id,i);
		if(Database_CmpGetFieldVal(id,field,value)==1)
		{
			(*count)++;
		}
	}
}							

int Database_AddNewFieldAll(char field[],char value[])
{
	int amount =0;
	Database_CountAllRecords(&amount);
	char *id = malloc(sizeof(char*)*(amount+1));
	for(int i=1;i<=amount;i++)
	{
		Database_GetRecordInfo(id,i);
		if(Database_AddNewField(id,field,value)==0)
		{
			free(id);
			return 0;
		}
	}
	free(id);
	return 1;
}

int Database_AddNewField(char id[], char field[], char value[])
{
	if(id!=NULL)
	{
		if(Ini_ItemExists (iniHandle, id, field)==0)
		{
			if(value !=NULL)
				Ini_PutRawString (iniHandle, id, field, value);
			else
				Ini_PutRawString (iniHandle, id, field, "");
			Ini_WriteToFile (iniHandle, dbFile);
			return 1;
		}
		
	}
	return 0;
}
//==============================================================================
//							End Field functions						
//==============================================================================

//==============================================================================
//								Auto Fill functions						
//==============================================================================

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
	free(lib);
	return j;
	
}

//==============================================================================
//							End Auto fill functions						
//==============================================================================




