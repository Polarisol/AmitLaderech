int CSVParser_GetNumberOfRecords(char filename[]);
int CSVParser_NewRecords(char filename[]);
void CSVParser_MarkAsProcessed(char filename[], int numberOfNewProcessedRecords);
int CSVParser_GetFieldFromRecord(char filename[], int recordNum, char fieldName[], char value[]);
int CSVParser_CountAllRecordsWithFieldValue(char filename[], char fieldName[], char value[]);
void CSVParser_GetRecordsWithFieldValue(char filename[], char fieldName[], char value[], int number, int recordNumbers[]);
char** CSV_Analyzer(char* runner, int* num_of_values);
char* fgetcsvl(char* line,int MAX_SIZE,FILE *Stream);
void HebrewConverter_convertHebrewUTF8toISO(char original[]); //file to cvi
void HebrewConverter_convertHebrewISOtoUTF8(char original[]); //cvi to file
//
