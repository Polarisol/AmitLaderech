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
static int pMain, pActivity, pGuide, pNewGuide, pMentor, pNewMent, pSoldier, pNewSold, pEditTL, pTable, pGroup, pNewGroup;
static char id[SIZE], currentDate[50], currentTime[50];
static char **tagName,**tagValue,**ids,**output;; 
int tableFlag = 0;// 1 - soldier  2 - mentor  3 - guide
int recordAmount;
int fieldAmount;
int ctrlArray;
int hr, min, sec;
int day, month, year;



//==============================================================================
//							Function declaration section
//============================================================================== 
void initialize(char database[],char dir[]);
void finalize();
void addMember(char dir[],char database[],int panel,int ctrlArray,int status);
int getIndexOfControl(int panel,int ctrlArray,int count,char controlName[]);
void showMember(int panel,char dir[],char database[],char record[],int ctrlArray);
void connectIDtoName(char dir[],char database[],char record[],char fullName[]);
int connectNametoID(char dir[],char database[],char record[],char fullName[]); 
void createTable(char dir[],char database[], char **ids, int rows,int panel,int control,char *fields[],int fieldLen,char groupName[]);
void delTable();
int connectNametoIDS(char **records,char fullName[]);
int search(char searchBy[],char val[],char **output);
void clockDate();
void restoreSearch();
void displayGroupPanel(char groupName[]);
void searchSoldier(char mentorName[],char soldierName[]);
void searchFor(char dir[],char database[], char fieldName[], char valToCmp[],char valToCng[]);

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
	RecallPanelState (pMain, "panelState.txt", 0);
	restoreSearch();
	clockDate();
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
//							Exits Function
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
			{
				if(panel == pGroup)
				{//REMOVE TEXT FROM MENTOR'S BUTTONS
					int count;
					char tmp[SIZE];
					ctrlArray = GetCtrlArrayFromResourceID(pGroup,CA_MENTOR_BTN);
					GetNumCtrlArrayItems (ctrlArray, &count);
					for(int i=0;i<count;i++)
					{
						GetCtrlAttribute (pGroup, GetCtrlArrayItem(ctrlArray, i), ATTR_LABEL_TEXT, tmp);
						if(strcmp(tmp,"")!=0)//false
							SetCtrlAttribute (pGroup, GetCtrlArrayItem(ctrlArray, i), ATTR_LABEL_TEXT, "");
					}
								
				}
                HidePanel (panel);
			}
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
	char group1[SIZE],group2[SIZE],group3[SIZE];
	char *result;
	
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == pNewSold)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY);
				addMember(SOLDIER,"SOLDIER",panel,ctrlArray,1);
				HidePanel(panel);
				DisplayPanel(pSoldier);
				ctrlArray = GetCtrlArrayFromResourceID (pSoldier, CTRLARRAY_2);
				showMember(pSoldier,SOLDIER,"SOLDIER",id,ctrlArray);
			}
			else if(panel == pNewGuide)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_5);
				addMember(GUIDE,"GUIDE",panel,ctrlArray,1);
				HidePanel(panel);
				DisplayPanel(pGuide);
				ctrlArray = GetCtrlArrayFromResourceID (pGuide, CTRLARRAY_6);
				showMember(pGuide,GUIDE,"GUIDE",id,ctrlArray);
			}
			else if(panel == pNewMent)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_3);
				addMember(MENTOR,"MENTOR",panel,ctrlArray,1);
				HidePanel(panel);
				DisplayPanel(pMentor);
				ctrlArray = GetCtrlArrayFromResourceID (pMentor, CTRLARRAY_4);
				showMember(pMentor,MENTOR,"MENTOR",id,ctrlArray);
			}
			else if(panel == pNewGroup)
			{
				///////////////////////////////////////////////////
				GetCtrlVal (panel, P_NEW_GROU_CITY, group1);
				GetCtrlVal (panel, P_NEW_GROU_MONTH, group2);
				GetCtrlVal (panel, P_NEW_GROU_YEAR, group3);		//CREATE THE GROUP NAME
				result = malloc(strlen(group1)+strlen(group2)+strlen(group3)+1);
				strcpy(result,group1);
				strcat(result,group2);
				strcat(result,group3);
				SetCtrlVal (panel, P_NEW_GROU_ID_NUMBER, result);
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
				addMember(GROUP,"GROUP",panel,ctrlArray,1);
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

int CVICALLBACK Edit (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	int count;
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == pGroup)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CA_GROUP_EDIT);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_10);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
				ctrlArray = GetCtrlArrayFromResourceID (panel, CA_MENTOR_BTN);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_11);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_HOT);
			}
			else if (panel == pGuide)
			{		
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_GUIDE_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_12);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_HOT);	  
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_GUIDE_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
			}
			else if (panel==pMentor)
			{		
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_MENTOR_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_13);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_HOT);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_MENTOR_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
			}
			else if(panel==pSoldier)
			{
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_SOLDIER_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_2);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_HOT);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_SOLDIER_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);	
			}
			 
			
			break;
	}
