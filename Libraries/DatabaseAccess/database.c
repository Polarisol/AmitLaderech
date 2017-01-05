//==============================================================================
//									database.c							
//							database function file.
//
//									Variables
//						//dbFile - database file path.
//==============================================================================

#include <ansi_c.h>
#include "inifile.h"

#include "database.h"

static IniText iniText;
static char dbFile[SIZE];
FILE *fp;

//allows specifying the databases file, it will be saved globally
//to be accessed by other functions
//other functions should check if a database file was defined and not work otherwise
//returns 1 if successful, 0 if not 
int setDatabaseFile(char name[])
{
	char path[SIZE];
	if(strcmp (name, ""))
	{
		sprintf (path, "Database\\%s.ini", name);
		fp = fopen (path, "w");
		fclose(fp);
		getDatabaseFile(path);
		return 1;
	}
	
	return 0;	
}

//changes the value of the provided 'name' to the used database file name.
//the user must make sure an appropriate array is provided
//returns 1 if successful, 0 if not
int getDatabaseFile(char name[])
{
	char file[SIZE];
	char path[SIZE];
	GetFirstFile ("Database\\*.ini", 1, 0, 0, 0, 0, 0, file);
	if(strcmp (file, ""))
	{
		if(!strcmp (file, name))
		{
			sprintf (path, "Database\\%s", name);
			strcpy (dbFile, path);
			return 1;
		}
		while (!GetNextFile (file))
		{
			if(!strcmp (file, name))
			{
				sprintf (path, "Database\\%s", name);
				strcpy (dbFile, path);
				return 1;
			}
		}
	}
	return 0;
}


