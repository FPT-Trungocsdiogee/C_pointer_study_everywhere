#include <stdio.h>
#include <stdlib.h>
void print_array(int rows, int cols, int arr[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int *p = arr[i]; p < arr[i] + cols; p++)
        {
            printf("%d ", *p);
        }
        printf("\n");
    }
}
void print_transpose(int rows, int cols, int arr[rows][cols])
{
    int (*p)[cols];
    for(int j = 0; j < cols; j++)
    {
        for(p = &arr[0]; p < &arr[rows]; p++)
        {
            printf("%d ", (*p)[j]);
        }
        printf("\n");
    }
}
void print_transpose2(int rows, int cols, int arr[rows][cols])
{
    int (*p)[cols]; //Khai báo con trỏ p trỏ đến mảng 1 chiều có cols phần tử
    for(int j = 0; j < cols; j++)
    {
        for(p = arr; p < arr + rows; p++)
        {
            printf("%d ", (*(p))[j]);
        }
        printf("\n");
    }
}
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
    print_array(rows, cols, arr);
    printf("\n");
    print_transpose(rows, cols, arr);
    printf("\n");
    print_transpose2(rows, cols, arr);
    return 0;
}