return 0;
}

int CVICALLBACK TimeUpdate (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			clockDate();
			break;
	}
	return 0;
}

int CVICALLBACK SaveChanges (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	int count;
	switch (event)
	{
		case EVENT_COMMIT:
			if (panel == pGroup)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CA_GROUP_EDIT);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_10);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				ctrlArray = GetCtrlArrayFromResourceID (panel, CA_MENTOR_BTN);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_11);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_INDICATOR);
				/*char groupName[SIZE];
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_9);
				GetNumCtrlArrayItems (ctrlArray, &count);
				addMember(GROUP,"GROUP",panel,ctrlArray,0);	
				
				ctrlArray = GetCtrlArrayFromResourceID (panel, CA_GROUP_EDIT);
				GetNumCtrlArrayItems (ctrlArray, &count);
				for(int i=0;i<count;i++)
				{
					SetCtrlAttribute (panel, GetCtrlArrayItem(ctrlArray, i), ATTR_VISIBLE, 0);
				}
				SetCtrlAttribute (panel, P_GROUP_STATUS_RING, ATTR_CTRL_MODE, VAL_INDICATOR);
				SetCtrlAttribute (panel, P_GROUP_GUIDE, ATTR_CTRL_MODE, VAL_INDICATOR);*/
			}
			else if (panel==pGuide)
			{	
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_GUIDE_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_12);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_INDICATOR);	  
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_GUIDE_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				/*ctrlArray=GetCtrlArrayFromResourceID (panel, CA_GUIDE_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				
				/*ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_6);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_INDICATOR);
				addMember(GUIDE,"GUIDE",panel,ctrlArray,0); 
				
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_GUIDE_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);*/
			}
			else if (panel==pMentor)
			{		
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_MENTOR_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_13);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_INDICATOR);
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_MENTOR_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
				
				/*ctrlArray=GetCtrlArrayFromResourceID (panel, CA_MENTOR_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
				
				ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_4);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_INDICATOR);
				addMember(MENTOR,"MENTOR",panel,ctrlArray,0); 
				
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_MENTOR_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);*/
				
			} 
			else if(panel == pSoldier)
			{
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_SOLDIER_ACTION);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 0);
				
				ctrlArray=GetCtrlArrayFromResourceID (panel, CTRLARRAY_2);
				SetCtrlArrayAttribute (ctrlArray, ATTR_CTRL_MODE, VAL_INDICATOR);
				addMember(SOLDIER,"SOLDIER",panel,ctrlArray,0); 
				
				ctrlArray=GetCtrlArrayFromResourceID (panel, CA_SOLDIER_VIS);
				SetCtrlArrayAttribute (ctrlArray, ATTR_VISIBLE, 1);
			}
			break;
	}
	return 0;
}

int CVICALLBACK checkIfExist  (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)
{
	char database[SIZE],fullName[SIZE],dir[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlAttribute (panel, control, ATTR_CONSTANT_NAME, database);
			GetCtrlVal(panel,control,fullName);
			if(strcmp(database,"GUIDE")==0)
				sprintf(dir,GUIDE);
			else
				sprintf(dir,MENTOR);
			initialize(database,dir); 
			if(connectNametoID(dir,database,id,fullName)==0)//if the fullName does not excist return 0
				MessagePopup("Alert", "Record does not excist!");
				
			break;
	}
	return 0;
}

