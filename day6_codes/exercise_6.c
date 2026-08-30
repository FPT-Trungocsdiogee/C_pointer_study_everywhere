#include <stdio.h>
void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    *largest = *second_largest = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > *largest)
        {
            *largest = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > *second_largest && a[i] < *largest)
        {
            *second_largest = a[i];
        }
    }

}
int main(void)
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int largest, second_largest;
    find_two_largest(a, n, &largest, &second_largest);
    printf("Largest: %d\n", largest);
    printf("Second Largest: %d\n", second_largest);
    return 0;
}