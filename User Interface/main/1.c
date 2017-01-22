#include <cvirte.h>		
#include <userint.h>
#include "1.h"
#include "database.h"
#define SOLDIER "Database\\soldier.ini"
#define CONFIG "Database\\config.ini"

//==============================================================================
//							Variables section
//============================================================================== 
static int pMain,pActivity,pNewSold;
static char id[SIZE];
static char dbFile[SIZE];
static char **tagName,**tagValue,**ids;
int recordAmount;
int fieldAmount;


//==============================================================================
//							Function declaration section
//============================================================================== 
void initialize(char name[]);
void finalize();

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((pMain = LoadPanel (0, "1.uir", P_MAIN)) < 0)
		return -1;
	if ((pActivity = LoadPanel (0, "1.uir", P_ACTIVITY)) < 0)
		return -1;
	if ((pNewSold = LoadPanel (0, "1.uir", P_NEW_SOLD)) < 0)
		return -1;
	DisplayPanel (pMain);
	RunUserInterface ();
	finalize();
	DiscardPanel (pMain);
	return 0;
}


////////////////////////
// Exits Functions    //
////////////////////////


int CVICALLBACK exitActivity (int panel, int event, void *callbackData,
							  int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			DiscardPanel (pActivity);
			break;
	}
	return 0;
}

int CVICALLBACK exitMain (int panel, int event, void *callbackData,
						  int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK exitSoldier (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK exitGuide (int panel, int event, void *callbackData,
						   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK exitNewMentor (int panel, int event, void *callbackData,
							   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK exitNewSoldier (int panel, int event, void *callbackData,
								int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			DiscardPanel (pNewSold);
			break;
	}
	return 0;
}

int CVICALLBACK exitNewGuide (int panel, int event, void *callbackData,
							  int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK exitMentor (int panel, int event, void *callbackData,
							int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
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
	char tmpVal[SIZE],tmpName[SIZE];	
	switch (event)
	{
		case EVENT_COMMIT:
			initialize("SOLDIER");
			GetCtrlVal (panel, P_NEW_SOLD_ID_NUMBER, id);
			Database_SetDatabaseFile(SOLDIER);
			if(Database_AddNewRecord(id,tagName,fieldAmount)==0)
				  MessagePopup("Error", "ID already exist");
			else
			  {
				 GetCtrlVal (panel, P_NEW_SOLD_FIRST_NAME, tmpVal); 
				 GetCtrlAttribute (panel, P_NEW_SOLD_FIRST_NAME, ATTR_LABEL_TEXT, tmpName);
				 Database_SetFieldVal(id,tmpName,tmpVal);
				 HidePanel(panel);
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

void initialize(char name[])
{
	Database_SetDatabaseFile(CONFIG);
	Database_CountAllFields(name,&fieldAmount);  
	Database_CountAllRecords(&recordAmount);
	tagName = malloc(sizeof(char*)*(fieldAmount));
	tagValue = malloc(sizeof(char*)*(fieldAmount));
	for(int i=1;i<=recordAmount;i++)
	{
		Database_GetRecordValues(name,fieldAmount,tagName,tagValue);
	}
}

void finalize()
{
	free(ids);free(tagName);free(tagValue);
}

