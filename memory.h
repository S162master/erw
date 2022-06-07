#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

char* allocateString(int size);
char** allocateMas(int count, int size);
char*** allocateMatrix(int len, int count, int size);

void clearString(char* string);
void clearMas(char** mas, int count);
void clearMatrix(char*** matrix, int len, int count);

#endif // MEMORY_H
