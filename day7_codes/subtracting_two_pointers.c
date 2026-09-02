#include <stdio.h>
int main(void)
{
    int a[15] = {1,2,3,4,5,6,8,10,14,22,30,60,120,250,500}, *p, *q; // Variable declaration
    int i, j;
    printf("Enter the array indexes to subtract: ");
    scanf("%d %d",&i,&j);
    p = &a[i];
    q = &a[j];
    printf("p - q = %d\n", p - q);
    printf("i - j = %d\n", i - j);
    return 0;
}