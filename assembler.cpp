#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <assert.h>
#include "assembler.h"

enum INPUT_COMMANDS
{
    HTL,
    OUT,
    SUB,
    DIV,
    ADD,
    MUL,
    POP,
    PUSH,
    N_COMMANDS,
    INVALID = -1,
};

struct commands
{
    const char* str;
    enum INPUT_COMMANDS encoding;
};

struct commands cmds[] = {{"push", PUSH}, {"add", ADD}, {"div", DIV}, {"htl", HTL}, {"out", OUT}, {"sub", SUB}, {"mul", MUL}, {"pop", POP}};

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
    long file_sz = file_size(open_file);
    char* data = (char*) calloc(file_sz+1, sizeof(char));
    fread(data, sizeof(char), file_sz, open_file);
    return data;
}

int find_spaces(const char* str)
{
    assert(str);
    for (int i = 0; str[i] != 0; i++)
    {
        if (isspace(str[i])) return i;
 
    }
    return INVALID;
}

int skip_spaces(const char* str)
{
    assert(str);
    for (int i = 0; str[i] != 0; i++)
    {
        if (!isspace(str[i])) return i;
 
    }
    return INVALID;
}

#if 0
enum INPUT_COMMANDS check_if(const char* data)
{
    for (int i = 0; i < N_COMMANDS; i++)
    {
        if (!strcmp(data, cmds[i].str)) return cmds[i].encoding;
    }
    return INVALID;
}

int shift(const char* str)
{
    int length = strlen(str);
    return length;
}

int converter(FILE* open_file)
{   
    char* data = read_file(open_file);
    long file_sz = file_size(open_file);
    if (data == NULL) return INVALID;
    char* ptr = data;
    
    char* output_data = malloc(file_sz);
    char* out_ptr = output_data; 

    while (*ptr != '\0')
    {
        int start_i = skip_spaces(ptr);
        if (start_i == -1) return -1;
        ptr += start_i;

        int stop_i = find_spaces(ptr);
        if (stop_i == -1) return -1;
        char* end_ptr = ptr + stop_i;

        *end_ptr = '\0';
        
        enum INPUT_COMMANDS encoding = check_if(ptr);
        ptr = end_ptr + 1;

        output_data[out_ptr] = encoding;

        out_ptr += shift(encoding);

        if (encoding == INVALID) return INVALID;
        
        else if (encoding == PUSH || encoding == POP)
        {
            if (start_i) == -1 return INVALID;
            
            int arg = strtol(ptr, &end_ptr, 10);
            
        }

       
    }

}
#endif

#if 0
char* read_file(FILE* open_file)
{
    // open and close file right here, not in main or anywhere else
    char* data = (char*) calloc(file_size(open_file)+1, sizeof(char));
    fread(data, sizeof(char), file_size(open_file), open_file);
    return data;
}

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

char* output_buff = ....;
*output_buff = PUSH;
output_buff++;
*((int*)output_buff) = 4; <=> int x = 4; memcpy(output_buff, &x, sizeof(int));
#endif