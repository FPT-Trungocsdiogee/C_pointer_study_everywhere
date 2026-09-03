#include <stdio.h>
int main(void)
{
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    printf("Address of a[0]: %p, Address of a[1]: %p\n", (void*)&a[0], (void*)&a[1]);
    int *p, *q;
    p = &a[0];
    q = &a[1];
    printf("q - p = %ld\n", q - p);
    return 0;
}