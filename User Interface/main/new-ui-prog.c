	// DONT FORGET TO ADD database.c

	#include "toolbox.h"
	#include <utility.h>
	#include <ansi_c.h>
	#include <cvirte.h>		
	#include <userint.h>
	#include "new-ui-prog.h"
	#include "HebrewConversions.h"
	#include "database.h"

	#define canvasHeight 115
	#define TextBoxWidth 130
	#define canvasWidth 1080
	#define canvasWidthPosition 75
	#define textSIZE 16
	#define textBOLDSIZE 24
	#define secondsPerDay 86400
	#define secondsPerMonth 2592000
	#define secondsPerYear 31557600

	static int pgraph, pgraph_2;

	struct todaydate
	{
		int DD;
		int MM;
		int YYYY;

	} todaydate;

	// **** arraying all controls *** //
	int boldarr[8]={PANEL_PROG_BOLD, PANEL_PROG_BOLD_2, PANEL_PROG_BOLD_3,PANEL_PROG_BOLD_4, PANEL_PROG_BOLD_5, PANEL_PROG_BOLD_6, PANEL_PROG_BOLD_7, PANEL_PROG_BOLD_8};
	int opentextarr[9]={PANEL_PROG_OPENEXT, PANEL_PROG_OPENEXT_2, PANEL_PROG_OPENEXT_3,PANEL_PROG_OPENEXT_4, PANEL_PROG_OPENEXT_5, PANEL_PROG_OPENEXT_6, PANEL_PROG_OPENEXT_7, PANEL_PROG_OPENEXT_8, PANEL_PROG_OPENEXT_9};
	int reminderarr[8]={PANEL_PROG_DAYS, PANEL_PROG_DAYS_2, PANEL_PROG_DAYS_3,PANEL_PROG_DAYS_4, PANEL_PROG_DAYS_5, PANEL_PROG_DAYS_6, PANEL_PROG_DAYS_7, PANEL_PROG_DAYS_8};
	int finaldayarr[8]={PANEL_PROG_DAY, PANEL_PROG_DAY_2, PANEL_PROG_DAY_3,PANEL_PROG_DAY_4, PANEL_PROG_DAY_5, PANEL_PROG_DAY_6, PANEL_PROG_DAY_7, PANEL_PROG_DAY_8};
	int finalmontharr[8]={PANEL_PROG_MONTH, PANEL_PROG_MONTH_2, PANEL_PROG_MONTH_3,PANEL_PROG_MONTH_4, PANEL_PROG_MONTH_5, PANEL_PROG_MONTH_6, PANEL_PROG_MONTH_7, PANEL_PROG_MONTH_8};  
	int finalyeararr[8]={PANEL_PROG_YEAR, PANEL_PROG_YEAR_2, PANEL_PROG_YEAR_3,PANEL_PROG_YEAR_4, PANEL_PROG_YEAR_5, PANEL_PROG_YEAR_6, PANEL_PROG_YEAR_7, PANEL_PROG_YEAR_8};
	int taskarr[8]={PANEL_PROG_TASK,PANEL_PROG_TASK_2, PANEL_PROG_TASK_3,PANEL_PROG_TASK_4, PANEL_PROG_TASK_5, PANEL_PROG_TASK_6, PANEL_PROG_TASK_7, PANEL_PROG_TASK_8};
	int missioncompletearr[8]={PANEL_PROG_MISSIONCOMPLETE, PANEL_PROG_MISSIONCOMPLETE_2, PANEL_PROG_MISSIONCOMPLETE_3,PANEL_PROG_MISSIONCOMPLETE_4, PANEL_PROG_MISSIONCOMPLETE_5, PANEL_PROG_MISSIONCOMPLETE_6, PANEL_PROG_MISSIONCOMPLETE_7, PANEL_PROG_MISSIONCOMPLETE_8};
	int TextforProgresBar[8]={PANEL_GRPH_PROGRESSTASK,PANEL_GRPH_PROGRESSTASK_2,PANEL_GRPH_PROGRESSTASK_3,PANEL_GRPH_PROGRESSTASK_4,PANEL_GRPH_PROGRESSTASK_5,PANEL_GRPH_PROGRESSTASK_6,PANEL_GRPH_PROGRESSTASK_7,PANEL_GRPH_PROGRESSTASK_8};
	int inistringarr[8]={PANEL_PROG_inistring,PANEL_PROG_inistring_2,PANEL_PROG_inistring_3,PANEL_PROG_inistring_4,PANEL_PROG_inistring_5,PANEL_PROG_inistring_6,PANEL_PROG_inistring_7};
	int ctrlarray4, ctrlarray3, ctrlarray2, ctrlarray;


	char task[8][256]={""};

	// task counter
	int counter=0;

	// getting control index
	int bold_index = 0, open_index = 0;

	//getting state
	int bold_state = 0, task_state = 0;

	// progress bar name
	int id_num;
	char progressbarpng[64];

	// placing task in Canvas
	Point canvasFirst, canvasLast;

	struct todaydate taskdate[8];
	int days_before_reminder = 0;
	int openPanelConfirm, selection, answersave;
	char firstday[16];
	char savepanelstatefile[32], loadpanelstatefile[260];

	//ini
	char taskforINI[8][256];
	char dateforINI[16];
	char labeltext[32];
	char id[16]={"203059936"};

	void loadAmitPanel()
	{

		int boldinitialze, missioncompleteinitialze;
		char textinitialize[256];



		for (int i=0; i<8; i++)
		{
			GetCtrlVal (pgraph, taskarr[i], textinitialize);
	
			if (strcmp(textinitialize,"")!=0)
			{
					// Reading from date controls
			
					GetCtrlVal (pgraph, finaldayarr[i], &taskdate[i].DD);
					GetCtrlVal (pgraph, finalmontharr[i], &taskdate[i].MM);
					GetCtrlVal (pgraph, finalyeararr[i], &taskdate[i].YYYY);
					GetCtrlVal (pgraph, reminderarr[i], &days_before_reminder);
			
					// Adding Row in initialize()
			
					SetCtrlAttribute (pgraph, boldarr[counter], ATTR_DIMMED, 0);
					SetCtrlAttribute (pgraph, opentextarr[counter+1], ATTR_DIMMED, 0);
					SetCtrlAttribute (pgraph, reminderarr[counter], ATTR_DIMMED, 0);
					SetCtrlAttribute (pgraph, finaldayarr[counter], ATTR_DIMMED, 0);
					SetCtrlAttribute (pgraph, finalmontharr[counter], ATTR_DIMMED, 0);
					SetCtrlAttribute (pgraph, finalyeararr[counter], ATTR_DIMMED, 0);
					SetCtrlAttribute (pgraph, taskarr[counter], ATTR_DIMMED, 0);
					SetCtrlAttribute (pgraph, missioncompletearr[counter], ATTR_DIMMED, 0);
					counter ++; 
				
					// Checking Bold or mission complete
			
					GetCtrlVal (pgraph, boldarr[i], &boldinitialze);
					GetCtrlVal (pgraph, missioncompletearr[i], &missioncompleteinitialze);
					GetCtrlVal (pgraph, PANEL_PROG_FIRSTDAY, firstday);
			
			}
		}
		return;
	}

