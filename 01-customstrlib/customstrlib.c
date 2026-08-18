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

    dststr[count] = '\0';

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

// Based on strcat function
char *phistrcat(char *str1, char *str2, char *strdst) {
    phistrcopy(strdst, str1);
    phistrcopy(strdst + phistrlen(str1), str2);

    return strdst;
}

// strcat but slightly slower and allocates without needing a buffer
char *phistrcatmalloc(char *str1, char *str2) {
    int strcatlen = phistrlen(str1) + phistrlen(str2) + 1; 

    char *newstr = malloc(strcatlen);

    phistrcopy(newstr, str1);
    phistrcopy(newstr + phistrlen(str1), str2);

    return newstr;
}

// Based on strcmp function
int phistrcmp(char *str1, char *str2) {
    
    // char currentChar = str1[0];
    int index = 0;

    while (str1[index] != '\0' && str2[index] != '\0') {
        if (str1[index] != str2[index]) {
            return 0;
        }

        index++;
    }

    return 1;
}

// Based on strchr function
char *phistrchr(char *s, char c) {
    int index = 0;

    while (s[index] != '\0') {
        if (s[index] == c) {
            break;
        }
        index++;
    }

    if (s[index] == '\0') return NULL;
    else return &s[index];
}

// Based on strstr function
char *phistrstr(char *str, char *substr) {
    int startIndex = 0;
    int len = phistrlen(str);
    int sublen = phistrlen(substr);

    while (str[startIndex] != '\0' && startIndex < len - sublen) {
        int match = 1;

        for (int i = 0; i < sublen; i++) {
            if (str[startIndex + i] != substr[i]) {
                match = 0;        
                break;
            }
        }
        
        if (match == 1) {
            return &str[startIndex];
        }

        startIndex++;
    }

    return NULL;
}