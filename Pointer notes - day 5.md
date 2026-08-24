# Pointer notes - day 5
Hôm qua chúng ta đã tìm hiểu về cách con trỏ được dùng làm đầu vào của hàm.  Hôm nay, chúng ta sẽ tìm hiểu cách con trỏ làm giá trị trả về của một hàm.
## 1. Con trỏ làm giá trị trả về của hàm
Chúng ta không chỉ viết được hàm nhận đầu vào là con trỏ, mà còn viết được hàm trả về con trỏ. Các hàm như vậy rất phổ biến khi lập trình trong nhiều ứng dụng khác nhau.
Ví dụ như chương trình sau, trong đó hàm sẽ lấy đầu vào là 2 con trỏ của 2 số nguyên và nó sẽ trả con trỏ của số nguyên lớn hơn 
```c{.line-numbers}
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
```
Kết quả: 
```
The maximum value is: 20
```
Khi chúng ta gọi hàm, ta sẽ khai báo các biến như dòng 10 và gọi hàm như dòng số 11. Chúng ta sẽ truyền 2 con trỏ `&x, &y` vào hàm và con trỏ ra sẽ được lưu ở biến p.
Khi hàm `max` được gọi, *a sẽ truy cập vào i và *b sẽ truy cập vào j. Nếu giữa i và j số nào lớn hơn, hàm sẽ trả địa chỉ của số lớn và ngược lại. Sau khi quá trình hàm được gọi, p sẽ trỏ tới i hoặc j.
Mặc dù hàm có thể trả về 1 trong số những con trỏ được truyền vào như tham số, đây không phải là khả năng duy nhất của ứng dụng này. Hàm có thể trả về con trỏ trỏ tới biến bên ngoài (external variable), hoặc biến toàn cục ,hoặc biến cục bộ (local variable)được khai báo `static`.
## Lưu ý
Không nên viết hàm như sau:
```
int *f(void)
{
    int i;
    ...
    return &i;
}
```
Ở đây, biến i sẽ không tồn tại khi f trả kết quả, nên con trỏ trỏ vào nó sẽ không tồn tại.
# 2. Con trỏ trả về phần tử của xâu.
Con trỏ hàm có thể trả về không chỉ biến thông thường, mà nó còn có thể trả về phần tử của xâu. 
Nếu `a` là một xâu, thì `&a[i]` là con trỏ trỏ tới thành phần i của xâu a.
Khi hàm có tham số là một xâu, ta có thể viết hàm để trả về con trỏ trỏ tới một phần tử của xâu.
Ví dụ như chương trình [sau](day5_codes/demo_return_function_array.c) sẽ đọc xâu `arr[n]` và chỉ số i được yêu cầu, sử dụng hàm trả về phần tử có chỉ số i:
```c{.line-numbers}
#include <stdio.h>
int *arraySelectedReturn(int n, int arr[], int *index)
{
    if(*index < n)
    {
        return &arr[*index];
    }
    else
    {
        return NULL;
    }
}
int main(void)
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int index;
    printf("Enter the index of the element to return: ");
    scanf("%d", &index);
    int *result = arraySelectedReturn(n, arr, &index);
    if(result != NULL)
    {
        printf("The element at index %d is: %d\n", index, *result);
    }
    else
    {
        printf("Index out of bounds.\n");
    }
}
```
Kết quả:
* Lần 1:
```   
Enter the size of the array: 5
Enter the elements of the array:
10 20 30 40 70
Enter the index of the element to return: 2
The element at index 2 is: 30
```
* Lần 2:
```
Enter the size of the array: 5
Enter the elements of the array:
10 20 30 40 70
Enter the index of the element to return: 2
The element at index 2 is: 30
```
## Bài tập ví dụ kèm lời giải tham khảo
Đề bài: Điền nội dung hàm để hoàn thành chương trình sau:
```c
#include <stdio.h>
int *find_largest(int a[], int n) // Function to find the largest element in an array
{

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
```
Lời giải tham khảo: [Ở đây](day5_codes/exercise1.c)