#ifndef TYPES_TYPESINFO_H
#define TYPES_TYPESINFO_H

#include "../DataTypes.h"

typedef struct TypeInfo {
    size_t size;
    size_t size_for_linear_combination;
    void (*init_zero) (void*);
    // void (*print) (void*);  //TODO: to_string
    void (*div) (void*, void*, void*); 
    void (*diff) (void*, void*, void*);
    void (*toString) (void*, int*, char**, size_t*);
    void (*sum) (void*, void*, void*);
    void (*multiply) (void*, void*, void*);
    void (*multiply_scalar) (void*, void*, void*);
    DataType_t type;
} TypeInfo_t;

#endif // TYPES_TYPESINFO_H