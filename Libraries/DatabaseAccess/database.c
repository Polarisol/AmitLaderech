#include <ansi_c.h>
#include "inifile.h"

#include "database.h"

static IniText iniText;
FILE *fp;

//allows specifying the databases file, it will be saved globally
//to be accessed by other functions
//other functions should check if a database file was defined and not work otherwise
//returns 1 if successful, 0 if not 
int setDatabaseFile(char name[])
{
	char path[300];
	if(strcmp (name, ""))
	{
		sprintf (path, "Database\\%s.ini", name);
		fp = fopen (path, "w");
		fclose(fp);
		return 1;
	}
	
	return 0;	
}
