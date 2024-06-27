#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "assembler.h"

struct command
{
    const char* str;
    enum INPUT_COMMAND encoding;
};

struct command cmds[] = {{"push", PUSH}, {"add", ADD}, {"div", DIV}, {"htl", HTL}, {"out", OUT}, {"sub", SUB}, {"mul", MUL}, {"pop", POP}};

long file_size(FILE* open_file)
{
    long orig_pos = ftell(open_file);
    fseek(open_file, 0, SEEK_END);

    long end_pos = ftell(open_file);
    fseek(open_file, orig_pos, SEEK_SET);

    return end_pos;  
}

buffer read_file(const char *restrict filename, const char *restrict mode)
{   
    FILE* open_file = fopen(filename, mode);
    struct buffer invalid = {NULL, 0};
    if (fopen(filename, mode) == NULL) return invalid;

    long file_sz = file_size(open_file);
    char* data = (char*) calloc(file_sz+1, sizeof(char));
    if (data == NULL) return invalid;

    fread(data, sizeof(char), file_sz, open_file);
    struct buffer cur_buffer = {data, file_sz};

    fclose(open_file);

    return cur_buffer;
}

int find_spaces(const char* str)
{
    assert(str);
    for (int i = 0; str[i] != 0; i++)
    {
        if (isspace(str[i])) return i;
 
    }
    return -1;
}

int skip_spaces(const char* str)
{
    assert(str);
    for (int i = 0; str[i] != 0; i++)
    {
        if (!isspace(str[i])) return i;
 
    }
    return -1;
}

enum INPUT_COMMAND get_encoding(const char* data)
{
    for (int i = 0; i < N_COMMANDS; i++)
    {
        if (!strcmp(data, cmds[i].str)) return cmds[i].encoding;
    }
    return INVALID;
}

const char* get_str(enum INPUT_COMMAND encoding)
{
    for (int i = 0; i < N_COMMANDS; i++)
    {
        if (encoding == cmds[i].encoding) return cmds[i].str;
    }
    return NULL;
}

int converter(FILE* open_file)
{   
    char* data = read_file(open_file);
    if (data == NULL) return -1;
    long file_sz = file_size(open_file);
    char* ptr = data;
    
    char* output_data = (char*)malloc(file_sz);
    char* out_ptr = output_data; 

    while (*ptr != '\0')
    {
        int start_i = skip_spaces(ptr);
        if (start_i == -1) 
        {
            return -1;
            free(data);
        }

        ptr += start_i;

        int stop_i = find_spaces(ptr);
        if (stop_i == -1) 
        {
            return -1;
            free(data);
        }

        char* end_ptr = ptr + stop_i;

        *end_ptr = '\0';
        
        enum INPUT_COMMAND encoding = get_encoding(ptr);
        if (encoding == INVALID) 
        {
            return INVALID;
            free(data);
        }
        ptr = end_ptr + 1;

        *out_ptr = encoding;

        const char* str_encoding = get_str(encoding);

        out_ptr += strlen(str_encoding);

        if (encoding == PUSH || encoding == POP)
        {
            if (start_i == -1) 
            {
                return -1;
                free(data);
            }
            
            int arg = strtol(ptr, &end_ptr, 10);
            *out_ptr = arg;
            out_ptr += 4;
        }
    }

    return *((int*)out_ptr);
}