int CVICALLBACK changeVal (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	char database[SIZE], searchBy[SIZE], val[SIZE], dir[SIZE];
	char **fields;

	switch (event)
	{
		case EVENT_COMMIT:
			if(control == P_MAIN_SEARCH_RING)
			{
				GetCtrlVal (panel, P_MAIN_SEARCH_RING, database);
				if(strcmp(database,"GROUP")==0)
				{
					SetCtrlAttribute (panel, P_MAIN_SEARCH_BY_RING, ATTR_CTRL_INDEX, 1);
					SetCtrlAttribute (panel, P_MAIN_SEARCH_BY_RING, ATTR_CTRL_MODE, VAL_INDICATOR);
					SetCtrlAttribute (panel,P_MAIN_SEARCH_STRING, ATTR_VISIBLE, 1);
				}                           
				else					
				{   					
					SetCtrlAttribute (panel, P_MAIN_SEARCH_BY_RING, ATTR_CTRL_INDEX, 0);
					SetCtrlAttribute (panel, P_MAIN_SEARCH_BY_RING, ATTR_CTRL_MODE, VAL_HOT);
					SetCtrlAttribute (panel,P_MAIN_SEARCH_STRING, ATTR_VISIBLE, 0);
				}					
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
					tableFlag = 3;
				}
				else if(strcmp(database,"MENTOR")==0)
				{
					sprintf(dir,"%s",MENTOR);
					tableFlag = 2; 
				}
				else
				{
					sprintf(dir,"%s",SOLDIER);
					tableFlag = 1;
				}
				
				initialize(database,dir);
				output = malloc(sizeof(char*)*recordAmount);
				
				if(strcmp(database,"GROUP")==1) //not equal
				{
					int cc = search(searchBy,val,output);
					if(cc>=1)
					{
						fields = malloc(sizeof(char*)*2);
						fields[0] = malloc(sizeof(char)*strlen("שם פרטי")+1);
						sprintf(fields[0],"שם פרטי");
						fields[1] = malloc(sizeof(char)*strlen("שם משפחה")+1);
						sprintf(fields[1],"שם משפחה");
						restoreSearch();
						DisplayPanel(pTable);
						delTable(); 
						createTable(dir,database,output,cc,pTable,P_TABLE_LIST_S_OR_M,fields,2,"");
						free(fields);
					}
				}
				else
				{
					for(int i=0;i<recordAmount;i++)
					{
						Database_GetRecordInfo(id,i+1);

						if(strcmp(id,val)==0) //true
						{ 
							displayGroupPanel(id);
							restoreSearch();
						}
					}
				}
			}								   
			break;
	}
	return 0;
}

int CVICALLBACK delRecord (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	char idef[SIZE];
	int i,count;
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == pGroup)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_9);
				GetNumCtrlArrayItems (ctrlArray, &count);
				i = getIndexOfControl(panel,ctrlArray,count,"ID_NUMBER");
				GetCtrlVal(panel,GetCtrlArrayItem(ctrlArray, i),idef);
				initialize("GROUP",GROUP);
				Database_RemoveRecord(idef);
				searchFor(SOLDIER,"SOLDIER","קבוצה",idef,"קבוצה");
				searchFor(MENTOR,"MENTOR","קבוצה",idef,"קבוצה");
				searchFor(GUIDE,"GUIDE","קבוצה 1",idef,"קבוצה 1");
				searchFor(GUIDE,"GUIDE","קבוצה 2",idef,"קבוצה 2");
			}
			else if(panel == pGuide)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_6);
				GetNumCtrlArrayItems (ctrlArray, &count);
				i = getIndexOfControl(panel,ctrlArray,count,"ID_NUMBER");
				GetCtrlVal(panel,GetCtrlArrayItem(ctrlArray, i),idef);
				initialize("GUIDE",GUIDE);
				Database_RemoveRecord(idef);
				searchFor(SOLDIER,"SOLDIER","מנחה",idef,"מנחה");
				searchFor(MENTOR,"MENTOR","מנחה",idef,"מנחה");
			}
			else if(panel == pMentor)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_4);
				GetNumCtrlArrayItems (ctrlArray, &count);
				i = getIndexOfControl(panel,ctrlArray,count,"ID_NUMBER");
				GetCtrlVal(panel,GetCtrlArrayItem(ctrlArray, i),idef);
				initialize("MENTOR",MENTOR);
				Database_RemoveRecord(idef);
				searchFor(SOLDIER,"SOLDIER","מנטור",idef,"מנטור");
				
			}
			else if(panel == pSoldier)
			{
				ctrlArray = GetCtrlArrayFromResourceID (panel, CTRLARRAY_4);
				GetNumCtrlArrayItems (ctrlArray, &count);
				i = getIndexOfControl(panel,ctrlArray,count,"ID_NUMBER");
				GetCtrlVal(panel,GetCtrlArrayItem(ctrlArray, i),idef);
				initialize("MENTOR",MENTOR);
				Database_RemoveRecord(idef);
			}
			HidePanel(panel);
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
			initialize("GUIDE",GUIDE);
			
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
			initialize("GROUP",GROUP);
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
			GetCtrlAttribute (panel, control, ATTR_LABEL_TEXT, fullName);
			if(strcmp(fullName,"")!=0)
			{
				HidePanel(panel);
				DefaultCtrl (pGuide, P_GUIDE_GROUP_1);	DefaultCtrl (pGuide, P_GUIDE_GROUP_2);
				DisplayPanel(pGuide); 
				connectNametoID(GUIDE,"GUIDE",id,fullName);
				ctrlArray = GetCtrlArrayFromResourceID (pGuide, CTRLARRAY_6);
				showMember(pGuide,GUIDE,"GUIDE",id,ctrlArray);
				GetCtrlVal (pGuide, P_GUIDE_GROUP_1_STRING, group1);
				GetCtrlVal (pGuide, P_GUIDE_GROUP_2_STRING, group2);
				if(strcmp(group1,"קבוצה 1")==0)
				{
					sprintf(group1,"");
					SetCtrlAttribute (pGuide, P_GUIDE_GROUP_1, ATTR_VISIBLE, 0);
				}
				if(strcmp(group2,"קבוצה 2")==0)
				{
					sprintf(group2,"");
					SetCtrlAttribute (pGuide, P_GUIDE_GROUP_2, ATTR_VISIBLE, 0);
				}
				SetCtrlAttribute (pGuide, P_GUIDE_GROUP_1, ATTR_LABEL_TEXT, group1);
				SetCtrlAttribute (pGuide, P_GUIDE_GROUP_2, ATTR_LABEL_TEXT, group2); 
			}
			break;
	}
	return 0;
}

