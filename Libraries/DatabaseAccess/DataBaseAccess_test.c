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
static char **tagName,**tagValue,**ids;
static IniText iniHandle;
int recordAmount,fieldAmount;
Point p;
int autofill;

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
	initialize("config.ini");
	RunUserInterface ();
	free(ids);free(tagName);free(tagValue);
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
				DisplayPanel (panelHandle2);
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
			initialize("amit.ini");
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
				GetTableColumnAttribute (panel, control, p.x, ATTR_LABEL_TEXT, tag);
				GetTableCellVal (panel, control, p, val);
				setFieldVal(iniHandle,id, tag , val); 
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
	if(!strcmp(name,"config.ini"))
	{
		tagName = malloc(sizeof(char*)*countAllFields(iniHandle,"CONFIG"));
		tagValue = malloc(sizeof(char*)*countAllFields(iniHandle,"CONFIG"));
	}
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
			  //HebrewConverter_convertHebrewISOtoUTF8(id);
			  if(addNewRecord(iniHandle,id,tagName,fieldAmount)==0)
				  MessagePopup("Error", "ID already exist");
			  else
			  	SetInTable(panel,PANEL_3_TABLE);
			break;
	}
	return 0;
}

int CVICALLBACK btnDelRecord (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			PromptPopup ("Delete Record", "Enter ID to delete", id, 100);
			if(removeRecord(iniHandle,id)==0)
				MessagePopup ("Error", "ID");
			else
				SetInTable(panel,PANEL_3_TABLE);
			break;
	}
	return 0;
}

int checkFieldInDB(char db[],int j)
{
	int count;
	char f[SIZE],v[SIZE];
	initialize(db);
	GetCtrlVal (panelHandle2, PANEL_2_SBFIELD, f);
	//HebrewConverter_convertHebrewUTF8toISO(f);
	GetCtrlVal (panelHandle2, PANEL_2_SBFIELDVAL, v);
	//HebrewConverter_convertHebrewUTF8toISO(v);
	count = getNumberOfIdsFromField(iniHandle,f,v);
	ids= getRecordIdsFromField(iniHandle, f ,v ,ids);
	InsertTableRows (panelHandle2, PANEL_2_TABLE, -1, count, VAL_CELL_STRING);
	for(int i=0;i<count;i++ )
	{
		SetTableCellVal (panelHandle2, PANEL_2_TABLE, MakePoint(1,j+i+1), ids[i]);
	}
	return count;
}

int checkByID(char db[])
{
	initialize(db);
	GetCtrlVal (panelHandle2, PANEL_2_SBYID, id);
	fieldAmount = countAllFields(iniHandle,id);
			
	if(search(iniHandle,id, fieldAmount,tagName,tagValue)==-1)
		return 0;
	else
	{
		delTable(panelHandle2,PANEL_2_TABLE);
		InsertTableRows (panelHandle2, PANEL_2_TABLE, -1, fieldAmount, VAL_CELL_STRING);
		InsertTableColumns (panelHandle2, PANEL_2_TABLE, -1, 2, VAL_CELL_STRING);
		for(int j=1;j<=fieldAmount;j++)
		{
			SetTableCellVal (panelHandle2, PANEL_2_TABLE, MakePoint(2,j), tagValue[j-1]);
			SetTableCellVal (panelHandle2, PANEL_2_TABLE, MakePoint(1,j), tagName[j-1]);
		}
		return 1;
	}
}
int CVICALLBACK searchBy (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			delTable(panel,PANEL_2_TABLE);
			if(control == PANEL_2_BTNID)
			{
				if(checkByID("amit.ini")==0)
					if(checkByID("mentor.ini")==0)
						MessagePopup("Error","Id was not found");
				
			}
			else if(control == PANEL_2_BTNFIELD)
			{
				InsertTableColumns (panelHandle2, PANEL_2_TABLE, -1, 1, VAL_CELL_STRING);
				int count = checkFieldInDB("amit.ini",0);
				checkFieldInDB("mentor.ini",count);
			}
			break;
	}
	return 0;
}

int CVICALLBACK test (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{//Doesnt work 
	char **lib,**d;
	int k=0;
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_VAL_CHANGED:
			autofill = NewCtrl (panelHandle2, CTRL_LIST, "", 250, 162);
			SetCtrlAttribute (panelHandle2, autofill, ATTR_WIDTH, 194);
			SetCtrlAttribute (panelHandle2, autofill, ATTR_TEXT_CHARACTER_SET, VAL_HEBREW_CHARSET);
			char str[SIZE];
			GetCtrlVal (panelHandle2, PANEL_2_SBYID, str);
			initialize("amit.ini");
			int a = countAllRecords(iniHandle);
			lib = malloc(sizeof(char*)*a);
			d = malloc(sizeof(char*)*a);
			for(int i=0;i<a;i++)
			{
				Ini_NthSectionName (iniHandle, i+1, &lib[i]);
			}
			k = getAutofill(iniHandle,countAllRecords(iniHandle),str, lib,d);
			for(int i=0;i<k;i++)
			{
				InsertListItem (panelHandle2, autofill, -1, d[i], i);
			}
			break; 
	}
	return 0;
}
