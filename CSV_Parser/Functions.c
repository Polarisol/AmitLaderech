#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Functions.h"

#include "Func_Header.h"
#include "HebrewConversions.h"


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


int CVICALLBACK GetFieldFromRecord (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	int SIZE=20000;
	char file_name[SIZE];
	int record_num;
	char field_name[SIZE];
	char value[SIZE];
	int status;
	int choice;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal (panelHandle, PANEL_RECORD_NUM, &record_num);
			GetCtrlVal (panelHandle, PANEL_S_FILE_NAME, file_name);
			
			GetCtrlIndex (panelHandle, PANEL_RING, &choice);
			GetLabelFromIndex (panelHandle, PANEL_RING, choice, field_name);
			
			HebrewConverter_convertHebrewISOtoUTF8(field_name);
			
			
			status = CSVParser_GetFieldFromRecord(file_name, record_num, field_name, value); 
			if(status==1)
			{
				ResetTextBox (panelHandle, PANEL_TEXTBOX, "");
				HebrewConverter_convertHebrewUTF8toISO(value);
				SetCtrlVal (panelHandle, PANEL_TEXTBOX, value);
			}
			else
			{
				ResetTextBox (panelHandle, PANEL_TEXTBOX, ""); 
				SetCtrlVal (panelHandle, PANEL_TEXTBOX, "שגיאה");	
			}
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
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_S_VAL, value);
			GetCtrlVal (panelHandle, PANEL_S_FILE_NAME_2, file_name);
			GetCtrlVal (panelHandle, PANEL_S_FIELD_NAME_2, field_name);
			HebrewConverter_convertHebrewISOtoUTF8(field_name);
			HebrewConverter_convertHebrewISOtoUTF8(value);
			
			num_of_records = CSVParser_CountAllRecordsWithFieldValue(file_name, field_name, value);
			
			SetCtrlVal (panelHandle, PANEL_RECORD_NUM_2, num_of_records);
			break;
	}
	return 0;
}

int CVICALLBACK Load_headers (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	int MAX_SIZE = 10000;
	char line[MAX_SIZE];
	char file_name[300];
	char** list = NULL;
	int num_of_values;
	FILE *Stream;
	
	
	switch (event)
	{
		case EVENT_COMMIT:
			ClearListCtrl (panelHandle, PANEL_RING);
			GetCtrlVal (panelHandle, PANEL_S_FILE_NAME, file_name);
			Stream = fopen(file_name,"r");
			if(Stream)
			{
				fgetcsvl(line,MAX_SIZE,Stream);
				list = CSV_Analyzer(line, &num_of_values);
			
				
				
				for(int i=0 ; i<num_of_values; i++)
				{
					
				HebrewConverter_convertHebrewUTF8toISO(list[i]);	
				InsertListItem (panelHandle, PANEL_RING, i, list[i], i);
				
				}
			}
			fclose(Stream);	
				
			break;
	}
	return 0;
}
