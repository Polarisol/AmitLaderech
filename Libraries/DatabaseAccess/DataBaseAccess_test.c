#include <cvirte.h>		
#include <userint.h>
#include "DataBaseAccess_test.h"
#include "database.h"

static int panelHandle;

void initialize();

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "DataBaseAccess_test.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	initialize();
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
{
	switch (event)
	{
		case EVENT_COMMIT:
				MessagePopup("Update","Field was updated!");
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
			switch(op)
			{
				case -1:
					break;
				case 0:
					//create new database file
				default:
					//open database file
					//initialize the table using
					//int getFieldVal(char id[], char field[], char value[]);
					break;
			}
			break;
	}
	return 0;
}

/* ------------------------------------
Check if database files were created and add them to PANEL_RING
-------------------------------------*/
void initialize()
{
	
}
