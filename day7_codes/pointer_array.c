#include <stdio.h>
int main(void)
{
    int a[10], *p; // Declaring array and pointer
    p = &a[0]; // Assigning the address of the first element of the array to the pointer
    printf("%d %d\n", *p, a[0]); // Print the value before assignment
    *p = 10;
    printf("%d %d\n", *p, a[0]); // Print the value after assignment
    return 0;
}