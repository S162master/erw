#include "memory.h"


char* allocateString(int size){
    return (char*)calloc(size, sizeof(char));
}


char** allocateMas(int count, int size){
    char** mas = (char**)calloc(count, sizeof(char*));
    for (int i = 0; i < count; i++){
        mas[i] = allocateString(size);
    }
    return mas;
}

char*** allocateMatrix(int len, int count, int size){
    char*** matrix = (char***)calloc(len, sizeof(char**));
    for (int i = 0; i < len; i++){
        matrix[i]  = allocateMas(count, size);
    }
    return matrix;
}


void clearString(char* string){
    free(string);
}

void clearMas(char** mas, int count){
    for (int i = 0; i < count; i++){
        free(mas[i]);
    }
    free(mas);
}

void clearMatrix(char*** matrix, int len, int count){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < count; j++){
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}
