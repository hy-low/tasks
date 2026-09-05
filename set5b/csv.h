typedef struct CsvReader CsvReader;

typedef struct CsvRecord {
    int count;
    char **fields;
} CsvRecord;

CsvReader* csv_open(char *filename);
CsvRecord* csv_next_record(CsvReader *reader);
void csv_free_record(CsvRecord *record);
void csv_free(CsvReader *reader);
