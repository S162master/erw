#ifndef MANAGEFILE_H
#define MANAGEFILE_H

#include <stdio.h>
#include "memory.h"
#include <string.h>
#include "editstring.h"

#define SIZE_LINE 150


struct Data {
    char* path; // Путь до файла
    char** nameColumn; // массив имен колонок
    char*** content; // Данные из файла
    int countColumn; // количество колонок
    int size; // количество строк
    char* region; // регион
    int col; // номер колонки для подсчета данных
};



FILE* openFile(char* fileName);
void scanFile(FILE* file, Data* data);
int getCountColumn(FILE* file);
int getLenRegion(FILE* file, Data* data);
bool completeData(FILE* file, Data* data);
bool checkCorrectCsv(FILE* file, int countColumn);



#endif // MANAGEFILE_H
