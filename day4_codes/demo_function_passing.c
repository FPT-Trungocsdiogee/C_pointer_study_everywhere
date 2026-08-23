#include <stdio.h>
void valueSwitch(int a, int b) //Switching function using value passing
{
    int temp = a;
    a = b;
    b = temp;
}
void referenceSwitch(int *a, int *b) //Switching function using reference passing
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{
    int x = 5, y = 10;
    printf("Before switch: x = %d, y = %d\n", x, y);
    
    valueSwitch(x, y); //Value passing
    printf("After value switch: x = %d, y = %d\n", x, y);

    referenceSwitch(&x, &y); //Reference passing
    printf("After reference switch: x = %d, y = %d\n", x, y);
    return 0;
}