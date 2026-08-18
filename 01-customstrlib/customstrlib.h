#ifndef CUSTOMSTRLIB_H
#define CUSTOMSTRLIB_H

// Custom functions for strings, based off of existing functions within the string.h library
int phistrlen(char *str);

char *phistrcopy(char *dststr, const char *srcstr);

char *phistrdup(char *srcstr);

char *phistrcat(char *str1, char *str2, char *strdst);

char *phistrcatmalloc(char *str1, char *str2);

int phistrcmp(char *str1, char *str2);

char *phistrchr(char *s, char c);

char *phistrstr(char *str1, char *str2);

#endif