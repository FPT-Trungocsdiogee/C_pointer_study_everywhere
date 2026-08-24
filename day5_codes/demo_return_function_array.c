#include <stdio.h>
int *arraySelectedReturn(int n, int arr[], int *index)
{
    if(*index < n)
    {
        return &arr[*index];
    }
    else
    {
        return NULL;
    }
}
int main(void)
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int index;
    printf("Enter the index of the element to return: ");
    scanf("%d", &index);
    int *result = arraySelectedReturn(n, arr, &index);
    if(result != NULL)
    {
        printf("The element at index %d is: %d\n", index, *result);
    }
    else
    {
        printf("Index out of bounds.\n");
    }
}