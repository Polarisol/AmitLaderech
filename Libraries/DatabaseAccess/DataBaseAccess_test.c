#include <ansi_c.h>
#include <utility.h>
#include <cvirte.h>		
#include <userint.h>
#include "DataBaseAccess_test.h"
#include "database.h"

static int panelHandle;
static int num_of_files = 0;
static char dbFile[SIZE][300];


void initialize();

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "DataBaseAccess_test.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	initialize(0);
	RunUserInterface ();
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
			QuitUserInterface (0);
			break;
	}
	return 0;
}

/* ------------------------------------
Add a new line to the table.
int addNewRecord(char id[]);
-------------------------------------*/
int CVICALLBACK btnRecored (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			InsertTableRows (panelHandle, PANEL_TABLE, -1, 1, VAL_CELL_STRING);
			//addNewRecord(char id[]);
			//countAllRecords(*amount);
			break;
	}
	return 0;
}

/* ------------------------------------
Add a new column to the table.
int addNewField(char id[], char field[], char value[]);
-------------------------------------*/
int CVICALLBACK btnField (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			InsertTableColumns (panelHandle, PANEL_TABLE, -1, 1, VAL_CELL_STRING);
			//addNewField(char id[], char field[], char value[]);
			break;
	}
	return 0;
}

/* ------------------------------------
Add a new column to the table.
int setFieldVal(char id[], char field[], char value[]); 
-------------------------------------*/
int CVICALLBACK tblFunc (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{//eventData1 = TRUE if entering edit mode; FALSE if leaving edit mode
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

/* ------------------------------------
Create a new database file or open a database file
-------------------------------------*/
int CVICALLBACK ringFunc (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	int op;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_RING, &op);
			if(op == num_of_files)
			{
				num_of_files++;
				PromptPopup ("Create new", "Enter name for the database", dbFile[num_of_files],300 );
				if(setDatabaseFile(dbFile[num_of_files]))
					initialize(num_of_files-1);
				else
					MessagePopup("Error", "Fail to create database");
			}
			else
			{
				MessagePopup("read","read from ini file and put in table");
				GetCtrlVal (panelHandle, PANEL_RING, &op);
				getDatabaseFile(dbFile[op]);
			}
							  
			break;
	}
	return 0;
}

/* ------------------------------------
Check if database files were created and add them to PANEL_RING
-------------------------------------*/
void initialize(int active)
{
	char file[300]; 
	ClearListCtrl (panelHandle, PANEL_RING);
	num_of_files = 0;
	if(!GetFirstFile ("Database\\*.ini", 1, 0, 0, 0, 0, 0, file))
	{
		InsertListItem (panelHandle, PANEL_RING, 0, file, 0);
		strcpy (dbFile[num_of_files], file);
		num_of_files++;
		while (!GetNextFile (file))
		{
			InsertListItem (panelHandle, PANEL_RING, num_of_files, file, num_of_files);
			strcpy (dbFile[num_of_files], file);
			num_of_files++;
		}
	}
	InsertListItem (panelHandle, PANEL_RING, num_of_files, "Add new...", num_of_files);
	SetCtrlVal (panelHandle, PANEL_RING, active);
	//read .ini file using 
	//getDatabaseFile(file); 
	//countAllRecords(*amount); 
	//getFieldVal(char id[], char field[], char value[]); 
}
