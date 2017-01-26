#include <cvirte.h>
#include <userint.h>
#include "test.h"
#include "Func_Header.h"
#include "HebrewConversions.h"
#define SIZE 300
#define PATH "test1.csv"
#define RINGDEF USERINT_FIELD_RING1

static int userint;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((userint = LoadPanel (0, "test.uir", USERINT)) < 0)
		return -1;
	DisplayPanel (userint);
	RunUserInterface ();
	DiscardPanel (userint);
	return 0;
}

int CVICALLBACK globalfunc (int panel, int event, void *callbackData,
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

int CVICALLBACK button (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	char fromcsv[SIZE],field[SIZE],originalheb[SIZE];
	int status,chosen_row,i=0;
	switch (event)
	{
			/*case EVENT_COMMIT:
				CSVParser_GetFieldFromRecord("test2.csv",2,"name",fromcsv);
				SetCtrlVal (userint, USERINT_TEXT1, fromcsv);

				break;*/

		case EVENT_COMMIT:

			for(i=0; i<=4; i++)
			{
				//HebrewConverter_convertHebrewUTF8toISO(originalheb);
				GetCtrlVal (userint, USERINT_CHOOSE_ROW, &chosen_row);
				//GetCtrlVal (userint, USERINT_TEXTMSG,originalheb);
				//SetCtrlVal (userint, USERINT_TEXTMSG_2,originalheb);
				SetCtrlAttribute (userint, RINGDEF, ATTR_CTRL_INDEX, i);
				GetCtrlAttribute (userint, RINGDEF, ATTR_CTRL_VAL,originalheb);
				HebrewConverter_convertHebrewISOtoUTF8(originalheb); 
				status = CSVParser_GetFieldFromRecord(PATH,chosen_row, originalheb, fromcsv);
				if(status==1)
				{
					HebrewConverter_convertHebrewUTF8toISO(fromcsv);
					SetCtrlVal (userint, USERINT_TEXT1, fromcsv);
					SetTableCellVal (userint, USERINT_TABLE, MakePoint(i+1,chosen_row),fromcsv );
				}
				else if (!status)
					SetCtrlVal (userint, USERINT_TEXT1, "Error");
			}

			break;
	}
	return 0;
}
