#include "bass.h"
#include "MailFunctions.h"
#include <utility.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "email.h"

#define MAX 300

HSTREAM Shot_SND; 

static int panelHandle ,panelHandle2;

char SendMail[MAX] = "SwithMail.exe /s /from \"";
char username[MAX] = "Amit Laderech";
char sentFrom[MAX] = "amitprojectcvi@gmail.com";
char Password[MAX] = "NvvxhxntakH!2#4%";
char server[MAX] = "smtp.gmail.com";
char port[MAX] = "587";

char to[MAX];  
char subject[MAX];
char text[MAX] = "Enter Your Text";
char attachmentFile[MAX];

int counter=1;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "email.uir", PANEL)) < 0)
		return -1;
	if ((panelHandle2 = LoadPanel (0, "email.uir", PANEL_2)) < 0)
		return -1;

	
	DisplayPanel (panelHandle2);
	SetCtrlAttribute (panelHandle2, PANEL_2_PASSWORD, ATTR_ENABLE_CHARACTER_MASKING, 1);
	SetCtrlAttribute (panelHandle2, PANEL_2_PASSWORD, ATTR_MASK_CHARACTER, '*');     
	SetCtrlVal (panelHandle2, PANEL_2_MAIL, sentFrom);
	SetCtrlVal(panelHandle2, PANEL_2_USER, username);
	SetCtrlVal (panelHandle2, PANEL_2_PASSWORD, Password);
	SetCtrlVal (panelHandle2, PANEL_2_PORT, port);
	SetCtrlVal (panelHandle2, PANEL_2_SERVER, server);
	SetCtrlVal (panelHandle, PANEL_TEXT, text);
	BASS_Init( -1,44100, 0,0,NULL);
	SetActiveCtrl (panelHandle, PANEL_TO);
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



int CVICALLBACK toaddressFunc (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_KEYPRESS:
			if(eventData1==VAL_ENTER_VKEY)
			  SetActiveCtrl (panelHandle, PANEL_SUBJECT);
			break;
	}
	return 0;
}

int CVICALLBACK subjectFunc (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
    	case EVENT_KEYPRESS:
			if(eventData1==VAL_ENTER_VKEY)
			   SetActiveCtrl (panelHandle, PANEL_TEXT);
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
			GetCtrlVal (panelHandle2, PANEL_2_MAIL, sentFrom);
			GetCtrlVal(panelHandle2, PANEL_2_USER, username);
			GetCtrlVal (panelHandle2, PANEL_2_PASSWORD, Password);
			HidePanel (panelHandle2);
			DisplayPanel (panelHandle);   
			break;
	}
	return 0;
}

int CVICALLBACK sendmessageFunc (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{   FILE* fileDescriptor;

	switch (event)
	{
		case EVENT_COMMIT:
		
		GetCtrlVal(panelHandle, PANEL_TO, to); 
		GetCtrlVal(panelHandle, PANEL_SUBJECT, subject);
		GetCtrlVal(panelHandle, PANEL_TEXT, text);       
			
		EmailSender_Configure(SendMail, server, username, Password, port, sentFrom);
		EmailSender_SendMail(SendMail, to, subject, text, attachmentFile); 
	
        fileDescriptor=fopen ("emaildata.txt", "w");
		fprintf(fileDescriptor, "%s",SendMail);
		fclose (fileDescriptor);
						  
		LaunchExecutable (SendMail);
		
		Shot_SND = BASS_StreamCreateFile(FALSE,"bell.mp3",0,0,0); 
    	BASS_ChannelPlay(Shot_SND,TRUE);
		
	    SetCtrlVal(panelHandle, PANEL_TO, ""); 
		SetCtrlVal(panelHandle, PANEL_SUBJECT, "");
		
		
		MessagePopup ("Mail sent", "Your mail has been sent");
		
		

			break;
	}
	return 0;
}

int CVICALLBACK justrandomexitFunc (int panel, int event, void *callbackData,
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



int CVICALLBACK userinfoFunc (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 HidePanel (panelHandle);
			 DisplayPanel (panelHandle2);
			 SetActiveCtrl (panelHandle2, PANEL_2_MAIL);
			break;
	}
	return 0;
}
