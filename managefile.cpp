#include "managefile.h"


#include <QDebug>
FILE* openFile(char* fileName){ // Открытие файла
    return fopen(fileName, "r");
}


void scanFile(FILE* file, Data* data){ // Получение данных из файла
    rewind(file);
    char* line = allocateString(SIZE_LINE);
    char** splitLine = allocateMas(data->countColumn, SIZE_LINE);
    fgets(line, SIZE_LINE, file);
    stringSplit(data->nameColumn, line, data->countColumn);
    int i = 0;
    while (fgets(line, SIZE_LINE, file) != NULL){
        if (!checkLine(line))
            continue;
        stringSplit(splitLine, line, data->countColumn);
        if (!strcmp(splitLine[1], data->region)){ // Проверка региона
            copyMas(data->content[i], splitLine, data->countColumn);
            i++;
        }
    }
    clearString(line);
    clearMas(splitLine, data->countColumn);
}


int getLenRegion(FILE* file, Data* data){ // Получение количества строк в файле
    rewind(file);
    char* line = allocateString(SIZE_LINE);
    char** splitLine = allocateMas(data->countColumn, SIZE_LINE);
    int count = 0;
    while (fgets(line, SIZE_LINE, file) != NULL){
        if (!checkLine(line))
            continue;
        stringSplit(splitLine, line, data->countColumn);
        if (!strcmp(splitLine[1], data->region))
            count++;
    }
    clearString(line);
    clearMas(splitLine, data->countColumn);
    return count;
}


int getCountColumn(FILE* file){ // Получение количества колонок в файле
    rewind(file);
    int count = 1;
    char* line = allocateString(SIZE_LINE);
    fgets(line, SIZE_LINE, file);
    for (int i = 0; line[i]; i++){
        if (line[i] == ','){
            count++;
        }
    }
    clearString(line);
    return count;
}

bool checkCorrectCsv(FILE* file, int countColumn){ // Проверка корректности файла
    rewind(file);
    bool error = false;
    char* line = allocateString(SIZE_LINE);
    while (fgets(line, SIZE_LINE, file) != NULL){
        int count = 1;
        for (int i = 0; line[i]; i++){
            if (line[i] == ','){
                count++;
            }
        }
        if (count != countColumn)
            error = true;
    }
    clearString(line);
    return error;
}

bool completeData(FILE* file, Data* data){
    data->countColumn = getCountColumn(file);
    data->size = getLenRegion(file, data);

    // Выделение памяти
    data->content = allocateMatrix(data->size, data->countColumn, SIZE_LINE);
    data->nameColumn = allocateMas(data->countColumn, SIZE_LINE);
    if (data->content == NULL || data->nameColumn == NULL)
        return false;
    else
        return true;
}
