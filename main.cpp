#include <stdio.h>
#include <stdlib.h>
#include "assembler.h"

int main()
{
    buffer read_buffer = read_file("assembler.txt", "rb");

    if (read_buffer.ptr == NULL)
    {
        fprintf(stderr, "The file can't be opened");
        return 1;
    }
    printf("|%s|\n", read_buffer);

}