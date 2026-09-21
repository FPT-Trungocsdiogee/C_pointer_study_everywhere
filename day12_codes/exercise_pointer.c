#include <stdio.h>
double inner_product (const double *a, const double *b,
int n)
{
    double sum = 0; 
    const double *p = a, *q = b;
    while (n-- > 0)
        sum += *p++ * *q++;
    return sum;
}
int main (void)
{
    double a[3] = {1.0, 2.0, 3.0}, b[3] = {4.0, 5.0, 6.0};
    printf ("inner_product(a, b) = %f\n", inner_product (a, b, 3));
    return 0;
}