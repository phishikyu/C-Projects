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

    
    printf("STRING DUPLICATE:\n");
    char dupSrcStr1[] = "Duplicate me!\n";
    char *dupDstStr1 = phistrdup(dupSrcStr1);
    printf("In use: %s\n", dupDstStr1);    // normal output

    free(dupDstStr1);
    printf("Free: %s\n", dupDstStr1);     // garbage data, results in heap-use-after-free when run in debug mode

    dupDstStr1 = NULL;
    printf("Null: %s\n", dupDstStr1);     // segfault, using 

}