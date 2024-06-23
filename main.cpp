#include <stdio.h>
#include <stdlib.h>

char* read_file(FILE* open_file);

int main()
{
    FILE* open_file = fopen("assembler.txt", "rb");

    if (open_file == NULL)
    {
        fprintf(stderr, "The file can't be opened");
        return 1;
    }
    printf("|%s|\n", read_file(open_file));

    fclose(open_file);
}