int CVICALLBACK openTable (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	char **fields;
	char fullName[SIZE],val[SIZE];
	int j=0;
	switch (event)
	{
		case EVENT_COMMIT:
			tableFlag = 1;
			delTable();
			DisplayPanel(pTable);
			GetCtrlVal (panel, P_GUIDE_ID_NUMBER, id);
			connectIDtoName(GUIDE,"GUIDE",id,fullName);
			initialize("SOLDIER",SOLDIER);
			ids = malloc(sizeof(char*)*(recordAmount));
			for(int i=1;i<=recordAmount;i++) 
			{
				Database_GetRecordInfo(id,i);
				Database_GetFieldVal(id,"מנחה",val);
				if(strcmp(fullName,val)==0)
				{
					ids[j] = malloc((char)strlen(id)+1);
					sprintf(ids[j],id);
					j++;
				}
			}
			if(j!=0)
			{
				fields = malloc(sizeof(char*)*2);
				fields[0] = malloc(sizeof(char)*strlen("שם פרטי")+1);
				sprintf(fields[0],"שם פרטי");
				fields[1] = malloc(sizeof(char)*strlen("שם משפחה")+1);
				sprintf(fields[1],"שם משפחה");
				createTable(SOLDIER,"SOLDIER",ids,j,pTable,P_TABLE_LIST_S_OR_M,fields,2,"");
				free(fields);
			}
			
			break;
	}
	return 0;
}

int CVICALLBACK OpenMentor (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	char lbl[SIZE],soldierName[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlAttribute (panel, control, ATTR_LABEL_TEXT, lbl);
			if(strcmp(lbl,"")==1)
			{
				HidePanel (pGroup);
				connectNametoID(MENTOR,"MENTOR",id,lbl);
				DisplayPanel(pMentor);
				ctrlArray = GetCtrlArrayFromResourceID (pMentor, CTRLARRAY_4);
				showMember(pMentor,MENTOR,"MENTOR",id,ctrlArray);
				searchSoldier(lbl,soldierName);
				SetCtrlAttribute (pMentor, P_MENTOR_SOLDIER_BUTTON, ATTR_LABEL_TEXT, soldierName);
			}
			break;
	}
	return 0;
}

int CVICALLBACK showGroup (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	char groupName[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlAttribute (panel, control, ATTR_LABEL_TEXT, groupName);
			if(strcmp(groupName,"")!=0)
				displayGroupPanel(groupName);
			break;
	}
	return 0;
}

