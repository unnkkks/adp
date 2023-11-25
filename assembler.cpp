#include "assembler.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
enum INPUT_TASKS{
    DIV  = -3,
    HTL  = -2,
    SUB  = -1,
    OUT  =  0,
    PUSH =  1,
    ADD  =  2,
    MUL  =  3,
    POP  =  4,
};

// TODO: zabotay git submodules for Perun's sake

#if 0
struct commands{
    const char* str;
    enum INPUT_TASKS encoding;
};

struct commands cmds[] = {{"push", PUSH}, {"add", ADD}, {"div", DIV}, {"htl", HTL, {"out", OUT}, {"sub", SUB}, {"mul", MUL}, {"pop", POP}};

size_t str_len = strlen(str);
for (int i = 0; i < sizeof(cmds); ++i)
{
    if (str_len == strlen(cmds[i].str) && !strcmp(str, cmds[i].str))
    {
        output_buff[output_i] = cmds[i].encoding;
    }
}
#endif

long file_size(FILE* open_file)
{
    long orig_pos = ftell(open_file);
    fseek(open_file, 0, SEEK_END);
    long end_pos = ftell(open_file);
    fseek(open_file, orig_pos, SEEK_SET);
    return end_pos;  
}
char* read_file(FILE* open_file)
{
    // open and close file right here, not in main or anywhere else
    char* data = (char*) calloc(file_size(open_file)+1, sizeof(char));
    fread(data, sizeof(char), file_size(open_file), open_file);
    return data;
}
#if 0
int my_converter(FILE* open_file)
{   
    char* data = read_file(open_file)
    for (int i = 0; i < filesize(open_file); i++)
    {
        if (data[i] == ' ')
        {
            data[i] == '\0';
            str
        }

    }
}
#endif

#if 0
char* output_buff = ....;
*output_buff = PUSH;
output_buff++;
*((int*)output_buff) = 4; <=> int x = 4; memcpy(output_buff, &x, sizeof(int));
#endif