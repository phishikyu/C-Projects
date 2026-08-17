#ifndef CUSTOMSTRLIB_H
#define CUSTOMSTRLIB_H

// Custom functions for strings, based off of existing functions within the string.h library
int phistrlen(char *str);

char *phistrcopy(char *dststr, const char *srcstr);

char *phistrdup(char *srcstr);

#endif