void initialize_prog(int p, int p2,char id[])
{
	pgraph = p;  pgraph_2 = p2;
	DisplayPanel(pgraph);
	openPanelConfirm = ConfirmPopup ("עמית לדרך- גרף התקדמות",
										 "?האם תרצה לטעון פאנל של עמית");
		if (openPanelConfirm == 1)
		{
			selection = FileSelectPopup ("", "*.*", "", "Select a file",
										 VAL_LOAD_BUTTON, 0, 0, 1, 0,
										 loadpanelstatefile);
	
				if (selection!=0)
				{
					RecallPanelState (pgraph, loadpanelstatefile, 0);
					loadAmitPanel();
				}
					else
				{
					MessagePopup ("!אזהרה", ".לא נבחר קובץ");
					selection = FileSelectPopup ("", "*.*", "", "Select a file", VAL_LOAD_BUTTON, 0, 0, 1, 0, loadpanelstatefile);
				}  
		}
	
		//checking if panel was uploaded

		GetCtrlVal (pgraph, PANEL_PROG_FIRSTDAY, firstday);
	
		if(strcmp(firstday,"")==0)
			{
				GetSystemDate (&todaydate.MM, &todaydate.DD, &todaydate.YYYY);
				sprintf (firstday, "%d-%d-%d", todaydate.DD,todaydate.MM,todaydate.YYYY);
				SetCtrlVal (pgraph_2, PANEL_GRPH_FIRSTDATE, firstday);
				SetCtrlVal (pgraph, PANEL_PROG_FIRSTDATE, firstday);
			}
		
		ctrlarray = GetCtrlArrayFromResourceID (pgraph, BOLDARRAY);
		ctrlarray2 = GetCtrlArrayFromResourceID (pgraph, OPENARRAY);
		ctrlarray3 = GetCtrlArrayFromResourceID (pgraph, FINISHARRAY);
		ctrlarray4 = GetCtrlArrayFromResourceID (pgraph, INITEXT);
		canvasFirst = MakePoint (0 ,canvasHeight/2);
		canvasLast = MakePoint (canvasWidth, canvasHeight/2);
		SetCtrlAttribute (pgraph_2, PANEL_GRPH_CANVAS, ATTR_PEN_WIDTH, 4);
		GetCtrlVal (psoldier,P_SOLDIER_ID_NUMBER, &id_num);
		sprintf (savepanelstatefile, "%s-panel",id);
		sprintf (progressbarpng, "%s-progressbar.png",id);

	return;
}


	void ini_initialize()
	{
		Database_setDatabaseFile("Database\\soldier.ini");
	}

	void DatetoRemind(int day, int month, int year, int daysbefore)
	{
		int new_day=0, new_month=0, new_year=0;


		if((day+daysbefore)>31)
		{
			new_day=(day+daysbefore)-31;
	
			if((month+1)>12)
			{
				new_month=1;
				new_year=year+1;
			}
			else
			{
				new_month=month+1;
				new_year=year;
			}
		}
	   	else
			{
				new_day=day+daysbefore;
				new_year=year;
				new_month=month;
			}

		sprintf (dateforINI, "%d/%d/%d", new_day,new_month,new_year);

	}

	int MaxNumber(int arr[], int counter)
	{

		 int highest;

		 highest=arr[0];

		 for(int i=0;i<counter;i++)
		 {   
			 if(highest<arr[i])
				{
					highest=arr[i];	 
				}	 
		 }

		 return highest;
	}

	int main (int argc, char *argv[])
	{
		if (InitCVIRTE (0, argv, 0) == 0)
			return -1;	/* out of memory */ 
		if ((pgraph = LoadPanel (0, "new-ui-prog.uir", PANEL_PROG)) < 0)
			return -1;
		if ((pgraph_2 = LoadPanel (0, "new-ui-prog.uir", PANEL_GRPH)) < 0)
			return -1;
		DisplayPanel (pgraph);
		initialize();
		ini_initialize();
		RunUserInterface ();
		return 0;
	} 

	int CVICALLBACK exitFUNC (int panel, int event, void *callbackData,
							  int eventData1, int eventData2)
	{
		switch (event)
		{
			case EVENT_GOT_FOCUS:

				break;
			case EVENT_LOST_FOCUS:

				break;
			case EVENT_CLOSE:

				HidePanel(pgraph);
				break;
		}
		return 0;
	}

	int CVICALLBACK exitFunc2 (int panel, int event, void *callbackData,
							   int eventData1, int eventData2)
	{
		switch (event)
		{
			case EVENT_GOT_FOCUS:

				break;
			case EVENT_LOST_FOCUS:

				break;
			case EVENT_CLOSE:
				HidePanel (pgraph_2);
				break;
		}
		return 0;
	}
	//making text bold if needed

	int CVICALLBACK boldit (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
	{
		int val;

		switch (event)
		{
			case EVENT_COMMIT:
	
				GetCtrlArrayIndex (ctrlarray, pgraph, control, &bold_index);
	
				GetCtrlVal (pgraph, boldarr[bold_index], &val);
	
				SetCtrlAttribute (pgraph, taskarr[bold_index], ATTR_TEXT_BOLD, val);
	
				break;
		}
		return 0;
	}
	//open next line for another task if needed

	int CVICALLBACK opennext (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
	{
		int val;
		switch (event)
		{
			case EVENT_COMMIT:
	
				if (counter<8)
				{
					GetCtrlVal (pgraph, opentextarr[counter], &val);
	
					GetCtrlArrayIndex (ctrlarray2, pgraph, control, &open_index);
		
						if (val==1)		//adding line
						{
							SetCtrlAttribute (pgraph, boldarr[open_index], ATTR_DIMMED, !val);
							SetCtrlAttribute (pgraph, opentextarr[open_index+1], ATTR_DIMMED, !val);
							SetCtrlAttribute (pgraph, reminderarr[open_index], ATTR_DIMMED, !val);
							SetCtrlAttribute (pgraph, finaldayarr[open_index], ATTR_DIMMED, !val);
							SetCtrlAttribute (pgraph, finalmontharr[open_index], ATTR_DIMMED, !val);
							SetCtrlAttribute (pgraph, finalyeararr[open_index], ATTR_DIMMED, !val);
							SetCtrlAttribute (pgraph, taskarr[open_index], ATTR_DIMMED, !val);
							SetCtrlAttribute (pgraph, missioncompletearr[open_index], ATTR_DIMMED, !val);
							counter ++;
						}
						else			//closing line
						{
							counter --;
							SetCtrlAttribute (pgraph, boldarr[open_index], ATTR_DIMMED, 1);
							SetCtrlAttribute (pgraph, opentextarr[open_index+1], ATTR_DIMMED, 1);
							SetCtrlAttribute (pgraph, reminderarr[open_index], ATTR_DIMMED, 1);
							SetCtrlAttribute (pgraph, finaldayarr[open_index], ATTR_DIMMED, 1);
							SetCtrlAttribute (pgraph, finalmontharr[open_index], ATTR_DIMMED, 1);
							SetCtrlAttribute (pgraph, finalyeararr[open_index], ATTR_DIMMED, 1);
							SetCtrlAttribute (pgraph, taskarr[open_index], ATTR_DIMMED, 1);
							SetCtrlAttribute (pgraph, missioncompletearr[open_index], ATTR_DIMMED, 1);
						}
	
				}
	
				break;
		}
		return 0;
	}

	int CVICALLBACK ok (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
	{
		int daysBetweenDates[8]={0};
		int todayseconds=0, maxDaysBetween=0;
		int taskdateseconds[8]={0};
		//double pixelsPerday=0;
		char progressbarpath[64], panelstatepath[32];
	

		char initask[8][128]={""};
		int dayforini=0, monthforini=0, yearforini=0, daysbeforeini=0;



		switch (event)
		{
			case EVENT_COMMIT:
	
		//		CanvasClear (pgraph_2, PANEL_GRPH_CANVAS, VAL_ENTIRE_OBJECT);
	
					todayseconds = (todaydate.DD * secondsPerDay) + (todaydate.MM * secondsPerMonth) + ((todaydate.YYYY-2017) * secondsPerYear);
			
						//Getting the dates and ** DAYS ** between the day the mentor insert for the time data
			
						for (int i=0; i<counter; i++)
						{
							GetCtrlVal (panel, finaldayarr[i], &taskdate[i].DD);
							GetCtrlVal (panel, finalmontharr[i], &taskdate[i].MM);
							GetCtrlVal (panel, finalyeararr[i], &taskdate[i].YYYY);
							taskdateseconds[i] = (taskdate[i].DD * secondsPerDay) + (taskdate[i].MM * secondsPerMonth) + ((taskdate[i].YYYY-2017) * secondsPerYear); 
							daysBetweenDates[i] = (taskdateseconds[i]-todayseconds)/secondsPerDay;
							maxDaysBetween = MaxNumber(daysBetweenDates, counter); 
						
							if (daysBetweenDates[i]<0 || maxDaysBetween==0)
								{
									MessagePopup ("Error!", "One or more of the dates you insert is invalid");
									DisplayPanel (pgraph);
								}
							
						//	pixelsPerday = canvasWidth/maxDaysBetween;
							GetCtrlVal (panel, taskarr[i], task[i]);
				
						}
			
		
					// Insert tasks
			
				
					SetCtrlVal (pgraph_2, PANEL_GRPH_FIRSTDATE, firstday);
					SetCtrlVal (pgraph, PANEL_PROG_FIRSTDAY, firstday);

					for (int i=0;i<counter;i++)
						{
							// Placing Text Box in The Right Position and making visible
							
							SetCtrlAttribute (pgraph_2, TextforProgresBar[i], ATTR_LEFT, (canvasWidth/counter)*(i+1)-(TextBoxWidth/2));
							SetCtrlAttribute (pgraph_2, TextforProgresBar[i], ATTR_VISIBLE, 1);
						
							// Adding Task
							GetCtrlVal (panel, taskarr[i], task[i]);
							SetCtrlVal (pgraph_2, TextforProgresBar[i], task[i]);
						
							// Checking For task Data (Done\Bold)
						
							// Now checking Bold
							
							GetCtrlVal (panel, boldarr[i], &bold_state);
							if(bold_state==1)
							{
								SetCtrlAttribute (pgraph_2, TextforProgresBar[i], ATTR_TEXT_BOLD, bold_state);
							}
						
							//	Now checking task complition
							
							GetCtrlVal (panel, missioncompletearr[i], &task_state);
							if(task_state==1)
							{
								SetCtrlAttribute (pgraph_2, TextforProgresBar[i], ATTR_TEXT_COLOR,
												  VAL_GREEN);
								SetCtrlAttribute (pgraph_2, TextforProgresBar[i], ATTR_TEXT_ITALIC,
												  task_state);
							
							}
						
						
							
						
						
						}
		
			
							/*  My try of "SMART" progress bar with gap that matches dates gap
								MIGHT NOT WORK DUE TO TOO MANY CHANGES!!!*/

				/*	for (int i=0; i<=counter; i++)
					{
						TextBoxSize = strlen(task[i])*textSIZE+5;
						GetCtrlVal (panel, boldarr[i], &bold_state);
						GetCtrlVal (panel, missioncompletearr[i], &task_state);
				
						// Task Done
						if(task_state==1)
						{
							SetCtrlAttribute (pgraph_2, PANEL_GRPH_CANVAS,
										  ATTR_PEN_FILL_COLOR, VAL_DK_GREEN);
							SetCtrlAttribute (pgraph_2, PANEL_GRPH_CANVAS, ATTR_PEN_COLOR,
										  VAL_BLACK);
							CanvasDrawText (pgraph_2, PANEL_GRPH_CANVAS, &task[i],
										VAL_APP_META_FONT,
										MakeRect (canvasHeight/2, (canvasWidth/TextBoxSize)*(0.5+i), canvasHeight/2,
												  TextBoxSize),
										VAL_CENTER);
						}
						else
							if(bold_state==1)
								{	//Task Text Bold
									SetCtrlAttribute (pgraph_2, PANEL_GRPH_CANVAS, ATTR_PEN_WIDTH,
													  textBOLDSIZE);
									CanvasDrawText (pgraph_2, PANEL_GRPH_CANVAS, &task[i],
													VAL_APP_META_FONT,
													MakeRect (canvasHeight/2, (canvasWidth/counter)*(i-0.5), canvasHeight/2,
															  TextBoxSize*textSIZE),
													VAL_CENTER); 
								}
				
				
									else
									{   //Task Print
										SetCtrlAttribute (pgraph_2, PANEL_GRPH_CANVAS,
														  ATTR_PEN_FILL_COLOR, VAL_DK_RED);
										SetCtrlAttribute (pgraph_2, PANEL_GRPH_CANVAS, ATTR_PEN_COLOR,
														  VAL_WHITE);
										CanvasDrawText (pgraph_2, PANEL_GRPH_CANVAS, &task[i],
														VAL_APP_META_FONT,
														MakeRect (canvasHeight/2, (canvasWidth/TextBoxSize)*(0.5+i), canvasHeight/2,
															  TextBoxSize),
														VAL_CENTER);
									}
					}
								  
					CanvasEndBatchDraw(pgraph_2, PANEL_GRPH_CANVAS); */ 
		
					// saving into .ini file
		
					for (int i=0;i<=counter;i++)
					{
		   
						GetCtrlVal (pgraph, taskarr[i], initask[i]);
						GetCtrlVal (pgraph, finaldayarr[i], &dayforini);
						GetCtrlVal (pgraph, finalmontharr[i], &monthforini);
						GetCtrlVal (pgraph, finalyeararr[i], &yearforini);
						GetCtrlVal (pgraph, reminderarr[i], &daysbeforeini);
				
						DatetoRemind(dayforini, monthforini ,yearforini ,daysbeforeini);
						sprintf (taskforINI[i], "%s,%s",initask[i],dateforINI);
				
						SetCtrlVal (pgraph, inistringarr[i], taskforINI[i]);
				
					}  
			
			
	 				//=====================INI SAVING=====================//
					
					Database_SetDatabaseFile("Database\\soldier.ini");
			
					for (int i=0;i<counter;i++)
				
					{
						GetCtrlAttribute (pgraph, inistringarr[i], ATTR_LABEL_TEXT,
										  labeltext);
						Database_SetFieldVal(id, labeltext, taskforINI[i]); 
					}
		
			
					sprintf (panelstatepath, "panel-progress\\%s", savepanelstatefile);
			
					SavePanelState (panel, panelstatepath, 0);
			
					sprintf (progressbarpath, "progressbar\\%s", progressbarpng);
			
					SavePanelDisplayToFile (pgraph_2, 1, VAL_ENTIRE_OBJECT, 120,
											1050, progressbarpath);
		
		
				break;
		}
		return 0;
	}


	int CVICALLBACK showprogressbar (int panel, int control, int event,
									 void *callbackData, int eventData1, int eventData2)
	{
		switch (event)
		{
			case EVENT_COMMIT:
	
				DisplayPanel (pgraph_2);
	
				break;
		}
		return 0;
	}
