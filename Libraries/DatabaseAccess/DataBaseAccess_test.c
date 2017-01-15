#include "inifile.h"
#include <ansi_c.h>
#include <utility.h>
#include <cvirte.h>		
#include <userint.h>
#include "DataBaseAccess_test.h"
#include "database.h"
#include "HebrewConversions.h"

#define AMIT "Database\\amit.ini"
#define MENTOR "Database\\mentor.ini"
#define CONFIG "Database\\config.ini"

static int panelHandle,panelHandle2,panelHandle3;
static char id[SIZE];
static char dbFile[SIZE];
static char **tagName,**tagValue,**ids;
int recordAmount;
int fieldAmount;
Point p;
int autofill;

void initialize(char name[]);
void SetInTable(int panel,int control);
void delTable(int panel,int control);
void finalize();
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
	initialize(CONFIG);
	RunUserInterface ();
	finalize();
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
			initialize(AMIT);
			//char ss[100];
			//Database_GetFieldVal("203059936","name",ss);
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
			initialize(MENTOR);
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
				Database_SetFieldVal(id, tag , val); 
				MessagePopup("event","updated");
			}
			break;
	}
	return 0;
}

void initialize(char name[])
{
	if(Database_SetDatabaseFile(name)==1)
	{
		if(!strcmp(name,CONFIG))
		{			 
			Database_CountAllFields("CONFIG",&fieldAmount);
			tagName = malloc(sizeof(char*)*fieldAmount);
			tagValue = malloc(sizeof(char*)*fieldAmount);
		}
	}
	else		 
		MessagePopup ("Error", "No database found");
}

void finalize()
{
	free(ids);free(tagName);free(tagValue);
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
	Database_CountAllRecords(&recordAmount); 
	InsertTableRows (panel, control, -1, recordAmount, VAL_CELL_STRING);
	for(int i=1;i<=recordAmount;i++)
		{
			Database_GetRecordInfo(id,i);
			Database_CountAllFields(id,&fieldAmount);
					
			Database_GetRecordValues(id,fieldAmount,tagName,tagValue);
			HebrewConverter_convertHebrewUTF8toISO(tagValue[i]);
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
			  if(Database_AddNewRecord(id,tagName,fieldAmount)==0)
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
			if(Database_RemoveRecord(id)==0)
				MessagePopup ("Error", "ID");
			else
				SetInTable(panel,PANEL_3_TABLE);
			break;
	}
	return 0;
}

int checkFieldInDB(char db[],int j)
{
	int count=0;
	char f[SIZE],v[SIZE];
	initialize(db);
	GetCtrlVal (panelHandle2, PANEL_2_SBFIELD, f);
	GetCtrlVal (panelHandle2, PANEL_2_SBFIELDVAL, v);
	Database_GetNumberOfIdsFromField(f,v,&count);
	ids = malloc(sizeof(char*)*count); 
	Database_GetRecordIdsFromField(f ,v ,ids);
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
	Database_CountAllFields(id,&fieldAmount);
			
	if(Database_GetRecordValues(id, fieldAmount,tagName,tagValue)==-1)
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
				if(checkByID(AMIT)==0)
					if(checkByID(MENTOR)==0)
						MessagePopup("Error","Id was not found");
				
			}
			else if(control == PANEL_2_BTNFIELD)
			{
				InsertTableColumns (panelHandle2, PANEL_2_TABLE, -1, 1, VAL_CELL_STRING);
				int count = checkFieldInDB(AMIT,0);
				checkFieldInDB(MENTOR,count);
			}
			break;
	}
	return 0;
}

int CVICALLBACK test (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{ 
	char **d;
	int k=0,a=0;
	char str[SIZE];
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_VAL_CHANGED:
			GetCtrlVal (panelHandle2, PANEL_2_SBYID, str);
			DeleteListItem (panel, PANEL_2_AUTOFILL, 0, -1);
			SetCtrlAttribute (panel, PANEL_2_AUTOFILL, ATTR_VISIBLE, 1);
			initialize("Database\\amit.ini");
			Database_CountAllRecords(&a);
			d = malloc(sizeof(char*)*a);
			
			k = Database_GetAutofillId(str,d);
			for(int i=0;i<k;i++)
			{
				InsertListItem (panelHandle2, PANEL_2_AUTOFILL, -1, d[i], i);
			}
			free(d);
			break; 
	}
	return 0;
}

int CVICALLBACK autofillFunc (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	char str[SIZE];
	int index;
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute(panel, PANEL_2_AUTOFILL, ATTR_VISIBLE, 0);
			GetCtrlVal (panel, PANEL_2_AUTOFILL, &index);
			GetLabelFromIndex (panel, PANEL_2_AUTOFILL, index, str);
			SetCtrlVal (panel, PANEL_2_SBYID, str);
			break;
	}
	return 0;
}

int CVICALLBACK btnNewField (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	char value[SIZE+1];
	switch (event)
	{
		case EVENT_COMMIT:
			PromptPopup ("Add new", "Enter new field name", value, SIZE);
			if(Database_AddNewFieldAll(value,NULL)==0)
				MessagePopup("Alert","already exist"); 
			//PromptPopup ("Remove field", "Enter field to remove", value, SIZE);  
			//if(Database_RemoveFieldAll(value)==0)
				//MessagePopup("Alert","field does not exist");
			//Database_SetDatabaseFile(CONFIG); 
			Database_AddNewFieldAll(value,value);
			//initialize(CONFIG);
			initialize(AMIT);
			SetInTable(panel,PANEL_3_TABLE);
			break;
	}
	return 0;
}
