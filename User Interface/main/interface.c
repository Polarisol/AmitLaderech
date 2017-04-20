//==============================================================================
//
// Title:		interface.c
// Purpose:		A short description of the implementation.
//
// Created on:	20-Apr-17 at 19:36:38 by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "interface.h"
#include "database.h"
#include "1.h"


//Prepare the arrays for input. using the config.ini
void initialize(char database[], char dir[])
{
//database - name of the recorde database in config.ini
	Database_SetDatabaseFile(CONFIG);
	Database_CountAllFields(database,&fieldAmount);  
	tagName = malloc(sizeof(char*)*(fieldAmount));
	tagValue = malloc(sizeof(char*)*(fieldAmount));
	Database_GetRecordValues(database,fieldAmount,tagName,tagValue);
	Database_SetDatabaseFile(dir);
	Database_CountAllRecords(&recordAmount);
}

//free all dynamic arrays
void finalize()
{
	free(ids);free(tagName);free(tagValue);
}

//Return the index of control in the CtrlArray
//return -1 if the control was not found
int getIndexOfControl(int panel,int ctrlArray,int count,char controlName[])
{
//count - the amount of items in ctrlArray.
//controlName - the given name of the control. no need for PANLE_..
//panel - active panel.
//ctrlArray - active cntrlArray.
	char tmp[SIZE];
	for(int i=0;i<count;i++)
	{
		GetCtrlAttribute (panel, GetCtrlArrayItem(ctrlArray, i), ATTR_CONSTANT_NAME, tmp);
		if(strcmp(controlName,tmp)==0)
			return i;
	}
	return -1;
}

//add new member to the specific database
void addMember(char dir[],char database[],int panel, int ctrlArray)
{
//dir - directory of the inifile. use defined var SOLDIER,MENTOR,etc
//database - the name of the database as set in the config.ini. "SOLDIER", "MENTOR",etc
//panel - panel handle of the active panel.
	char tmpVal[SIZE],tmpName[SIZE];
	int count,idIndex = -1;
	initialize(database,dir); //CAPITAL LETTER IN CONFIG.INI
	GetNumCtrlArrayItems (ctrlArray, &count);
	idIndex = getIndexOfControl(panel,ctrlArray,count,"ID_NUMBER");
	
	if(idIndex!=-1)
	{
		GetCtrlVal (panel, GetCtrlArrayItem(ctrlArray, idIndex), id);
		if(Database_AddNewRecord(id,tagName,fieldAmount)==0)
			MessagePopup("Error", "ID already exist");
		else
		{
			
			for(int i=0;i<count;i++)
			{
				if(i!=idIndex)
				{
					GetCtrlVal (panel, GetCtrlArrayItem(ctrlArray, i), tmpVal); 
					GetCtrlAttribute (panel, GetCtrlArrayItem(ctrlArray, i), ATTR_LABEL_TEXT, tmpName);
					Database_SetFieldVal(id,tmpName,tmpVal);
					
				}
			}
		}
				
	}
	else
		MessagePopup("Eror","ID index was not found");
}
//Show the member from the database in the panel
void showMember(int panel,char dir[],char database[],char record[],int ctrlArray)
{
//dir - directory of the inifile. use defined var SOLDIER,MENTOR,etc
//database - the name of the database as set in the config.ini. "SOLDIER", "MENTOR",etc
//panel - panel handle of the active panel.
//record - the id number of the member.
	char tmpVal[SIZE],tmpName[SIZE];
	int count,idIndex = -1;
	initialize(database,dir); //CAPITAL LETTER IN CONFIG.INI
	GetNumCtrlArrayItems (ctrlArray, &count);
	Database_GetRecordValues(record,fieldAmount,tagName,tagValue);
	//(count-1) because: ID_NUMBER count as a ControlArray item but not as a field in ini file
	idIndex = getIndexOfControl(panel,ctrlArray,count,"ID_NUMBER");
	if(idIndex == -1)
	{
		MessagePopup("Error", "Control was not found");
		return;
	}
	SetCtrlVal(panel,GetCtrlArrayItem(ctrlArray, idIndex),record);//set the id number in the textbox
	for(int i=0;i<count;i++)
	{//Run on all of the items in the ctrlArray -> controls in the panel
		GetCtrlAttribute (panel, GetCtrlArrayItem(ctrlArray, i), ATTR_LABEL_TEXT, tmpName);//get the label text of the item
		GetCtrlAttribute (panel, GetCtrlArrayItem(ctrlArray, i), ATTR_CONSTANT_NAME, tmpVal);//get the name of the item. no PANEL_..
		int index = getIndexOfControl(panel,ctrlArray,count,tmpVal);
		if(index == -1)
		{
			MessagePopup("Error", "Control was not found");
			return;
		}
		if(index != idIndex)
		{//Only if the control is not the ID NUMBER
			for(int j=0;j<fieldAmount;j++)
			{
				if(strcmp(tmpName,tagName[j])==0)
				{//if the control's label text is equal to the field name from the database
				 //then, put the corresponding value in right control.
					SetCtrlVal(panel,GetCtrlArrayItem(ctrlArray, index),tagValue[j]);
				}
			}
		}
	}
}

