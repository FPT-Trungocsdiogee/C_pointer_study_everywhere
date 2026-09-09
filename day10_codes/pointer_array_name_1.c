#include <stdio.h>
int main(void)
{
    int a[15]; // Khai báo mảng a

    *a = 10; // Gán giá trị cho phần tử của mảng 
    // In ra giá trị phần tử theo hai cách khác nhau
    printf("Gia tri cua *a: %d\n", *a); 
    printf("Gia tri cua a[0]: %d\n", a[0]);

    *(a + 1) = 20;
    printf("Gia tri cua *(a + 1): %d\n", *(a + 1));
    printf("Gia tri cua a[1]: %d\n", a[1]);

    *(a + 5) = 30;
    printf("Gia tri cua *(a + 5): %d\n", *(a + 5));
    printf("Gia tri cua a[5]: %d\n", a[5]);

    return 0;
}