
#include <ansi_c.h>
#include "MailFunctions.h"
#include <utility.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "email.h"
#include "HebrewConversions.h"

#define MAX 1000



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
char attachmentFile[600];

char TestText[300];

int counter=1;

void initialize_mail(int p,int p2)
{
	panelHandle = p;
	panelHandle2 = p2;
	
	SetCtrlAttribute (panelHandle2, P_EMAILD_PASSWORD, ATTR_ENABLE_CHARACTER_MASKING, 1);
	SetCtrlAttribute (panelHandle2, P_EMAILD_PASSWORD, ATTR_MASK_CHARACTER, '*');     
	SetCtrlVal (panelHandle2, P_EMAILD_MAIL, sentFrom);
	SetCtrlVal(panelHandle2, P_EMAILD_USER, username);
	SetCtrlVal (panelHandle2, P_EMAILD_PASSWORD, Password);
	SetCtrlVal (panelHandle2, P_EMAILD_PORT, port);
	SetCtrlVal (panelHandle2, P_EMAILD_SERVER, server);
	SetCtrlVal (panelHandle, P_EMAIL_TEXT, text);
	
	SetActiveCtrl (panelHandle, P_EMAIL_TO);
	
}

int CVICALLBACK exitFuncEmail (int panel, int event, void *callbackData,
						  int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			HidePanel(panelHandle);
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
			  SetActiveCtrl (panelHandle, P_EMAIL_SUBJECT);
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
			   SetActiveCtrl (panelHandle, P_EMAIL_TEXT);
			break;
	}
	return 0;
}

int CVICALLBACK okFunc (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	// Get the account info from secondary panel
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal (panelHandle2, P_EMAILD_MAIL, sentFrom);  // Email
			GetCtrlVal(panelHandle2, P_EMAILD_USER, username);	   // User
			GetCtrlVal (panelHandle2, P_EMAILD_PASSWORD, Password);   // Password 
			HidePanel (panelHandle2);
			DisplayPanel (panelHandle);   
			break;
	}
	return 0;
}

int CVICALLBACK sendmessageFunc (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{   FILE* fileDescriptor;

     // Get the address info from primary panel

	switch (event)
	{
		case EVENT_COMMIT:
		 
		GetCtrlVal(panelHandle, P_EMAIL_TO, to); 				  // To
		GetCtrlVal(panelHandle, P_EMAIL_SUBJECT, subject);	  // Subject
		GetCtrlVal(panelHandle, P_EMAIL_TEXT, text);       	  // Text
		 
		
			
		EmailSender_Configure(SendMail, server, username, Password, port, sentFrom);
		EmailSender_SendMail(SendMail, to, subject, text, attachmentFile); 
	
      
	
		
						  
		LaunchExecutable (SendMail);	// Active the softwar "SwithMail" and send the mail through the CSV
		
	    SetCtrlVal(panelHandle, P_EMAIL_TO, ""); 
		SetCtrlVal(panelHandle, P_EMAIL_SUBJECT, "");
		
		
		MessagePopup ("Mail sent", "Your mail has been sent");  // Massage
		HidePanel (panelHandle);
		

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
			HidePanel(panelHandle2);
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
			 SetActiveCtrl (panelHandle2, P_EMAILD_MAIL);
			break;
	}
	return 0;
}

int CVICALLBACK fileselectFunc (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			FileSelectPopup ("", "*.*", "", "Load File", VAL_LOAD_BUTTON, 0, 0, 1, 0, attachmentFile);

			break;
	}
	return 0;
}

