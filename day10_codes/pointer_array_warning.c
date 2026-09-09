#include <stdio.h>
int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    // Wrong method:
    // while (*a != 0) {
    //     printf("%d\n", *a);
    //     a++;
    // }

    // Correct method:
    int *p = a; 
    while (*p != 0) {
        printf("%d\n", *p);
        p++;
    }
}