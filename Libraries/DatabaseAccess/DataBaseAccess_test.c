#include "inifile.h"
#include <ansi_c.h>
#include <utility.h>
#include <cvirte.h>		
#include <userint.h>
#include "DataBaseAccess_test.h"
#include "database.h"

static int panelHandle,panelHandle2,panelHandle3;
static int num_of_files = 0;
static char dbFile[SIZE];
static char id[SIZE];
static char *tagName[100],*tagValue[100];
static IniText iniHandle;
int recordAmount,fieldAmount;


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "DataBaseAccess_test.uir", PANEL)) < 0)
		return -1;
	if ((panelHandle2 = LoadPanel (0, "DataBaseAccess_test.uir", PANEL_2)) < 0)
		return -1;
	if ((panelHandle3 = LoadPanel (0, "DataBaseAccess_test.uir", PANEL_3)) < 0)
		return -1;
	iniHandle = Ini_New (0);
	Ini_ReadFromFile (iniHandle, "Database\\amit.ini");

	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle3);
	DiscardPanel (panelHandle2);
	DiscardPanel (panelHandle);
	return 0;
}

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
			if(panel == PANEL)
				QuitUserInterface (0);
			else
				HidePanel (panel);
			break;
	}
	return 0;
}



 

int CVICALLBACK btnSearch (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			PromptPopup ("Search", "Enter ID number", id, 12);
			fieldAmount = countAllFields(iniHandle,id);
			if(search(iniHandle,id, fieldAmount,tagName,tagValue)==-1)
				MessagePopup("asf","no");
			else
			{
				DisplayPanel (panelHandle2);
				recordAmount = countAllRecords(iniHandle);
				InsertTableRows (panelHandle2, PANEL_2_TABLE, -1, recordAmount, VAL_CELL_STRING);
				InsertTableColumns (panelHandle2, PANEL_2_TABLE, -1, fieldAmount, VAL_CELL_STRING);
				for(int i=1;i<=recordAmount;i++)
				{
					 for(int j=1;j<=fieldAmount;j++)
					 {
						 char str[100];
						 SetTableCellVal (panelHandle2, PANEL_2_TABLE, MakePoint(j,i), tagValue[j-1]);
						 SetTableColumnAttribute (panelHandle2, PANEL_2_TABLE, j, ATTR_USE_LABEL_TEXT, 1);
						 SetTableColumnAttribute (panelHandle2, PANEL_2_TABLE, j, ATTR_LABEL_TEXT, tagName[j-1]);
					  
					 }
				}
			}
			


			break;
	}
	return 0;
}

int CVICALLBACK btnAmit (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel(panelHandle3);
			recordAmount = countAllRecords(iniHandle);
			

				InsertTableRows (panelHandle3, PANEL_3_TABLE, -1, recordAmount, VAL_CELL_STRING);
				InsertTableColumns (panelHandle3, PANEL_3_TABLE, -1, fieldAmount, VAL_CELL_STRING);
				for(int i=1;i<=recordAmount;i++)
				{
					getRecordInfo(iniHandle,id,1);
					search(iniHandle,id,recordAmount,tagName,tagValue);
					fieldAmount = countAllFields(iniHandle,id);
					 for(int j=1;j<=fieldAmount;j++)
					 {
						 char str[100];
						 SetTableCellVal (panelHandle3, PANEL_3_TABLE, MakePoint(j,i), tagValue[j-1]);
						 SetTableColumnAttribute (panelHandle3, PANEL_3_TABLE, j, ATTR_USE_LABEL_TEXT, 1);
						 SetTableColumnAttribute (panelHandle3, PANEL_3_TABLE, j, ATTR_LABEL_TEXT, tagName[j-1]);
					  
					 }
				}
			break;
	}
	return 0;
}

int CVICALLBACK btnMentor (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy (dbFile, "Data\\mentor.ini");
			DisplayPanel(panelHandle3);
			break;
	}
	return 0;
}

int CVICALLBACK btnAmout (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}


	

int CVICALLBACK tblFuncSearch (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_EDIT_MODE_STATE_CHANGE:
			if(!eventData1)
			{
				//setFieldVal(char id[], char field[], char value[]); 
				MessagePopup("event","updated");
			}
			break;
	}
	return 0;
}

int CVICALLBACK btnDelete (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK tblFunc (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			break;
		case EVENT_EDIT_MODE_STATE_CHANGE:
			if(!eventData1)
			{
				//setFieldVal(char id[], char field[], char value[]); 
				MessagePopup("event","updated");
			}
			break;
	}
	return 0;
}