int CVICALLBACK openSoldier (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(panel);
			DisplayPanel(pSoldier);
			ctrlArray = GetCtrlArrayFromResourceID (pSoldier, CTRLARRAY_2);
			showMember(pSoldier,SOLDIER,"SOLDIER",id,ctrlArray);
			break;
	}
	return 0;
}

int CVICALLBACK tblFunction (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	Point p;
	char val[SIZE];
	switch (event)
	{
			case EVENT_COMMIT:
				if(eventData2==3)
				{
					switch(tableFlag)
					{
						case 1: //SOLDIER
							ctrlArray = GetCtrlArrayFromResourceID (pSoldier, CTRLARRAY_2);
							GetActiveTableCell (panel, control, &p);
							GetTableCellVal (panel, control, p, val);
							DisplayPanel(pSoldier);
							showMember(pSoldier,SOLDIER,"SOLDIER",val,ctrlArray);
							break;
						case 2://MENTOR
							ctrlArray = GetCtrlArrayFromResourceID (pMentor, CTRLARRAY_4);
							GetActiveTableCell (panel, control, &p);
							GetTableCellVal (panel, control, p, val);
							DisplayPanel(pMentor);
							showMember(pMentor,MENTOR,"MENTOR",val,ctrlArray);
							break;
						case 3://GUIDE
							ctrlArray = GetCtrlArrayFromResourceID (pGuide, CTRLARRAY_6);
							GetActiveTableCell (panel, control, &p);
							GetTableCellVal (panel, control, p, val);
							DisplayPanel(pGuide);
							showMember(pGuide,GUIDE,"GUIDE",val,ctrlArray);
							break;
					}
					
				}
				else if(eventData2==1)
				{
					GetActiveTableCell (panel, control, &p); 
					GetTableCellVal(panel,control, p,val);
					GetTableCellVal (panel, control, MakePoint(3,eventData1), id);
					initialize("MENTOR",MENTOR); 
					if(strcmp(val,"Yes")==0)
					{
						GetCtrlVal (panel, P_TABLE_GNAME, val);
						Database_SetFieldVal(id,"קבוצה",val);
					}
					else
					{
						Database_SetFieldVal(id,"קבוצה","קבוצה");	
					}
				}
			break;
	}
	return 0;
}

int CVICALLBACK editMentorsInGroup (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	char **fields;
	char val[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
			tableFlag = 2;
			initialize("MENTOR",MENTOR);
			ids = malloc(sizeof(char*)*(recordAmount));
			for(int i=0;i<recordAmount;i++)
			{
				Database_GetRecordInfo(id,i+1);
				ids[i] = malloc((char)strlen(id)+1);
				sprintf(ids[i],id);
			}
			fields = malloc(sizeof(char*)*2);
			fields[0] = malloc(sizeof(char)*strlen("שם פרטי")+1);
			sprintf(fields[0],"שם פרטי");
			fields[1] = malloc(sizeof(char)*strlen("שם משפחה")+1);
			sprintf(fields[1],"שם משפחה");
			GetCtrlVal (panel, P_GROUP_GROUP_NAME, val);
			DisplayPanel(pTable);
			createTable(MENTOR,"MENTOR",ids,recordAmount,pTable,P_TABLE_LIST_S_OR_M,fields,2,val);
			SetCtrlVal (pTable, P_TABLE_GNAME,val );
			break;
	}
	return 0;
}

int CVICALLBACK openSoldierTable (int panel, int control, int event,
								  void *callbackData, int eventData1, int eventData2)
{
	char **fields; 
	int j=0,rows;
	switch (event)
	{
		case EVENT_COMMIT:
			tableFlag = 1;
			delTable();
			initialize("SOLDIER",SOLDIER);
			ids = malloc(sizeof(char*)*(recordAmount));
			for(int i=1;i<=recordAmount;i++) 
			{
				Database_GetRecordInfo(id,i);
				if(panel == pGroup)
				{
					char groupName[SIZE],sGroup[SIZE];
					GetCtrlVal (panel, P_GROUP_GROUP_NAME, groupName);
					Database_GetFieldVal(id,"קבוצה",sGroup);
					if(strcmp(groupName,sGroup)==0)
					{
						ids[j] = malloc((char)strlen(id)+1);
						sprintf(ids[j],id);
						j++;	
					}
				}
				else
				{
					ids[i-1] = malloc((char)strlen(id)+1);
					sprintf(ids[i-1],id);
				}
				
			}
			if(panel == pGroup)
				rows = j;
			else
				rows = recordAmount;
			fields = malloc(sizeof(char*)*2);
			fields[0] = malloc(sizeof(char)*strlen("שם פרטי")+1);
			sprintf(fields[0],"שם פרטי");
			fields[1] = malloc(sizeof(char)*strlen("שם משפחה")+1);
			sprintf(fields[1],"שם משפחה");
			restoreSearch();
			DisplayPanel(pTable);
			createTable(SOLDIER,"SOLDIER",ids,rows,pTable,P_TABLE_LIST_S_OR_M,fields,2,"");
			free(fields);
			break;
	}
	return 0;
}

