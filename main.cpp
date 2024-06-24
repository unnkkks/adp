#include <stdio.h>
#include <stdlib.h>
#include "assembler.h"

int main()
{
    FILE* open_file = fopen("assembler.txt", "rb");
    char* read_buffer = read_file(open_file);

    if (open_file == NULL)
    {
        fprintf(stderr, "The file can't be opened");
        return 1;
    }
    printf("|%s|\n", read_buffer);
    
    free(read_buffer);

    fclose(open_file);
}