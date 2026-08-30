#include <stdio.h>
int *find_first_even(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            return &a[i];
        }
    }
    return NULL;
}
int main(void)
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    printf("Enter the elements: ");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int *first_even = find_first_even(a, n);
    if (first_even != NULL)
    {
        printf("First even number: %d\n", *first_even);
    }
    else
    {
        printf("No even number found.\n");
    }
}
    