#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

// #include "workWithFile.h"
#include "logic.h"

enum Operation {
    LOAD_DATA,
    CALC,
};

bool doOperation(Operation operation, Data* data, Numbers* numbers);

#endif // ENTRYPOINT_H
