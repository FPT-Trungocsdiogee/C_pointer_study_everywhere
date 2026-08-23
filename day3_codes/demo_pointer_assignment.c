#include <stdio.h>
int main(void) 
{
    int i, j, *p, *q;
    p = &i;
    q = p;

    *p = 1;
    printf("%d, %d, %d\n", i, *p, *q);
    *q = 2;
    printf("%d, %d, %d\n", i, *p, *q);

}