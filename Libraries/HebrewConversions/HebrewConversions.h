// Utility function used by 'HebrewConverter' functions to add an array value
void HebrewConverter_expand(char arr[], int new_index, int size);


// Utility function used by 'HebrewConverter' functions to delete an array value
void HebrewConverter_collapse(char arr[], int del_index, int size);


// Utility function used by 'HebrewConverter' functions to find a hebrew letter index in an array
int HebrewConverter_find_letter_index(char wrong[], char val);


// HEBREW Convertor: Converts a string from <UTF-8 without BOM> to <ISO 8859-8> / <Windows-1255>
// Should only be applied to English-Hebrew strings (the effect on other languages is no known)
// If the string is already in ISO or Window format the Hebrew letters remain OK
// Must be accompanied by two utility functions 
void HebrewConverter_convertHebrewUTF8toISO(char original[]);


// Warning!!! the provided string will double in size, make sure the array is large enough to hold it  
// HEBREW Convertor: Converts a string from <ISO 8859-8> / <Windows-1255> to <UTF-8 without BOM>
// Should only be applied to English-Hebrew strings (the effect on other languages is no known)
// If the string is already in UTF format the Hebrew letters remain OK
// Must be accompanied by two utility functions 
void HebrewConverter_convertHebrewISOtoUTF8(char original[]);

