#ifndef ASSEMBLER_H 
#define ASSEMBLER_H
#include <stdio.h>

int converter(FILE* open_file);

char* read_file(FILE* open_file);
long file_size(FILE* open_file);
int find_spaces(const char* str);
int skip_spaces(const char* str);

enum INPUT_COMMAND check_if(const char* data);

int shift(const char* str);

#endif