//==============================================================================
//							Function realization section
//==============================================================================

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
void addMember(char dir[],char database[],int panel, int ctrlArray,int status)
{
	//status: add new member mode = 1 | edit mode =0
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
		if(Database_AddNewRecord(id,tagName,fieldAmount)==0 && status==1)
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

void createTable(char dir[],char database[], char **ids,int rows,int panel,int control,char *fields[],int fieldLen,char groupName[])
{ //status - if we create table for all soldiers = 1
  //		 if we create table for editing mentors = 2
	char str[SIZE],tmp[SIZE];
	initialize(database,dir);
	InsertTableRows (panel, control, -1, rows, VAL_CELL_STRING);
	InsertTableColumns (panel, control, -1, 3, VAL_CELL_STRING);
	
	for(int k=1;k<=3;k++)
	{
		SetTableColumnAttribute (panel, control, k, ATTR_SIZE_MODE, VAL_USE_EXPLICIT_SIZE);
		SetTableColumnAttribute (panel, control, k, ATTR_COLUMN_WIDTH, 150);
	}
	
	for(int i=0;i<rows;i++)
	{
		sprintf(str,"%s","");
		for(int j=0;j<fieldLen;j++)
		{
			Database_GetFieldVal(ids[i],fields[j],tmp);
			strcat(str,tmp);
			if(j+1<fieldLen)
				strcat(str," ");
		}
		strcat(str,"\0");
		SetTableCellVal (panel, control, MakePoint(2,i+1), str);
		SetTableCellAttribute (panel, control, MakePoint(2,i+1), ATTR_NO_EDIT_TEXT, 1);
		SetTableCellAttribute (panel, control, MakePoint(3,i+1), ATTR_CELL_TYPE, VAL_CELL_BUTTON);
		SetTableCellVal (panel, control,MakePoint(3,i+1) , ids[i]);
		SetTableCellAttribute (panel, control, MakePoint(1,i+1), ATTR_CELL_TYPE, VAL_CELL_RING);
		InsertTableCellRingItem (panel, control, MakePoint(1,i+1), 0, "No");
		InsertTableCellRingItem (panel, control, MakePoint(1,i+1), 1, "Yes");
		if(strcmp(groupName,"")==0)
			SetTableCellAttribute (panel, control, MakePoint(1,i+1), ATTR_CELL_DIMMED, 1);  
		else
		{
			SetTableCellAttribute (panel, control, MakePoint(1,i+1), ATTR_CELL_DIMMED, 0);
			for(int i=0;i<rows;i++)
			{
				Database_GetFieldVal(ids[i],"קבוצה",tmp);
				if(strcmp(tmp,groupName)==0)
				{
					SetTableCellVal(panel,control,MakePoint(1,i+1),"YES");
				}
			}
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
	SetCtrlAttribute (pMain, P_MAIN_SEARCH_BY_RING, ATTR_VISIBLE, 0);
	DefaultCtrl (pMain, P_MAIN_SEARCH_STRING);
	SetCtrlAttribute (pMain, P_MAIN_SEARCH_STRING, ATTR_VISIBLE, 0); 
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

void searchFor(char dir[],char database[], char fieldName[], char valToCmp[], char valToCng[])
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
			Database_SetFieldVal(id, fieldName,valToCng);
		}
	}
	
}

void delTable()
{
	DeleteTableRows (pTable, P_TABLE_LIST_S_OR_M, 1, -1);
	DeleteTableColumns (pTable, P_TABLE_LIST_S_OR_M, 1, -1);
}
