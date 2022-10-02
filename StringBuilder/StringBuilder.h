#ifndef STRING_BUILDER
#define STRING_BUILDER

typedef struct StringBuilder{
    char* array;
    int size;
    int char_count;
} StringBuilder;

void initStringBuilder(StringBuilder *sb, int size);

void growStringBuilder(StringBuilder *sb);

void printStringBuilder(StringBuilder *sb);

void appendString(StringBuilder *sb, char *string, int length);

#endif