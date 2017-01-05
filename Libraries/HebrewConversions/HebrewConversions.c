#include <ansi_c.h>   

// Utility function used by 'HebrewConverter' functions to add an array value
void HebrewConverter_expand(char arr[], int new_index, int size)
{
	for (int i=size+1 ; i>new_index ; i--) arr[i]=arr[i-1];
}


// Utility function used by 'HebrewConverter' functions to delete an array value
void HebrewConverter_collapse(char arr[], int del_index, int size)
{
	for (int i=del_index ; i<size ; i++) arr[i]=arr[i+1];
}

// Utility function used by 'HebrewConverter' functions to find a hebrew letter index in an array
int HebrewConverter_find_letter_index(char wrong[], char val)
{
	int size;
	
	size=strlen(wrong);
	
	for (int i=0 ; i<size ; i++)
		if (wrong[i]==val) return i;
	return -1;
								
}

// HEBREW Convertor: Converts a string from <UTF-8 without BOM> to <ISO 8859-8> / <Windows-1255>
// Should only be applied to English-Hebrew strings (the effect on other languages is no known)
// If the string is already in ISO or Window format the Hebrew letters remain OK
// Must be accompanied by two utility functions 
void HebrewConverter_convertHebrewUTF8toISO(char original[])
{
	
	char wrong[30]={-86,-87,-88,-89,-90,-92,-94,-95,-96,-98,-100,-101,-103,-104,-105,-106,-107,-108,-109,-110,-111,-112,-91,-93,-97,-99,-102};
	char right[30]="תשרקצפעסנמלכיטחזוהדגבאץףןםך"; 
	
	int size;
	
	size=strlen(original);
	
	for (int i=0 ; i<=size  ; i++)
	{
		if (original[i]==-41)
		{
			HebrewConverter_collapse(original, i , size);
			size--;
			i--;
		}
		else if (original[i]<=-86)
		{
			int index;
			
			index = HebrewConverter_find_letter_index(wrong,original[i]) ;
			if (index>=0) original[i]=right[index];
		}
	}
}

// Warning!!! the provided string will double in size, make sure the array is large enough to hold it
// HEBREW Convertor: Converts a string from <ISO 8859-8> / <Windows-1255> to <UTF-8 without BOM>
// Should only be applied to English-Hebrew strings (the effect on other languages is no known)
// If the string is already in UTF format the Hebrew letters remain OK
// Must be accompanied by two utility functions 
void HebrewConverter_convertHebrewISOtoUTF8(char original[])
{
	
	char right[30]={-86,-87,-88,-89,-90,-92,-94,-95,-96,-98,-100,-101,-103,-104,-105,-106,-107,-108,-109,-110,-111,-112,-91,-93,-97,-99,-102};
	char wrong[30]="תשרקצפעסנמלכיטחזוהדגבאץףןםך"; 
	            
	int size;
	
	size=strlen(original);
	
	for (int i=0 ; i<=size  ; i++)
	{
		if (original[i]>=-87 && original[i]<0)
		{
			int index;
			
			index = HebrewConverter_find_letter_index(wrong,original[i]) ;
			if (index>=0) 
			{
				HebrewConverter_expand(original, i, size);
				size++;
				original[i++]=-41; 
				original[i]=right[index];
			}
		}
	}
}
