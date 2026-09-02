#include <stdio.h>
int main(void)
{
    int a[15] = {1,2,3,4,5,6,8,10,14,22,30,60,120,250,500}, *p, *q; // Variable declaration

    p = &a[1]; // p -> a[1]. Then *p = 2
    printf("Initial value of p = %d\n",*p);

    q = p + 5; // q -> a[1+5] = a[6]. Then *q = 8
    printf("Value of q = %d\n",*q);

    p += 10; // p(new) -> a[1+10] = a[11]. Then *p(new) = 60
    printf("Value of p after addition = %d\n",*p);

    return 0;
}