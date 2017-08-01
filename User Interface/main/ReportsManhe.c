#include <cvirte.h>		
#include <userint.h>
#include "ReportsManhe.h"

static int panelHandle;



int CVICALLBACK myExitFunc (int panel, int event, void *callbackData,
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
