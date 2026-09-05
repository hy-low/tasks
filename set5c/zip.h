#include <time.h>

typedef struct ZipReader ZipReader;

typedef struct ZipEntry {
    char *filename;
    struct tm modified;
    int comp_method;
    int orig_size;
    int comp_size;
} ZipEntry;

ZipReader* zip_open(char *filename);
ZipEntry* zip_next_entry(ZipReader *reader);
void zip_free_entry(ZipEntry *entry);
void zip_free(ZipReader *reader);
