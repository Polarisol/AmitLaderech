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


char name[300];
char address[300]; 
char age[300]; 
char price[300];

char string[]="Hello";

char data[40][40];
char grades[40][40];


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
	
	FILE* fp;
	
	char fname[300];
	char fline[300];
	
	int typ;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal (panelHandle, PANEL_DOCUMENT, &val);
			
			switch(val)
			{
				case 1:
					
					fp=fopen ("amit.csv", "r");
					if (fp)
					{
						while(fgets (fline, 300, fp)!=NULL)
						{
							sscanf (fline, "%[^,],%[^,],%[^,]" , name, address, age);
						}
					}
					fclose (fp); 
				 
						
					WordRpt_ApplicationNew (VTRUE, &appHandle);  // new application
					GetProjectDir (pathName);
					strcat (pathName, "\\amit.doc");
			
					WordRpt_DocumentOpen (appHandle, pathName, &docHandle); //open word file
	
					WordRpt_AddPageNumbers (docHandle, WRConst_Footer, WRConst_AlignPageNumberCenter, WRConst_TRUE);
					WordRpt_SetHeader (docHandle, "", "", "", WRConst_FieldDate, WRConst_FieldEmpty, WRConst_FieldTime); // date config time


					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 26.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					//WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_ALLCAPS, WRConst_TRUE);

	
					GetProjectDir (imageFileName);
					strcat (imageFileName, "\\assaf.png");
	
					WordRpt_NewLine (docHandle);  //new line
					WordRpt_AppendText (docHandle, "Amit Details");
					WordRpt_NewLine (docHandle); 
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 16.0);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignLeft);
					WordRpt_AppendText (docHandle, "Name:"); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_InsertTab (docHandle);
					WordRpt_AppendText (docHandle, name); 
	
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 16.0);   
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_AppendText (docHandle, "Address:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_InsertTab (docHandle);   
					WordRpt_AppendText (docHandle, address); 
	
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 16.0);   
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_AppendText (docHandle, "Age:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_InsertTab (docHandle);
					WordRpt_InsertTab (docHandle);      
					WordRpt_AppendText (docHandle, age);    
	
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);   
					WordRpt_InsertImage (docHandle, imageFileName, &imageHandle); 
				
					break;
					
				case 2:
					
					fp=fopen ("thanks.csv", "r");
					if (fp)
					{
						while(fgets (fline, 300, fp)!=NULL)
						{
							sscanf (fline, "%[^,],%[^,]" , name, price);
						}
					}
					fclose (fp);  
						
					WordRpt_ApplicationNew (VTRUE, &appHandle);  // new application
					GetProjectDir (pathName);
					strcat (pathName, "\\thanks.doc");
			
					WordRpt_DocumentOpen (appHandle, pathName, &docHandle); //open word file
	
					WordRpt_AddPageNumbers (docHandle, WRConst_Footer, WRConst_AlignPageNumberCenter, WRConst_TRUE);
					WordRpt_SetHeader (docHandle, "", "", "", WRConst_FieldDate, WRConst_FieldEmpty, WRConst_FieldTime); // date config time


					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 26.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					//WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_ALLCAPS, WRConst_TRUE);

	
					GetProjectDir (imageFileName);
					strcat (imageFileName, "\\thankyoujpg.png");
	
					WordRpt_NewLine (docHandle);  //new line
					WordRpt_AppendText (docHandle, "Thank You For Donate Us");
					
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);  
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 16.0);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignLeft);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone); 
					WordRpt_AppendText (docHandle, "Dear Mr. "); 
					WordRpt_AppendText (docHandle, name);
					WordRpt_AppendText (docHandle, " ,\n Thank you so much for donate us "); 
					WordRpt_AppendText (docHandle, price);
					WordRpt_AppendText (docHandle, "dollars!");
			
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);   
					WordRpt_InsertImage (docHandle, imageFileName, &imageHandle); 
					
					break;
					
				case 3:
					
					fp=fopen ("mentor.csv", "r");
					if (fp)
					{
						while(fgets (fline, 300, fp)!=NULL)
						{
							sscanf (fline, "%[^,],%[^,],%[^,]" , name, address, age);
						}
					}
					fclose (fp);  
					
					WordRpt_ApplicationNew (VTRUE, &appHandle);  // new application
					GetProjectDir (pathName);
					strcat (pathName, "\\mentor.doc");
			
					WordRpt_DocumentOpen (appHandle, pathName, &docHandle); //open word file
	
					WordRpt_AddPageNumbers (docHandle, WRConst_Footer, WRConst_AlignPageNumberCenter, WRConst_TRUE);
					WordRpt_SetHeader (docHandle, "", "", "", WRConst_FieldDate, WRConst_FieldEmpty, WRConst_FieldTime); // date config time


					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 26.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
				//	WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_ALLCAPS, WRConst_TRUE);

	
					GetProjectDir (imageFileName);
					strcat (imageFileName, "\\mentor.png");
	
					WordRpt_NewLine (docHandle);  //new line
					WordRpt_AppendText (docHandle, "Mentor Details");
					
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);    
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 16.0);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignLeft);
					WordRpt_AppendText (docHandle, "Name:"); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_InsertTab (docHandle);
					WordRpt_InsertTab (docHandle);      
					WordRpt_AppendText (docHandle, name); 
	
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 16.0);   
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_AppendText (docHandle, "Address:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					
					WordRpt_InsertTab (docHandle);
					WordRpt_InsertTab (docHandle);   
					WordRpt_InsertTab (docHandle);   
					
					WordRpt_AppendText (docHandle, address); 
	
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 16.0);   
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_AppendText (docHandle, "Numbers Of Colleagues:");
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0);
					WordRpt_InsertTab (docHandle);
					WordRpt_InsertTab (docHandle);      
					WordRpt_AppendText (docHandle, age);    
	
			     	WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
	
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);   
					WordRpt_InsertImage (docHandle, imageFileName, &imageHandle); 
					
					break;
					
				case 4:
					
					fp=fopen ("NamesGrades.csv", "r");
					if (fp)
					{
						while(fgets (fline, 300, fp)!=NULL)
						{
							sscanf(fline, "%[^,],%[^,]", data[count],grades[count]);
							count++;
						}
					}
					fclose (fp);
					
					WordRpt_ApplicationNew (VTRUE, &appHandle);  // new application
					GetProjectDir (pathName);
					strcat (pathName, "\\students.doc");
			
					WordRpt_DocumentOpen (appHandle, pathName, &docHandle); //open word file
					
					WordRpt_AddPageNumbers (docHandle, WRConst_Footer, WRConst_AlignPageNumberCenter, WRConst_TRUE);
					WordRpt_SetHeader (docHandle, "", "", "", WRConst_FieldDate, WRConst_FieldEmpty, WRConst_FieldTime); // date config time
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 26.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_TRUE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineSingle);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_TEXT_ALIGN, WRConst_AlignCenter);
					WordRpt_AppendText (docHandle, "Student's Grades");
					
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_SIZE, 12.0); 
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_BOLD, WRConst_FALSE);
					WordRpt_SetTextAttribute (docHandle, WR_ATTR_FONT_UNDERLINE, WRConst_UnderlineNone);
					
					WordRpt_NewLine (docHandle);
					WordRpt_NewLine (docHandle);
					
					TableHandle = 0;
					
					WordRpt_AddTable (docHandle, count, 2, &TableHandle);
					
					for(int i=0;i<count;i++)
						{
							WordRpt_WriteToCell (TableHandle, i+1, 1, data[i]);
							WordRpt_WriteToCell (TableHandle, i+1, 2, grades[i]);   
						}
			}
			
			break;
	}
	return 0;
}

