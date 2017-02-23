#include <cvirte.h>
#include <userint.h>
#include <stdio.h>
#include "test.h"
#include "HebrewConversions.h"
#include "Func_Header.h"
static int mainPanel;
int column_num,rows_num;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((mainPanel = LoadPanel (0, "test.uir", MAIN_PANEL)) < 0)
		return -1;
	DisplayPanel (mainPanel);
	RunUserInterface ();
	DiscardPanel (mainPanel);
	return 0;
}

int CVICALLBACK main_func (int panel, int event, void *callbackData,
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

int CVICALLBACK load_csv (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	int MAX_SIZE = 10000;
	char line[MAX_SIZE];
	char file_name[300],header[300];
	char** list = NULL;
	int num_of_values,status;
	FILE *Stream;


	switch (event)
	{
		case EVENT_COMMIT:
			ClearListCtrl (mainPanel, MAIN_PANEL_RING);
			GetCtrlVal (mainPanel,  MAIN_PANEL_CSV_PATH, file_name);
			Stream = fopen(file_name,"r");
			if(Stream)
			{
				fgetcsvl(line,MAX_SIZE,Stream);
				list = CSV_Analyzer(line, &num_of_values);
				column_num=num_of_values;
				for(int i=0 ; i<num_of_values; i++)
				{
					HebrewConverter_convertHebrewUTF8toISO(list[i]);
					InsertListItem (mainPanel, MAIN_PANEL_RING, i, list[i], i);
					GetNumTableRows (mainPanel, MAIN_PANEL_CSV_TABLE, &rows_num);
					if (!rows_num)
						InsertTableRows (mainPanel, MAIN_PANEL_CSV_TABLE, -1, 1, VAL_CELL_STRING);
					InsertTableColumns (mainPanel, MAIN_PANEL_CSV_TABLE, -1, 1, VAL_CELL_STRING);
					SetTableCellVal (mainPanel, MAIN_PANEL_CSV_TABLE, MakePoint(i+1,1),list[i] );
				}
			}
			fclose(Stream);
			rows_num=CSVParser_GetNumberOfRecords(file_name);
			for (int i=1; i<rows_num+1; i++)
			{
				InsertTableRows (mainPanel, MAIN_PANEL_CSV_TABLE, -1, 1, VAL_CELL_STRING);
				for (int j=1; j<column_num+1; j++)
				{
					GetLabelFromIndex (mainPanel, MAIN_PANEL_RING, j-1, header);
					HebrewConverter_convertHebrewISOtoUTF8(header);
					status = CSVParser_GetFieldFromRecord(file_name, i, header, line);
					if(status==1)
					{
						HebrewConverter_convertHebrewUTF8toISO(line);
						SetTableCellVal (mainPanel, MAIN_PANEL_CSV_TABLE, MakePoint(j,i+1),line );
					}
					else
					{
						MessagePopup ("error", "error");
					}
				}
			}
			break;
	}
	return 0;
}
