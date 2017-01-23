#include <cvirte.h>		
#include <userint.h>
#include "1.h"
#include "database.h"
#define SOLDIER "Database\\soldier.ini"
#define CONFIG "Database\\config.ini"

//==============================================================================
//							Variables section
//								SIZE = 300
//============================================================================== 
static int pMain, pActivity, pGuide, pNewGuide, pMentor, pNewMent, pSoldier, pNewSold;
static char id[SIZE];
//static char dbFile[SIZE];
static char **tagName,**tagValue,**ids;
int recordAmount;
int fieldAmount;
int soldierContorls[] = {P_NEW_SOLD_ID_NUMBER,P_NEW_SOLD_FIRST_NAME,
						 P_NEW_SOLD_LAST_NAME,P_NEW_SOLD_PHONE_NUMBER,
						P_NEW_SOLD_MAIL,P_NEW_SOLD_MAIL,P_NEW_SOLD_ADDRESS,P_NEW_SOLD_AGE,P_NEW_SOLD_GUIDE,
						P_NEW_SOLD_MENTOR, P_NEW_SOLD_IMAGE};


//==============================================================================
//							Function declaration section
//============================================================================== 
void initialize(char database[]);
void finalize();
void addMember(char dir[],char database[],int memberControl[],int panel);


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

//////////////////////////////////
//      Adding a new soldier	//
//////////////////////////////////

int CVICALLBACK Save_Sol_Func (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)

{
	switch (event)
	{
		case EVENT_COMMIT:
			addMember(SOLDIER,"SOLDIER",soldierContorls,panel);
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

//==============================================================================
//							Function realization section
//============================================================================== 

void initialize(char database[])
{
	Database_SetDatabaseFile(CONFIG);
	Database_CountAllFields(database,&fieldAmount);  
	tagName = malloc(sizeof(char*)*(fieldAmount));
	tagValue = malloc(sizeof(char*)*(fieldAmount));
	Database_GetRecordValues(database,fieldAmount,tagName,tagValue);
}

void finalize()
{
	free(ids);free(tagName);free(tagValue);
}

void addMember(char dir[],char database[],int memberControl[],int panel)
{
	//dir - directory of the inifile. use defined var SOLDIER,MENTOR,etc
	//database - the name of the database as set in the config.ini. "SOLDIER", "MENTOR",etc
	//memberContor - array of the controls in  the panel.
	//panel - panel handle the active panel - send panel. 
	char tmpVal[SIZE],tmpName[SIZE];
	initialize(database); //CAPITAL LETTER IN CONFIG.INI
	GetCtrlVal (panel, memberControl[0], id);
	Database_SetDatabaseFile(dir);
	if(Database_AddNewRecord(id,tagName,fieldAmount)==0)
		MessagePopup("Error", "ID already exist");
	else
	{
		for(int i=0;i<9;i++)
		{
			GetCtrlVal (panel, memberControl[i+1], tmpVal); 
			GetCtrlAttribute (panel, memberControl[i+1], ATTR_LABEL_TEXT, tmpName);
			Database_SetFieldVal(id,tmpName,tmpVal);
		}
	}
}

