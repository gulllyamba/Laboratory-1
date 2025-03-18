#ifndef ERROR_ERROR_H
#define ERROR_ERROR_H

#include <stdio.h>

typedef enum error{
    ERROR_NULL_POINTER,
    ERROR_MEMORY_ALLOCATION,
    ERROR_INVALID_MATRIX_SIZE,
    ERROR_INVALID_DATA_TYPE,
    ERROR_INVALID_MATRIX_INDICES,
    ERROR_MISMATCH_MATRIX_SIZES,
    ERROR_FILE_READ,
    ERROR_UNKNOWN
} error_t;

void log_error(error_t Error, char* path);

#endif //ERROR_ERROR_H