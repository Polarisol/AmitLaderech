#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Functions.h"

#include "Func_Header.h"


static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Functions.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
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

int CVICALLBACK find_num_records (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	char file_name[300];
	int num;
				
	switch (event)
	{
		case EVENT_COMMIT:
					GetCtrlVal (panelHandle, PANEL_STRING_1, file_name);

					num = CSVParser_GetNumberOfRecords(file_name);
					SetCtrlVal (panelHandle, PANEL_NUMERIC_1, num);
				
		break;
	}
	return 0;
}

int CVICALLBACK add (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	char file_name[300];
	int num;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panelHandle,PANEL_NUMERIC_3, &num);
			GetCtrlVal(panelHandle,PANEL_STRING_3, file_name);
			CSVParser_MarkAsProcessed(file_name,num);
			
			break;
	}
	return 0;
}

int CVICALLBACK find_new_records (int panel, int control, int event,
								  void *callbackData, int eventData1, int eventData2)
{
	char file_name[300];
	int new_records;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_STRING_2, file_name);
			new_records = CSVParser_NewRecords(file_name);
			SetCtrlVal (panelHandle, PANEL_NUMERIC_2, new_records);
			SetCtrlVal (panelHandle, PANEL_NUMERIC_3, new_records); 
			break;
	}
	return 0;
}

int CVICALLBACK test (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{

	char line[300];	
	char** list = NULL;
	int num_of_values;
	
	
	switch (event)
	{
		case EVENT_COMMIT:
				
			GetCtrlVal (panelHandle, PANEL_STRING, line);
			list = CSV_Analyzer(line, &num_of_values);
			InsertTableRows (panelHandle, PANEL_TABLE, -1, num_of_values, VAL_CELL_STRING);
			for(int i=1 ; i<=num_of_values; i++)
			{
				SetTableCellVal (panelHandle, PANEL_TABLE, MakePoint(1,i), list[i-1]);
				
			}
			
				
				
			break;
	}
	return 0;
}

int CVICALLBACK GetFieldFromRecord (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	int SIZE=300;
	char file_name[SIZE];
	int record_num;
	char field_name[SIZE];
	char value[SIZE];
	int status;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal (panelHandle, PANEL_RECORD_NUM, &record_num);
			GetCtrlVal (panelHandle, PANEL_S_FILE_NAME, file_name);
			GetCtrlVal (panelHandle, PANEL_S_FIELD_NAME, field_name);
			
			status = CSVParser_GetFieldFromRecord(file_name, record_num, field_name, value); 
			if(status==1)
			SetCtrlVal (panelHandle, PANEL_FIELD_RESULT, value);
			else
			SetCtrlVal (panelHandle, PANEL_FIELD_RESULT, "Error");	
			
			break;
	}
	return 0;
}

int CVICALLBACK CountAllRecordsWithFieldValue (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int SIZE=300;
	char file_name[SIZE];
	int num_of_records;
	char field_name[SIZE];
	char value[SIZE];
	int status;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_S_VAL, value);
			GetCtrlVal (panelHandle, PANEL_S_FILE_NAME_2, file_name);
			GetCtrlVal (panelHandle, PANEL_S_FIELD_NAME_2, field_name);
			
			num_of_records = CSVParser_CountAllRecordsWithFieldValue(file_name, field_name, value);
			
			SetCtrlVal (panelHandle, PANEL_RECORD_NUM_2, num_of_records);
			break;
	}
	return 0;
}
