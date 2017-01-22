#include <cvirte.h>		
#include <userint.h>
#include "1.h"
#include "database.h"
#define SOLDIER "Database\\soldier.ini"

static int pMain,pActivity,pNewSold;

static char **tagName , **tagValue;
int RecordAmount,FieldAmount;

void initialize(char name[]);

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
	char ID[10];
	int amount;
	char tagName[10][300];
	
	switch (event)
	{
		case EVENT_COMMIT:

			Database_SetDatabaseFile (SOLDIER);
			GetCtrlAttribute (panel, P_NEW_SOLD_ID_NUMBER, ATTR_XYNAME_BOLD, ID);
			initialize(SOLDIER);
			Database_AddNewRecord (ID , *tagname, amount); 
			
			
			 
			break;
	}
	return 0;
}

void initialize(char name[])
{
	if (Database_SetDatabaseFile(name)==1)
	{
		Database_CountAllFile (name,&FieldAmount);
		tagName = malloc (sizeof(char *)*FieldAmount);
		tagValue = malloc (sizeof(char *)*FieldAmount);
	}
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

