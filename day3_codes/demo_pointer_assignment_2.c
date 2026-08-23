#include <stdio.h>
int main(void) 
{
    int i, j, *p, *q;
    p = &i;
    q = &j;

    i = 1;
    printf("%d, %d, %d, %d\n", i, j, *p, *q);
    *q = *p;
    printf("%d, %d, %d, %d\n", i, j, *p, *q);

}