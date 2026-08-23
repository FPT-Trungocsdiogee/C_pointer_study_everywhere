#include <stdio.h>

int main(void) {
    //int *p;
    //printf("%d", *p);   /*** WRONG ***/

    //*p = 1;
   //printf("%d", *p);   /*** WRONG ***/

    //Correct usage:
    int value = 42; 
    int *good_p = &value;
    printf("%d", *good_p);
    

    return 0;
}