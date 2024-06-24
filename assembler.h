#ifndef ASSEMBLER_H 
#define ASSEMBLER_H
#include <stdio.h>

int converter(FILE* open_file);

char* read_file(FILE* open_file);
long file_size(FILE* open_file);
int find_spaces(const char* str);
int skip_spaces(const char* str);

enum INPUT_COMMAND get_encoding(const char* data);


#endif