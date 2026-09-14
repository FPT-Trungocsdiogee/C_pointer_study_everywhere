#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("Enter the number of rows and columns: ");
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];
    for(int *p = &arr[0][0]; p <= &arr[rows-1][cols-1]; p++)
    {
        *p = rand();
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}