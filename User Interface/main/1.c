#include <cvirte.h>		
#include <userint.h>
#include "1.h"
#include "database.h"
//Constants for the database directory
#define SOLDIER "Database\\soldier.ini"
#define MENTOR  "Database\\mentor.ini"
#define GUIDE   "Database\\guide.ini"
#define CONFIG  "Database\\config.ini"

//==============================================================================
//							Variables section
//								SIZE = 300
//============================================================================== 
static int pMain, pActivity, pGuide, pNewGuide, pMentor, pNewMent, pSoldier, pNewSold, pEditTL;
static char id[SIZE];
//static char dbFile[SIZE];
static char **tagName,**tagValue,**ids;
int recordAmount;
int fieldAmount;
int ctrlArray;



//==============================================================================
//							Function declaration section
//============================================================================== 
void initialize(char database[]);
void finalize();
void addMember(char dir[],char database[],int panel,int ctrlArray);
int getIndexOfControl(int panel,int ctrlArray,int count,char controlName[]);
void showMember(int panel,char dir[],char database[],char record[],int ctrlArray);
void connectIDtoName(char dir[],char database[],char record[],char fullName[]);


//==============================================================================
//									MAIN
//============================================================================== 
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
        return -1;    /* out of memory */
    if ((pMain = LoadPanel (0, "1.uir", P_MAIN)) < 0)
        return -1;
    if ((pActivity = LoadPanel (0, "1.uir", P_ACTIVITY)) < 0)
        return -1;
    if ((pGuide = LoadPanel (0, "1.uir", P_GUIDE)) < 0)
        return -1;
    if ((pNewGuide = LoadPanel (0, "1.uir", P_NEW_GUID)) < 0)
        return -1;
    if ((pMentor = LoadPanel (0, "1.uir", P_MENTOR)) < 0)
        return -1;
    if ((pNewMent = LoadPanel (0, "1.uir", P_NEW_MENT)) < 0)
        return -1;
    if ((pSoldier = LoadPanel (0, "1.uir", P_SOLDIER)) < 0)
        return -1;
    if ((pNewSold = LoadPanel (0, "1.uir", P_NEW_SOLD)) < 0)
        return -1;
	if ((pEditTL = LoadPanel (0, "1.uir", P_EDIT_TL)) < 0)
        return -1;
    DisplayPanel (pMain);
    RunUserInterface ();
    finalize();
    DiscardPanel (pMain);
    DiscardPanel (pActivity);
    DiscardPanel (pGuide);
    DiscardPanel (pNewGuide);
    DiscardPanel (pMentor);
    DiscardPanel (pNewMent);
    DiscardPanel (pSoldier);
    DiscardPanel (pNewSold);
	DiscardPanel (pEditTL);
    return 0;
}


////////////////////////
// Exits Functions    //
////////////////////////

int CVICALLBACK exitFunc (int panel, int event, void *callbackData,
                          int eventData1, int eventData2)
{
    switch (event)
    {
        case EVENT_GOT_FOCUS:

            break;
        case EVENT_LOST_FOCUS:

            break;
        case EVENT_CLOSE:
            if (panel==pMain)
                QuitUserInterface (0);
            else
                HidePanel (panel);
            break;
    }
    return 0;
}


//Add new record to any database
int CVICALLBACK Save_Sol_Func (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)

{
	
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == pNewSold)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY);
				addMember(SOLDIER,"SOLDIER",panel,ctrlArray);
				HidePanel(panel);
				DisplayPanel(pSoldier);
				ctrlArray = GetCtrlArrayFromResourceID (pSoldier, CTRLARRAY_2);
				showMember(pSoldier,SOLDIER,"SOLDIER",id,ctrlArray);
			}
			else if(panel == pNewGuide)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_5);
				addMember(GUIDE,"GUIDE",panel,ctrlArray);
				HidePanel(panel);
				DisplayPanel(pGuide);
				ctrlArray = GetCtrlArrayFromResourceID (pGuide, CTRLARRAY_6);
				showMember(pGuide,GUIDE,"GUIDE",id,ctrlArray);
			}
			else if(panel == pNewMent)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_3);
				addMember(MENTOR,"MENTOR",panel,ctrlArray);
				HidePanel(panel);
				DisplayPanel(pMentor);
				ctrlArray = GetCtrlArrayFromResourceID (pMentor, CTRLARRAY_4);
				showMember(pMentor,MENTOR,"MENTOR",id,ctrlArray);
			}
			break;
	}
	return 0;
}