void connectIDtoName(char dir[],char database[],char record[],char fullName[])
{//gets the ID and returns the FULL NAME of the record.
	char fName[SIZE],lName[SIZE];
	initialize(database,dir);
	Database_GetFieldVal(record,"שם פרטי",fName);
	Database_GetFieldVal(record,"שם משפחה",lName);
	sprintf(fullName,"%s %s",fName,lName);
}

int connectNametoID(char dir[],char database[],char record[],char fullName[]) 
{ //gets the FULL NAME and return the ID
	char fName[SIZE],lName[SIZE],fullNameCheck[SIZE];
	initialize(database,dir);
	for(int i=1;i<=recordAmount;i++)
	{
		Database_GetRecordInfo(id,i);
		Database_GetFieldVal(id,"שם פרטי",fName);
		Database_GetFieldVal(id,"שם משפחה",lName);
		sprintf(fullNameCheck,"%s %s",fName,lName);
		if(strcmp(fullName,fullNameCheck)==0)
		{
			sprintf(record,id);
			return 1;
		}
	}
	return 0;
}

int connectNametoIDS(char **records,char fullName[]) 
{ //gets the FULL NAME and return the ID
	char fName[SIZE],lName[SIZE],fullNameCheck[SIZE];
	int countID =0;
	for(int i=1;i<=recordAmount;i++)
	{
		Database_GetRecordInfo(id,i);
		Database_GetFieldVal(id,"שם פרטי",fName);
		Database_GetFieldVal(id,"שם משפחה",lName);
		sprintf(fullNameCheck,"%s %s",fName,lName);
		if((strcmp(fullName,fullNameCheck)==0)|| strcmp(fullName,fName)==0 ||  strcmp(fullName,lName)==0)
		{
			records[countID] = malloc(sizeof(char)*12);
			sprintf(records[countID],"%s\0",id);
			countID++;
		}
		
	}
	if(countID==0)
		return 0;
	else
		return countID;
}

int search(char searchBy[],char val[],char **output)
{
	
	if(strcmp(searchBy,"name")==0)
	{//Search by name 
			return connectNametoIDS(output,val);
	}
	else
	{//search by ID
		for(int i=0;i<recordAmount;i++)
		{
			Database_GetRecordInfo(id,i+1);
			if(strcmp(val,id)==0)
			{
				output[0] = malloc(sizeof(char)*strlen(val)+1);
				sprintf(output[0],val);
				return 1;
			}
		}	
	}
	return 0;
}

void createTable(char dir[],char database[], char **ids,int rows,int panel,int control)
{//NOT WORKING WITH HEBREW 
	initialize(database,dir);
	InsertTableRows (panel, control, -1, rows, VAL_CELL_STRING);
	InsertTableColumns (panel, control, -1, fieldAmount, VAL_CELL_STRING);
	for(int i=0;i<rows;i++)
	{
		SetTableRowAttribute (panel, control, i+1, ATTR_USE_LABEL_TEXT, 1);
		SetTableRowAttribute (panel, control, i+1, ATTR_LABEL_TEXT, ids[i]);
		Database_GetRecordValues(ids[i],fieldAmount,tagName,tagValue); 
		for(int j=1;j<=fieldAmount;j++)
		{
			SetTableColumnAttribute (panel, control, j, ATTR_TEXT_CHARACTER_SET, VAL_HEBREW_CHARSET);
			SetTableCellVal (panel, control, MakePoint(j,i+1), tagValue[j-1]);
			SetTableColumnAttribute (panel, control, j, ATTR_USE_LABEL_TEXT, 1);
			HebrewConverter_convertHebrewUTF8toISO(tagName[j-1]); 
			SetTableColumnAttribute (panel, control, j, ATTR_LABEL_TEXT, tagName[j-1]);
			
		}
		
	}
}

