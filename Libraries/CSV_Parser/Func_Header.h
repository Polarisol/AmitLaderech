int CSVParser_GetNumberOfRecords(char filename[]);
int CSVParser_NewRecords(char filename[]);
void CSVParser_MarkAsProcessed(char filename[], int numberOfNewProcessedRecords);
char** CSV_Analyzer(char* runner, int* num_of_values);
int CSVParser_GetFieldFromRecord(char filename[], int recordNum, char fieldName[], char value[]) ;
int CSVParser_CountAllRecordsWithFieldValue(char filename[], char fieldName[], char value[]);
