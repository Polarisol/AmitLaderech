#include <cvirte.h>		
#include <userint.h>
#include "1.h"
#include "database.h"
//Constants for the database directory
#define SOLDIER "Database\\soldier.ini"
#define MENTOR  "Database\\mentor.ini"
#define GUIDE   "Database\\guide.ini"
#define CONFIG  "Database\\config.ini"
#define GROUP   "Database\\group.ini"

//==============================================================================
//							Variables section
//								SIZE = 300
//============================================================================== 
static int pMain, pActivity, pGuide, pNewGuide, pMentor, pNewMent, pSoldier, pNewSold, pEditTL,pTable,pGroup,pNewGroup;
static char id[SIZE], currentDate[50], currentTime[50];
//static char dbFile[SIZE];
static char **tagName,**tagValue,**ids,**output; 
int recordAmount;
int fieldAmount;
int ctrlArray;
int hr, min, sec;
int day, month, year;


//==============================================================================
//							Function declaration section
//============================================================================== 
void initialize(char database[]);
void finalize();
void addMember(char dir[],char database[],int panel,int ctrlArray);
int getIndexOfControl(int panel,int ctrlArray,int count,char controlName[]);
void showMember(int panel,char dir[],char database[],char record[],int ctrlArray);
void connectIDtoName(char dir[],char database[],char record[],char fullName[]);
int connectNametoID(char dir[],char database[],char record[],char fullName[]); 
void createTable(char dir[],char database[], char **ids, int rows,int panel,int control);
int connectNametoIDS(char **records,char fullName[]);
int search(char searchBy[],char val[],char **output);


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
	if ((pTable = LoadPanel (0, "1.uir", P_TABLE)) < 0)
        return -1;
	if ((pGroup = LoadPanel (0, "1.uir", P_GROUP)) < 0)
        return -1;
	if ((pNewGroup = LoadPanel (0, "1.uir", P_NEW_GROU)) < 0)
        return -1;
	//RecallPanelState (pMain, "panelState.txt", 0);
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
	else
		  SetCtrlVal (pMain, P_MAIN_BLESSING, "!נטלי, לילה טוב! לכי לישון");
	DisplayPanel (pMain);
    RunUserInterface ();
    finalize();
	SavePanelState (pMain, "panelState.txt", 0);
    DiscardPanel (pMain);
    DiscardPanel (pActivity);
    DiscardPanel (pGuide);
    DiscardPanel (pNewGuide);
    DiscardPanel (pMentor);
    DiscardPanel (pNewMent);
    DiscardPanel (pSoldier);
    DiscardPanel (pNewSold);
	DiscardPanel (pEditTL);
	DiscardPanel (pTable);
	DiscardPanel (pGroup);
	DiscardPanel (pNewGroup);
    return 0;
}

//==============================================================================
//							Exits Functions
//==============================================================================
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


//==============================================================================
//							CVI CALLBACK Functions
//==============================================================================

//Add new record to any database
int CVICALLBACK Save_Sol_Func (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)

{
	char guideName[SIZE],groupName[SIZE];
	char group1[SIZE],group2[SIZE];
	char *result;
	
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
			else if(panel == pNewGroup)
			{
				///////////////////////////////////////////////////
				GetCtrlVal (panel, P_NEW_GROU_CITY, group1);
				GetCtrlVal (panel, P_NEW_GROU_YEAR, group2);		//CREATE THE GROUP NAME
				result = malloc(strlen(group1)+strlen(group2)+1);
				strcpy(result,group1);
				strcat(result,group2);
				SetCtrlVal (panel, P_NEW_GROU_GROUP_NAME, result);
				//////////////////////////////////////////////////
				GetCtrlVal (panel, P_NEW_GROU_GUIDE, guideName);
				connectNametoID(GUIDE,"GUIDE",id,guideName);	 
				Database_GetFieldVal(id,"קבוצה 1", group1);
				Database_GetFieldVal(id,"קבוצה 2", group2);//
				GetCtrlVal (panel, P_NEW_GROU_GROUP_NAME, groupName);
				if(strcmp(group1,"קבוצה 1")==0)
					Database_SetFieldVal(id,"קבוצה 1", groupName);
				else if(strcmp(group2,"קבוצה 2")==0)
					Database_SetFieldVal(id,"קבוצה 2", groupName);
				else
				{
					MessagePopup("Alert", "GUIDE already have 2 groups"); 
					return 0;
				}
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_8);
				addMember(GROUP,"GROUP",panel,ctrlArray);
				HidePanel(panel);
				DisplayPanel(pGroup);
				ctrlArray = GetCtrlArrayFromResourceID (pGroup, CTRLARRAY_9);
				showMember(pGroup,GROUP,"GROUP",id,ctrlArray);
				SetCtrlVal (pGroup, P_GROUP_GROUP_NAME, result);
			}
			break;
	}
	return 0;
}


