#include <stdio.h>
int array_sum_traditional(int a[], int n) // Cách truyền thông thường
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}
int array_sum_pointer_1(int *a, int n) // Cách sử dụng phép toán số học trên con trỏ
{
    int sum = 0;
    for (int *p = &a[0]; p < &a[n]; p++)
    {
        sum += *p;
    }
    return sum;
}
int array_sum_pointer_2(int *a, int n) // Cách sử dụng tên mảng như một con trỏ
{
    int sum = 0;
    for (int *p = a; p < a + n; p++)
    {
        sum += *p;
    }
    return sum;
}
int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Tong cua mang (cach truyen thong): %d\n", array_sum_traditional(a, 10));
    printf("Tong cua mang (cach su dung con tro 1): %d\n", array_sum_pointer_1(a, 10));
    printf("Tong cua mang (cach su dung con tro 2): %d\n", array_sum_pointer_2(a, 10));
    return 0;
}