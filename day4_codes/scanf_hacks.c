#include <stdio.h>
int main(void)
{
    int i, *p;
    p = &i;

    printf("Enter an integer: ");
    //scanf("%d", p); //Using pointer to read input
    //scanf("%d", &p); //Incorrect method
    scanf("%d", i); //Incorrect method
    printf("You entered: %d\n", i);

    return 0;
}