//==============================================================================
//							Display Panels Functions
//==============================================================================

int CVICALLBACK OPEN_P_Activity (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{
	char fullName[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (pActivity);
			initialize(GUIDE);
			Database_SetDatabaseFile(GUIDE);
			Database_CountAllRecords(&recordAmount);
			ctrlArray = GetCtrlArrayFromResourceID (pActivity, CTRLARRAY_7);
			for(int i=0;i<recordAmount;i++)
			{
				Database_GetRecordInfo(id,i+1);
				connectIDtoName(GUIDE,"GUIDE",id,fullName);
				SetCtrlAttribute (pActivity, GetCtrlArrayItem(ctrlArray, i), ATTR_LABEL_TEXT, fullName);
			}
			
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
	char s[3];
	switch (event)
	{
		case EVENT_COMMIT:
			initialize("GROUP");
			Database_SetDatabaseFile(GROUP);
			Database_CountAllRecords(&recordAmount);
			sprintf(s,"%d",(recordAmount+1));
			DisplayPanel(pNewGroup);
			SetCtrlVal (pNewGroup, P_NEW_GROU_ID_NUMBER, s);
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

int CVICALLBACK openGuidePanel (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	char fullName[SIZE];
	char group1[SIZE],group2[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(panel);
			DisplayPanel(pGuide);
			GetCtrlAttribute (panel, control, ATTR_LABEL_TEXT, fullName);
			connectNametoID(GUIDE,"GUIDE",id,fullName);
			ctrlArray = GetCtrlArrayFromResourceID (pGuide, CTRLARRAY_6);
			showMember(pGuide,GUIDE,"GUIDE",id,ctrlArray);
			GetCtrlVal (pGuide, P_GUIDE_GROUP_1_STRING, group1);
			GetCtrlVal (pGuide, P_GUIDE_GROUP_2_STRING, group2);
			SetCtrlAttribute (pGuide, P_GUIDE_GROUP_1, ATTR_LABEL_TEXT, group1);
			SetCtrlAttribute (pGuide, P_GUIDE_GROUP_2, ATTR_LABEL_TEXT, group2); 
			break;
	}
	return 0;
}

int CVICALLBACK openTable (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	char fullName[SIZE],val[SIZE];
	int j=0;
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel(pTable);
			GetCtrlVal (panel, P_GUIDE_ID_NUMBER, id);
			connectIDtoName(GUIDE,"GUIDE",id,fullName);
			initialize("SOLDIER");
			Database_SetDatabaseFile(SOLDIER);
			Database_CountAllRecords(&recordAmount);
			ids = malloc(sizeof(char*)*(recordAmount));
			for(int i=1;i<=recordAmount;i++) 
			{
				Database_GetRecordInfo(id,i);
				Database_GetFieldVal(id,"מנחה",val);
				if(strcmp(fullName,val)==0)
				{
					ids[j] = malloc((char)strlen(val)+1);
					sprintf(ids[j],id);
					j++;
				}
			}
			if(j!=0)
			{
				createTable(SOLDIER,"SOLDIER",ids,j,pTable,P_TABLE_LIST_S_OR_M);
			}
			
			break;
	}
	return 0;
}

int CVICALLBACK checkIfExcist (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)
{
	char database[SIZE],fullName[SIZE],dir[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlAttribute (panel, control, ATTR_CONSTANT_NAME, database);
			GetCtrlVal(panel,control,fullName);
			initialize(database);
			if(strcmp(database,"GUIDE")==0)
				sprintf(dir,GUIDE);
			else
				sprintf(dir,MENTOR);
			if(connectNametoID(dir,database,id,fullName)==0)//if the fullName does not excist return 0
				MessagePopup("Alert", "Record does not excist!");
				
			break;
	}
	return 0;
}

int CVICALLBACK changeVal (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
char database[SIZE], searchBy[SIZE],val[SIZE],dir[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			if(control == P_MAIN_SEARCH_RING)
			{
				SetCtrlAttribute (panel, P_MAIN_SEARCH_BY_RING ,ATTR_VISIBLE, 1);
			}
			else if(control ==  P_MAIN_SEARCH_BY_RING) 
			{
				 SetCtrlAttribute (panel,P_MAIN_SEARCH_STRING, ATTR_VISIBLE, 1);
			}
			else if(control == P_MAIN_SEARCH_STRING)
			{
				
				GetCtrlVal (panel, P_MAIN_SEARCH_RING, database);
				GetCtrlVal (panel, P_MAIN_SEARCH_BY_RING, searchBy);
				GetCtrlVal (panel, control, val);
				if(strcmp(database,"GROUP")==0)
				{
					sprintf(dir,"%s",GROUP);	
				}
				else if(strcmp(database,"GUIDE")==0)
				{
					sprintf(dir,"%s",GUIDE);
				}
				else if(strcmp(database,"MENTOR")==0)
				{
					sprintf(dir,"%s",MENTOR);
				}
				else
					sprintf(dir,"%s",SOLDIER);
				initialize(database);
				Database_SetDatabaseFile(dir);
				Database_CountAllRecords(&recordAmount);
				output = malloc(sizeof(char*)*recordAmount);
				if(database != "GROUP")
				{
					int cc = search(searchBy,val,output);
					if(cc>=1)
					{
						DisplayPanel(pTable);
						createTable(dir,database,output,cc,pTable,P_TABLE_LIST_S_OR_M);
					}
				}
				else
				{
					//GROUP search
				}
			}								   
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

int connectNametoID(char dir[],char database[],char record[],char fullName[]) 
{ //gets the FULL NAME and return the ID
	char fName[SIZE],lName[SIZE],fullNameCheck[SIZE];
	initialize(database);
	Database_SetDatabaseFile(dir);
	Database_CountAllRecords(&recordAmount);
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
	initialize(database);
	Database_SetDatabaseFile(dir);
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

int CVICALLBACK edit (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{/*
	
	int ctrlarr1[3], ctrlarr2[7], ctrlarr3[3]; // 1-hide/show , 2-hot/indicator, 3-another hide/show
	switch (event)
	{
		case EVENT_COMMIT:
			if (panel==pGuide)
			switch (panel)    // I didn't finish that function. Please Don't touch!
			{
				case pGroup:
					ctrlarr1=[P_GROUP_DELETE_GROUP_BUTTON, P_GROUP_EDIT_MENTORS_BUTTON, P_GROUP_SAVE_CHANGES_BUTTON];
					ctrlarr2=[P_GROUP_GUIDE, P_GROUP_STATUS_RING];
					ctrlarr3=[P_GROUP_EDIT_GROUP_BUTTON, P_GROUP_LIST_SOLDIERS_BUTTON];
					break;
				case pGuide:
					ctrlarr1={P_GUIDE_DELETING_GUIDE_BUTTON, P_GUIDE_SAVE_CHANGES_BUTTON};
					ctrlarr2={P_GUIDE_CELL_PHONE_NUMBER, P_GUIDE_PHONE_NUMBER, P_GUIDE_ADDRESS, P_GUIDE_CITY,
							  P_GUIDE_MAIN_OCCUPATION, P_GUIDE_SUMMARY, P_GUIDE_EXCEPTIONS};
					ctrlarr3={P_GUIDE_LIST_SOLDIERS_BUTTON, P_GUIDE_SEND_EMAIL, P_GUIDE_EDITING_BUTTON};
					break;
				case pMentor:
					ctrlarr1=[P_MENTOR_DELETING_MENTO_BUTTON, P_MENTOR_SAVE_CHANGES_BUTTON];
					ctrlarr2=[P_MENTOR_CELL_PHONE_NUMBER, P_MENTOR_PHONE_NUMBER, P_MENTOR_ADDRESS, P_MENTOR_CITY,
							  P_MENTOR_MAIN_OCCUPATION];
					ctrlarr3=[];
					break;
				case pSoldier:
					ctrlarr1=[P_SOLDIER_MOVING_ARCHIVE_BUTTON, P_SOLDIER_SAVE_CHANGES_BUTTON, P_SOLDIER_EDIT_TL_BUTTON];
					ctrlarr2=[];
					break;
			}
			SetCtrlArrayAttribute (ctrlarr1, ATTR_VISIBLE, 1);
			SetCtrlArrayAttribute (ctrlarr2, ATTR_CTRL_MODE, VAL_HOT);
			SetCtrlArrayAttribute (ctrlarr3, ATTR_VISIBLE, 0);
			break;
	}
	
*/
return 0;
}
