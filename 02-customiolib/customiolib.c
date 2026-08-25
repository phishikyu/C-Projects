#include <stdio.h>
#include <stdlib.h>

#include "customiolib.h"
#include "../01-customstrlib/customstrlib.h"

// Functions go here

char *read_line() {
    char *buf = malloc(256);
    char *input = fgets(buf, 256, stdin);

    if (input != NULL) {
        return buf;
    }
    
    free(buf);
    return NULL;
}


// ignores any non-numerical values without crashing on invalid characters
int read_int() {
    char *result = read_line();
    int counter = 0;
    int newInt = 0;

    while (result[counter] != '\0') {
        if (result[counter] >= '0' && result[counter] <= '9') {
            newInt = newInt * 10 + (result[counter] - '0');
        }

        counter++;
    }

    free(result);
    return newInt;
}

float read_float() {
    return 0.0f;
}