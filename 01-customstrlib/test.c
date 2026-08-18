#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "customstrlib.h"

int main() {
    
    printf("STRING LENGTH:\n");
    
    printf("%s" "%d" "%s", "test - ", phistrlen("test"), "\n");
    printf("%s" "%d" "%s", "testnumbertwo - ", phistrlen("testnumbertwo"), "\n");
    printf("%s" "%d" "%s", "the big potato - ", phistrlen("the big potato"), "\n");
    
    assert(phistrlen("test") == 4);
    assert(phistrlen("testnumbertwo") == 13);
    assert(phistrlen("the big potato") == 14);


    printf("\nSTRING COPY:\n");
    char srcStr1[] = "Hi guys\n";
    char dstStr1[100];

    char srcStr2[] = "Memory allocation is fun\n";
    char dstStr2[100];

    char srcStr3[] = "Another one-??\n";
    char dstStr3[100];
    printf("%s", phistrcopy(dstStr1, srcStr1));
    printf("%s", phistrcopy(dstStr2, srcStr2));
    printf("%s", phistrcopy(dstStr3, srcStr3));
    
    // assert strcmp here later

    
    printf("\nSTRING DUPLICATE:\n");
    char *dupSrcStr1 = "Duplicate me!";
    char *dupDstStr1 = phistrdup(dupSrcStr1);
    printf("In use: %s\n", dupDstStr1);    // normal output

    free(dupDstStr1);
    printf("Free: %s\n", dupDstStr1);     // garbage data, results in heap-use-after-free when run in debug mode

    dupDstStr1 = NULL;
    printf("Null: %s\n", dupDstStr1);     // segfault 


    printf("\nSTRING CONCAT:\n");
    char *strcat1 = "Mewo";
    char *strcat2 = "MewoMewo\n";
    char buff[256];
    phistrcat(strcat1, strcat2, buff);

    char *strcat3 = phistrcatmalloc(strcat1, strcat2);

    printf("%s", buff);
    printf("%s", strcat3);


    printf("\nSTRING COMPARE:\n");
    char *strcmp1 = "match"; 
    char *strcmp2 = "match";
    
    char *strcmp3 = "no match";
    char *strcmp4 = "doesn't match"; 

    printf("%d" "%s", phistrcmp(strcmp1, strcmp2), "\n");
    printf("%d" "%s", phistrcmp(strcmp3, strcmp4), "\n");


    printf("\nSTRING LOCATE:\n");
    char chr1 = 'a';
    char chr2 = 'd'; 
    char *strchr1 = "find me";

    printf("%s - ", phistrchr(strchr1, chr1));
    printf("%p\n", phistrchr(strchr1, chr1));
    
    printf("%s - ", phistrchr(strchr1, chr2));
    printf("%p\n", phistrchr(strchr1, chr2));

}