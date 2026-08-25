#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "customiolib.h"
#include "../01-customstrlib/customstrlib.h"

int main(void) {
   char *rawInput = read_line();
   printf("%s", rawInput);
   
   // Always remember to free variables after use!
   free(rawInput);
   rawInput = NULL;


   // READ INT
   int myint = read_int();
   printf("%s%d", "very cool int: ", myint);

}