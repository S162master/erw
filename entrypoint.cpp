#include "entrypoint.h"


bool doOperation(Operation operation, Data* data, Numbers* numbers){ // Единая точка входа
    bool error = false;
    switch (operation){
        case LOAD_DATA:
            error = loadData(data);
            break;
        case CALC:
            error = calcColm(data, numbers);
            break;
    }
    return error;
}
