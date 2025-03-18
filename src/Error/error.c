#include "error.h"

void log_error(error_t Error, char* path) {
    static const char* error_messages[] = {
        "null pointer",
        "memory allocation",
        "invalid matrix size",
        "invalid data type",
        "invalid matrix indices",
        "mismatch matrix sizes",
        "file read",
        "unknown"
    };
    if (Error < 0 || Error > ERROR_FILE_READ) Error = ERROR_UNKNOWN;
    printf("%s ERROR(%s)\n", path, error_messages[Error]);
}