#include <stdio.h>
#include <stdlib.h>
#include "StringBuilder.h"

void initStringBuilder(StringBuilder *sb, int size)
{
    sb->array = malloc(size * sizeof(char)); 
    sb->char_count = 0;
    sb->size = size;
}

void growStringBuilder(StringBuilder *sb)
{
    sb->size = sb->size*2; // Double the size
    sb->array = realloc(sb->array, sb->size*sizeof(char));
}

void printStringBuilder(StringBuilder *sb)
{
    for (int i = 0; i < sb->char_count; i++)
    {
        printf("%c", *(sb->array+i));
    }
    printf("\n");
    printf("StringBuilder size: %d\n", sb->size);
    printf("StringBuilder char count: %d\n", sb->char_count);
}

void appendString(StringBuilder *sb, char *string, int length)
{
    for (int i = 0; i < length; i++)
    {
        if(sb->char_count==sb->size)
        {
            growStringBuilder(sb);
        }
        sb->array[sb->char_count] = string[i];
        sb->char_count++;
    }
    
}

int main() {
     
    StringBuilder sb;
    initStringBuilder(&sb, 1);

    while (sb.size<1000000)
    {
        char in[5];
        printf("Enter String (length 5): ");
        scanf("%s", in);
        appendString(&sb, in, sizeof(in));
        printStringBuilder(&sb);
    }
    
    return 0;
}