void clockDate()
{
	GetSystemDate (&month, &day, &year);
	sprintf (currentDate, "%d/%d/%d", day, month, year);
	GetSystemTime (&hr, &min, &sec);
	if  (min<10)
		sprintf (currentTime, "%d:0%d", hr, min);
	else
		sprintf (currentTime, "%d:%d",  hr, min);
	SetCtrlVal (pMain, P_MAIN_DATE_STRING, currentDate);
	SetCtrlVal (pMain, P_MAIN_CLOCK_STRING, currentTime);
	if (hr>=7 && hr<12)
		  SetCtrlVal (pMain, P_MAIN_BLESSING, "!נטלי, בוקר טוב");
	else if (hr>=12 && hr<17)
		SetCtrlVal (pMain, P_MAIN_BLESSING, "!נטלי, צהריים טובים");
	else if (hr>=17 && hr<22)
		SetCtrlVal (pMain, P_MAIN_BLESSING, "!נטלי, ערב טוב");
	else	// 22:00-6:59
		SetCtrlVal (pMain, P_MAIN_BLESSING, "!נטלי, לילה טוב! לכי לישון");
}

void searchSoldier(char mentorName[],char soldierName[])
{
	char tmp[SIZE];
	initialize("SOLDIER",SOLDIER);
	for(int i=0;i<recordAmount;i++)
	{
		Database_GetRecordInfo(id,i+1);
		Database_GetFieldVal(id,"מנטור",tmp);
		if(strcmp(tmp,mentorName)==0)
		{
			connectIDtoName(SOLDIER,"SOLDIER",id,tmp);
			sprintf(soldierName,"%s",tmp);
			break;
		}
	}
	
}

void restoreSearch()
{
	DefaultCtrl (pMain, P_MAIN_SEARCH_RING);
	DefaultCtrl (pMain, P_MAIN_SEARCH_BY_RING);
	DefaultCtrl (pMain, P_MAIN_SEARCH_STRING);
}

void displayGroupPanel(char groupName[])
{
	char tmp[SIZE],fullName[SIZE];
	int count;
	//SET THE STAGE
	DisplayPanel(pGroup);
	ctrlArray = GetCtrlArrayFromResourceID (pGroup, CTRLARRAY_9);
	showMember(pGroup,GROUP,"GROUP",groupName,ctrlArray);
	SetCtrlVal (pGroup, P_GROUP_GROUP_NAME, groupName);
	//END. START LOCATING MENTORS
	initialize("MENTOR",MENTOR);
	for(int i=0;i<recordAmount;i++)
	{
		Database_GetRecordInfo(id,i+1);
		Database_GetFieldVal(id,"קבוצה", tmp); //get the group name
		if(strcmp(tmp,groupName)==0)  //true
		{
			connectIDtoName(MENTOR,"MENTOR",id,fullName);
			//Create array for all the buttons and run of them until u find 
			//button without text in it and set it to be fullName
			ctrlArray = GetCtrlArrayFromResourceID(pGroup,CA_MENTOR_BTN);
			GetNumCtrlArrayItems (ctrlArray, &count); 
			for(int i=0;i<count;i++)
			{
				GetCtrlAttribute (pGroup, GetCtrlArrayItem(ctrlArray, i), ATTR_LABEL_TEXT, tmp);
				if(strcmp(tmp,"")==0)//true
				{
					SetCtrlAttribute (pGroup, GetCtrlArrayItem(ctrlArray, i), ATTR_LABEL_TEXT, fullName);
					break;
				}
			}
		}
	}
}

void searchFor(char dir[],char database[], char fieldName[], char valToCmp[])
{  //function is used when group\mentor\guide was deleted. 
	//function remove group\mentor\guide connections from other database 
	char tmp[SIZE];
	initialize(database,dir);
	for(int i=0;i<recordAmount;i++)
	{
		Database_GetRecordInfo(id,i+1);
		Database_GetFieldVal(id,fieldName,tmp);
		if(strcmp(tmp,valToCmp)==0)
		{
			Database_SetFieldVal(id, fieldName,fieldName);
		}
	}
	
}
