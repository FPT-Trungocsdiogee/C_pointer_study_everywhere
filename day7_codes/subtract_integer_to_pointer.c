#include <stdio.h>
int main(void)
{
    int a[15] = {1,2,3,4,5,6,8,10,14,22,30,60,120,250,500}, *p, *q; // Variable declaration

    p = &a[7]; // p -> a[7]. Then *p = 10
    printf("Initial value of p = %d\n",*p);

    q = p - 5; // q -> a[7-5] = a[2]. Then *q = 3
    printf("Value of q = %d\n",*q);

    p -= 6; // p(new) -> a[7-6] = a[1]. Then *p(new) = 2
    printf("Value of p after subtraction = %d\n",*p);

    return 0;
}