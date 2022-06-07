#include "logic.h"


bool loadData(Data* data){ // Работа с файлом
    bool error = false;
    FILE* file = fopen(data->path, "r");

    if (file){

        if (data->content){
            // Очистка памяти
            clearMatrix(data->content, data->size, data->countColumn);
            clearMas(data->nameColumn, data->countColumn);
        }
        if (completeData(file, data)){
            if (!checkCorrectCsv(file, data->countColumn)){
                scanFile(file, data);
            }
            else {
                error = true;
            }
        }
        else{
            error = true;
        }
        fclose(file);
    }
    else {
        error = true;
    }
    return error;
}


bool calcColm(Data* data, Numbers* numbers){ // Проверка корректности номера колонки
    bool error = false;
    if (data->col > data->countColumn || data->col < 2){
        error = true;
    }
    else {
        error = completeNumbers(data, numbers);
    }
    return error;
}



bool completeNumbers(Data* data, Numbers* numbers){ // Заполнение структуры Numbers (максимальное, минимальное, медиана)
    double* masNumber = (double*)calloc(data->size, sizeof(double));
    if (masNumber != NULL){
        for (int i = 0; i < data->size; i++){
            masNumber[i] = atof(data->content[i][data->col]);
        }
        sortMas(masNumber, data->size);
        if (data->size) {
            numbers->max = masNumber[data->size - 1];
            numbers->min = masNumber[0];
            numbers->mediana = getMediana(masNumber, data->size);
        }
        else {
            numbers->max = 0;
            numbers->min = 0;
            numbers->mediana = 0;
        }
        free(masNumber);
        return false;
    }
    else{
        return true;
    }
}


void sortMas(double* mas, int size){ // Сортировка массива
    for (int i = 0; i < size - 1; i++){
        for (int j = i; j < size; j++){
            if (mas[i] > mas[j]){
                swap(mas + i, mas + j);
            }
        }
    }
}


void swap(double* a, double* b){ // Смена элементов в массиве
    double time = *a;
    *a = *b;
    *b = time;
}


double getMediana(double* mas, int size){ // Подсчет медианы
    if (size % 2){
        return mas[size/2];
    }
    else {
        return (mas[size/2] + mas[size/2 - 1]) / 2;
    }
}
