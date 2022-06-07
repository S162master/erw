#ifndef LOGIC_H
#define LOGIC_H

#include "managefile.h"

struct Numbers {
    double min;
    double max;
    double mediana;
};


bool completeNumbers(Data* data, Numbers* numbers);
double getMediana(double* mas, int size);
void swap(double* a, double* b);
void sortMas(double* mas, int size);
bool loadData(Data* data);
bool calcColm(Data* data, Numbers* numbers);

#endif // LOGIC_H
