#include "wordrpt.h"    
#include "word2000.h"  
#include "wordreport.h"
#include <ansi_c.h>
#include <utility.h>
#include <cvirte.h>		
#include <userint.h>
#include "wordfunc.h"

static int panelHandle;
static void	InitializeTests (void);
static int	Run (int TestNum);
static void	FillTable (void);
static void	PlotGraph (void);
static void	Generate_WordReport (void);
static void ReportActiveXError (void);

//----------------------------------------------------------------------------
// Global variables
//----------------------------------------------------------------------------


static CAObjHandle	appHandle;
static CAObjHandle	docHandle;
static CAObjHandle TableHandle;

static int	panelHandle;

char AMIT_NAME[300]="Full Name - Amit";
char AMIT_ID[300];
char AMIT_DATE[300];		   
char AMIT_AGE[300];
char AMIT_GENDER[300];
char AMIT_ADDRESS[300];
char AMIT_CITY[300];
char AMIT_LIVING_STATUS[300];
char AMIT_MOBILE[300];
char AMIT_PHONE[300];
char AMIT_MAIL[300];
char AMIT_EDUCATION[300];
char AMIT_JOB[300];
char AMIT_PERIOD[300];
char AMIT_ECONOMY[300];
char AMIT_LEGAL_STATUS[300];
char AMIT_MENTOR[300]; 

char MENTOR_NAME[300]="Full Name - Mentor";
char MENTOR_ID[300];
char MENTOR_AGE[300];
char MENTOR_ADDRESS[300];
char MENTOR_CITY[300];
char MENTOR_MOBILE[300];
char MENTOR_PHONE[300];
char MENTOR_MAIL[300];
char MENTOR_MANHE[300];
char MENTOR_AMIT1[300];
char MENTOR_AMIT2[300];         
char MENTOR_AMIT3[300];         

char MANHE_NAME[300]="Full Name - MANHE";
char MANHE_ID[300];
char MANHE_AGE[300];
char MANHE_ADDRESS[300];
char MANHE_CITY[300];
char MANHE_MOBILE[300];
char MANHE_PHONE[300];
char MANHE_MAIL[300];
char MANHE_KVUTZA1[300];
char MANHE_KVUTZA2[300];         
char MANHE_KVUTZA3[300];         

int counter=0;

int count=0;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "wordfunc.uir", PANEL)) < 0)
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

