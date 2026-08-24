#include <stdio.h>
int *max(int *a, int *b) {
    if (*a > *b) { //Compare the values pointed to by a and b
        return a; //Return the address of the maximum value
    } else {
        return b;
    }
}
int main(void) {
    int x = 10, y = 20, *result; //Declaring variables and pointer
    result = max(&x, &y); //Call the function with the addresses of x and y
    printf("The maximum value is: %d\n", *result);
    return 0;
}