#include <stdio.h>
int sum(int a[], int n)
{
    int sum = 0;
    for(int *p = &a[0]; p < &a[n]; p++)
    {
        sum += *p;
    }
    return sum;
}
int main(void)
{
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    printf("Sum of array elements: %d\n", sum(a, 10));
    return 0;
}