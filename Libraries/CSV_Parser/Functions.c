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
	int LINE_SIZE = 300;
	char line[LINE_SIZE];
	char filename[LINE_SIZE];
	char buffer[LINE_SIZE];
	FILE *Stream;
	char *token;
	char s[2] = ",";
	char l[3] = """"""""";

	
	switch (event)
	{
		case EVENT_COMMIT:
				GetCtrlVal (panelHandle, PANEL_STRING_2, filename);
				Stream = fopen(filename,"r");
				if(Stream)
				{
					fgets(line,LINE_SIZE,Stream);
					while(fgets(line,LINE_SIZE,Stream)!=0)
					{
						if(line[0] == '"')
						{
							token = strtok(line,l);
							strcpy(buffer, token);
						}
						else
						{
							token = strtok(line,s);
							strcpy(buffer, token);	
						}
						while(token != NULL)
						{
							if(&token[0] == '"')
							{
								token = strtok(NULL,l);
								strcpy(buffer, token);
							}
							else
							{
								token = strtok(NULL,s);
								strcpy(buffer, token);	
							}							
						}
							

			
					}
				}
			break;
	}
	return 0;
}
