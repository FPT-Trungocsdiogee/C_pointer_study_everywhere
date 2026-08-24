#include <stdio.h>
int *find_largest(int a[], int n) // Function to find the largest element in an array
{
    int *largest = &a[0]; // Initialize largest to the first element
    for (int i = 1; i < n; i++) {
        if (a[i] > *largest) {
            largest = &a[i]; // Update largest if a larger element is found
        }
    }
    return largest; // Return pointer to the largest element
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int *largest = find_largest(a, n);
    printf("Largest element: %d\n", *largest);
    return 0;
}