/////////////////////////////////
// Display Panels functions    //
/////////////////////////////////

int CVICALLBACK OPEN_P_Activity (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (pActivity);
			char fullName[SIZE];
			connectIDtoName(SOLDIER,"SOLDIER","203059936",fullName);
			break;
	}
	return 0;
}

int CVICALLBACK Open_P_NEW_SOLD (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 DisplayPanel (pNewSold);
			break;
	}
	return 0;
}

int CVICALLBACK Open_New_Guide (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel(pNewGuide);
			break;
	}
	return 0;
}
int CVICALLBACK OpenPanelNewGroup (int panel, int control, int event,
								   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK Open_P_NEW_MENTOR (int panel, int control, int event,
								   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel(pNewMent);
			break;
	}
	return 0;
}


//==============================================================================
//							Function realization section
//============================================================================== 
//Prepare the arrays for input. using the config.ini
void initialize(char database[])
{
//database - name of the recorde database in config.ini
	Database_SetDatabaseFile(CONFIG);
	Database_CountAllFields(database,&fieldAmount);  
	tagName = malloc(sizeof(char*)*(fieldAmount));
	tagValue = malloc(sizeof(char*)*(fieldAmount));
	Database_GetRecordValues(database,fieldAmount,tagName,tagValue);
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
	initialize(database); //CAPITAL LETTER IN CONFIG.INI
	GetNumCtrlArrayItems (ctrlArray, &count);
	idIndex = getIndexOfControl(panel,ctrlArray,count,"ID_NUMBER");
	if(idIndex!=-1)
	{
		GetCtrlVal (panel, GetCtrlArrayItem(ctrlArray, idIndex), id);
		Database_SetDatabaseFile(dir);
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
	initialize(database); //CAPITAL LETTER IN CONFIG.INI
	Database_SetDatabaseFile(dir);
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
	initialize(database);
	Database_SetDatabaseFile(dir);
	Database_GetFieldVal(record,"שם פרטי",fName);
	Database_GetFieldVal(record,"שם משפחה",lName);
	sprintf(fullName,"%s %s",fName,lName);
}


//==============================================================================
//							OLD Function\VAR realization section
//============================================================================== 

/*
int soldierContorls[] = {P_NEW_SOLD_ID_NUMBER,P_NEW_SOLD_FIRST_NAME,
						 P_NEW_SOLD_LAST_NAME,P_NEW_SOLD_PHONE_NUMBER,
						P_NEW_SOLD_MAIL,P_NEW_SOLD_ADDRESS,P_NEW_SOLD_AGE,P_NEW_SOLD_GUIDE,
						P_NEW_SOLD_MENTOR, P_NEW_SOLD_IMAGE};
void addMember(char dir[],char database[],int memberControl[],int limit,int panel)
{
	//dir - directory of the inifile. use defined var SOLDIER,MENTOR,etc
	//database - the name of the database as set in the config.ini. "SOLDIER", "MENTOR",etc
	//memberContor - array of the controls in  the panel.
	//limit - the size of the memberControl array. use limit = sizeof(memberCcontrol)\sizeof(int);
	//panel - panel handle the active panel - send panel. 
	char tmpVal[SIZE],tmpName[SIZE];
	initialize(database); //CAPITAL LETTER IN CONFIG.INI
	GetCtrlVal (panel, memberControl[0], id);
	Database_SetDatabaseFile(dir);
	if(Database_AddNewRecord(id,tagName,fieldAmount)==0)
		MessagePopup("Error", "ID already exist");
	else
	{
		for(int i=1;i<limit;i++)
		{
			GetCtrlVal (panel, memberControl[i], tmpVal); 
			GetCtrlAttribute (panel, memberControl[i], ATTR_LABEL_TEXT, tmpName);
			Database_SetFieldVal(id,tmpName,tmpVal);
		}
	}
}
*/