int CVICALLBACK wordDoc (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	char		pathName[MAX_PATHNAME_LEN]; 
		
	CAObjHandle	tableHandle = 0;
	int			i;	
	
	char		imageFileName[MAX_PATHNAME_LEN]; 
	
		int			label_color, panel_color;
	CAObjHandle	imageHandle = 0;
	
	int val;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal (panelHandle, PANEL_DOCUMENT, &val);
			
			switch(val)
			{
				case 1:
					
					WordRpt_ApplicationNew (VTRUE, &appHandle);  // new application
					GetProjectDir (pathName);
					strcat (pathName, "\\amit.doc");
			
					WordRpt_DocumentOpen (appHandle, pathName, &docHandle); //open word file
	
					WordRpt_AddPageNumbers (docHandle, WRConst_Footer, WRConst_AlignPageNumberCenter, WRConst_TRUE);
					WordRpt_SetHeader (docHandle, "", "", "", WRConst_FieldDate, WRConst_FieldEmpty, WRConst_FieldTime); // date config time


					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 14.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					WordRpt_NewLine (docHandle);  //new line
					
					WordRpt_AppendText (docHandle, AMIT_NAME);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);  
					WordRpt_NewLine (docHandle); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignLeft);
					WordRpt_NewLine (docHandle);
					
					WordRpt_AppendText (docHandle, "ID:"); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_ID); 
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);        
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Date Of Birth:");
					WordRpt_InsertTab (docHandle);    
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_AppendText (docHandle, AMIT_DATE);    
					WordRpt_InsertTab (docHandle);
					WordRpt_InsertTab (docHandle);      
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Age:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_AGE);    
					WordRpt_InsertTab (docHandle);
					WordRpt_InsertTab (docHandle);      
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Gender:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_GENDER);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);   
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Address:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_ADDRESS);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);        
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);   
					
					WordRpt_AppendText (docHandle, "City:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_CITY);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);   
					
					WordRpt_AppendText (docHandle, "Living Status:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_LIVING_STATUS);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Economy:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_ECONOMY);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Legal Status:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_LEGAL_STATUS);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Job:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_JOB);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Education:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_EDUCATION);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Period:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_PERIOD);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Mentor:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_MENTOR);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);   
					WordRpt_AppendText (docHandle, "Contact info:");
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					
					WordRpt_AppendText (docHandle, "Mobile:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_MOBILE);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Phone:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_PHONE);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Mail:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, AMIT_MAIL);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
	
					break;
					
				case 2:
					
					WordRpt_ApplicationNew (VTRUE, &appHandle);  // new application
					GetProjectDir (pathName);
					strcat (pathName, "\\mentor.doc");
			
					WordRpt_DocumentOpen (appHandle, pathName, &docHandle); //open word file
	
					WordRpt_AddPageNumbers (docHandle, WRConst_Footer, WRConst_AlignPageNumberCenter, WRConst_TRUE);
					WordRpt_SetHeader (docHandle, "", "", "", WRConst_FieldDate, WRConst_FieldEmpty, WRConst_FieldTime); // date config time


					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 14.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					WordRpt_NewLine (docHandle);  //new line
					
					WordRpt_AppendText (docHandle, MENTOR_NAME);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);  
					WordRpt_NewLine (docHandle); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignLeft);
					WordRpt_NewLine (docHandle);
					
					WordRpt_AppendText (docHandle, "ID:"); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_ID); 
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Age:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_AGE);    
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Address:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_ADDRESS);    
					WordRpt_NewLine (docHandle);        
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);   
					
					WordRpt_AppendText (docHandle, "City:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_CITY);    
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE); 
					
					WordRpt_AppendText (docHandle, "Manhe incharge:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_MANHE);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);   
					WordRpt_AppendText (docHandle, "Contact info:");
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					
					WordRpt_AppendText (docHandle, "Mobile:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_MOBILE);    
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Phone:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_PHONE);    
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Mail:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_MAIL);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);   
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);  
					WordRpt_AppendText (docHandle, "Amitim under his response:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);  
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_AMIT1);    
					WordRpt_NewLine (docHandle);
					WordRpt_AppendText (docHandle, MENTOR_AMIT2);
					WordRpt_NewLine (docHandle);            
					WordRpt_AppendText (docHandle, MENTOR_AMIT3);              
					
					break;
					
				case 3:
					WordRpt_ApplicationNew (VTRUE, &appHandle);  // new application
					GetProjectDir (pathName);
					strcat (pathName, "\\manhe.doc");
			
					WordRpt_DocumentOpen (appHandle, pathName, &docHandle); //open word file
	
					WordRpt_AddPageNumbers (docHandle, WRConst_Footer, WRConst_AlignPageNumberCenter, WRConst_TRUE);
					WordRpt_SetHeader (docHandle, "", "", "", WRConst_FieldDate, WRConst_FieldEmpty, WRConst_FieldTime); // date config time


					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 14.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					WordRpt_NewLine (docHandle);  //new line
					
					WordRpt_AppendText (docHandle, MANHE_NAME);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);  
					WordRpt_NewLine (docHandle); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignLeft);
					WordRpt_NewLine (docHandle);
					
					WordRpt_AppendText (docHandle, "ID:"); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_ID); 
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Age:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_AGE);    
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Address:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_ADDRESS);    
					WordRpt_NewLine (docHandle);        
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);   
					
					WordRpt_AppendText (docHandle, "City:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_CITY);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);    
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE); 
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);   
					WordRpt_AppendText (docHandle, "Contact info:");
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					
					WordRpt_AppendText (docHandle, "Mobile:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_MOBILE);    
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Phone:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_PHONE);    
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_AppendText (docHandle, "Mail:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_MAIL);    
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);   
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);  
					WordRpt_AppendText (docHandle, "Groups under his response:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);  
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, MANHE_KVUTZA1);    
					WordRpt_NewLine (docHandle);
					WordRpt_AppendText (docHandle, MANHE_KVUTZA2);
					WordRpt_NewLine (docHandle);            
					WordRpt_AppendText (docHandle, MANHE_KVUTZA3);              
					
					break;
			}
					
	}
	return 0;
}

