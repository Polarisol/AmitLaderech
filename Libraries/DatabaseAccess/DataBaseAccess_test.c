#include "inifile.h"
#include <ansi_c.h>
#include <utility.h>
#include <cvirte.h>		
#include <userint.h>
#include "DataBaseAccess_test.h"
#include "database.h"
#include "HebrewConversions.h"

static int panelHandle,panelHandle2,panelHandle3;
static char id[SIZE];
static char dbFile[SIZE];
static char *tagName[100],*tagValue[100];
static IniText iniHandle;
int recordAmount,fieldAmount;
Point p;

void initialize(char name[]);
void SetInTable(int panel,int control);
void delTable(int panel,int control);

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
				MessagePopup("Message","ID was not found");
			else
			{
				DisplayPanel (panelHandle2);
				delTable(panelHandle2,PANEL_2_TABLE);
				InsertTableRows (panelHandle2, PANEL_2_TABLE, -1, fieldAmount, VAL_CELL_STRING);
				InsertTableColumns (panelHandle2, PANEL_2_TABLE, -1, 2, VAL_CELL_STRING);
				for(int j=1;j<=fieldAmount;j++)
				{
					SetTableCellVal (panelHandle2, PANEL_2_TABLE, MakePoint(2,j), tagValue[j-1]);
					SetTableCellVal (panelHandle2, PANEL_2_TABLE, MakePoint(1,j), tagName[j-1]);
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
			initialize("Amit.ini");
			DisplayPanel(panelHandle3);
			SetInTable(panelHandle3,PANEL_3_TABLE);
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
			initialize("mentor.ini");
			DisplayPanel(panelHandle3);
			SetInTable(panelHandle3,PANEL_3_TABLE);
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


int CVICALLBACK tblFunc (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	char tag[SIZE],val[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:
		
			break;
		case EVENT_EDIT_MODE_STATE_CHANGE:
			if(eventData1)
				GetActiveTableCell (panel, control, &p);
			if(!eventData1)
			{ 
				GetTableRowAttribute (panel, control, p.y, ATTR_LABEL_TEXT, id);
				HebrewConverter_convertHebrewISOtoUTF8(id);
				GetTableColumnAttribute (panel, control, p.x, ATTR_LABEL_TEXT, tag);
				HebrewConverter_convertHebrewISOtoUTF8(tag);
				GetTableCellVal (panel, control, p, val);
				HebrewConverter_convertHebrewISOtoUTF8(val);
				Ini_PutRawString (iniHandle, "20", tag, val);
				Ini_WriteToFile (iniHandle, dbFile);
				//setFieldVal(char id[], char field[], char value[]); 
				MessagePopup("event","updated");
			}
			break;
	}
	return 0;
}

void initialize(char name[])
{
	sprintf(dbFile,"%s",name);
	iniHandle = getDatabaseFile(name);
	if(iniHandle == 0)		 
		MessagePopup ("Error", "No database found");
}

void delTable(int panel,int control)
{
	DeleteTableRows (panel, control, 1, -1);
	DeleteTableColumns (panel, control, 1, -1);
}

void SetInTable(int panel,int control)
{
	
	delTable(panel,control);
	SetPanelAttribute (panel, ATTR_TITLE, dbFile);
	recordAmount = countAllRecords(iniHandle); 
	InsertTableRows (panel, control, -1, recordAmount, VAL_CELL_STRING);
	for(int i=1;i<=recordAmount;i++)
		{
			sprintf(id,"%s",getRecordInfo(iniHandle,id,i));
			fieldAmount = countAllFields(iniHandle,id);
					
			search(iniHandle,id,fieldAmount,tagName,tagValue);
			SetTableRowAttribute (panel, control, i, ATTR_USE_LABEL_TEXT, 1);
			SetTableRowAttribute (panel, control, i, ATTR_LABEL_TEXT, id);
				
			for(int j=1;j<=fieldAmount;j++)
			{
				if(i==1)//check if this is the loop's fist run.if true create the columns. need to think on a diffrent way
					InsertTableColumns (panel, control, -1, 1, VAL_CELL_STRING); 
				SetTableCellVal (panel, control, MakePoint(j,i), tagValue[j-1]);
				SetTableColumnAttribute (panel, control, j, ATTR_USE_LABEL_TEXT, 1);
				SetTableColumnAttribute (panel, control, j, ATTR_LABEL_TEXT, tagName[j-1]);
					  
			}
					
		}
}


int CVICALLBACK btnNewRec (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			  PromptPopup ("New Record","Enter ID", id, 12);
			  HebrewConverter_convertHebrewISOtoUTF8(id);
			  if(addNewRecord(iniHandle,id,tagName,fieldAmount)==0)
				  MessagePopup("Error", "ID already exist");
			  else
			  	SetInTable(panel,PANEL_3_TABLE);
			break;
	}
	return 0;
}
