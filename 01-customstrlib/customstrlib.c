#include "customstrlib.h"
#include <stdlib.h>
#include <stdio.h>

// Custom functions for strings, based off of existing functions within the string.h library

// Based on strlen function
int phistrlen(char *str) {
    char currentChar = str[0];
    int count = 0;

    while (currentChar != '\0') {
        count++;
        currentChar = str[count];
    }

    return count;
}

// Based on strcopy function
char *phistrcopy(char *dststr, const char *srcstr) {
    char currentChar = srcstr[0];
    int count = 0;
    
    while (currentChar != '\0') {
        dststr[count] = srcstr[count];
        count++;
        currentChar = srcstr[count];
    }

    return dststr;
}

// Duplicates the entire string and allocates memory accordingly
char *phistrdup(char *srcstr) {
    int count = 0;
    
    int bufferLength = phistrlen(srcstr);
    char *startAddress = malloc(bufferLength + 1);
    char *currentAddress = startAddress;

    while ((currentAddress - startAddress) < (bufferLength + 1)) {
        *currentAddress = srcstr[count];
        count++;
        currentAddress++;
    }

    return startAddress;
}