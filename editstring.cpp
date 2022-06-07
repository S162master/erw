#include "editstring.h"


void stringSplit(char** newString, char* string, int count){ // Разделение строки на массив по запятой
    char* time;
    time = strtok(string, ",");
    for (int i = 0; i < count; i++){
        strcpy(newString[i], time);
        time = strtok(NULL, ",");
    }
}


void copyMas(char** newMas, char** mas, int count){ // Копирование массива строк
    for (int i = 0; i < count ; i++){
        strcpy(newMas[i], mas[i]);
    }
}


bool checkLine(char* line){ // Проверка на наличие пустых колонок в файле
    bool correct = true;
    for (int i = 1; line[i]; i++){
        if (line[i-1] == ',' && line[i] == ','){
            correct = false;
            break;
        }
    }
    return correct;
}
