#include <utility.h>
#include <cvirte.h>		
#include <userint.h>
#include "Reports.h"

static int panelHandle;

int data_image;
int ID;
int AGE;
int PHONE;  
int CELLPHONE;
char FIRST_NAME[300];     
char LAST_NAME[300];     
char CITY[300];     
char ADRESS[300];     
char OCCUPATION[300]; 
char MAIL[300];      



int CVICALLBACK myexitFunc (int panel, int event, void *callbackData,
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

int CVICALLBACK okFunc (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			/*	 GetCtrlVal (panelHandle, ID_NUMBER, &ID);
				 GetCtrlVal (panelHandle, P_SOLDIER_AGE, &AGE);
				 GetCtrlVal (panelHandle, P_SOLDIER_FIRST_NAME, FIRST_NAME);
				 GetCtrlVal (panelHandle, P_SOLDIER_LAST_NAME, LAST_NAME);
				 GetCtrlVal (panelHandle, P_SOLDIER_PHONE_NUMBER, &PHONE); 
				 GetCtrlVal (panelHandle, P_SOLDIER_ADDRESS, ADRESS);
				 
				 SetCtrlVal (panelHandle, PANEL_AMIT_ID, ID);
			     SetCtrlVal (panelHandle, PANEL_AGE, AGE);
				 SetCtrlVal (panelHandle, PANEL_AMIT_FIRST_NAME, FIRST_NAME);
				 SetCtrlVal (panelHandle, PANEL_AMIT_LAST_NAME, LAST_NAME);
				 SetCtrlVal (panelHandle, PANEL_AMIT_CELLPHONE, CELLPHONE); 
				 SetCtrlVal (panelHandle, PANEL_AMIT_ADDRESS, ADRESS);
	
				 
				 GetPanelDisplayBitmap (panelHandle, VAL_FULL_PANEL, VAL_ENTIRE_OBJECT, &data_image);
				 SaveBitmapToJPEGFile (data_image, "amitfile.jpg", 0, 80);
				 LaunchExecutable ("convert amitfile.jpg amitfile.pdf");   */

			break;
	}
	return 0;
}
