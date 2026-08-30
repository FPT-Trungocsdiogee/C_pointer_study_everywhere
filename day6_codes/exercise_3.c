#include <stdio.h>
void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i; 

    *sum = 0;
    for (i = 0; i < n; i++)
    {
        *sum += a[i];
    }
    *avg = *sum / n;
}
int main(void)
{
    double a[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double avg, sum;
    avg_sum(a, 5, &avg, &sum);
    printf("Average: %.2f\n", avg);
    printf("Sum: %.2f\n", sum);
    return 0;
} 
