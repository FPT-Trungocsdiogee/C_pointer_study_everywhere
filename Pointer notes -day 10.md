# Pointer notes - day 10
### 1. Sử dụng tên mảng làm con trỏ
Các phép toán số học với con trỏ là một cách xử lí liên quan đến mối quan hệ giữa mảng và con trỏ. Nhưng đây không phải là mối liên hệ duy nhất giữa chúng. 
Phần này sẽ nói về một mối liên hệ khác: **Tên của mảng có thể được dùng làm con trỏ trỏ tới phần tử đầu tiên của mảng.** Mối quan hệ này có thể làm đơn giản hóa phép toán số học với con trỏ và làm tăng tính đa năng của con trỏ và mảng. 
Xét một chương trình ví dụ như sau:
```c
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
```
Ở đoạn chương trình trên, ta có thể dùng `a` như con trỏ chỉ tới phần tử đầu tiên của mảng. Khi đó ta có thể gán giá trị cho `a[0]`.
Ngoài ra chúng ta có thể gán giá trị cho hai phần tử `a[1], a[5]` bằng hai con trỏ tương ứng `a+1, a+5`. Như vậy, để trỏ tới một phần tử `a[i]` nói chung thì ta có thể dùng con trỏ `a+i`. Khi đó `a+i` tương đương với `&a[i]` và `*(a+i)` tương đương với `a[i]`. Nói cách khác, sử dụng chỉ số của mảng được coi là một dạng khác của sử dụng phép toán con trỏ.
Xét một đoạn code nhỏ như sau:
```c
for(int i = 0; i<n; i++)
{
    sum += a[i];
}
``` 
Ta có thể viết lại theo cách đã nói ở [ngày 8](Pointer%20notes%20-%20day%208.md):
```c
for(int *p = &a[0]; p < &a[n]; p++)
{
    sum += *p;
}
```
Và ta có thể viết lại theo cách đã tìm hiểu trong hôm nay:
```c
for(int *p = a; p < (a + n); p++)
{
    sum += *p;
}
```
Để kiếm chứng kết quả khi sử dụng các cách đã nói ở trên, bạn có thể xem chương trình gồm 3 hàm cùng có chức năng tính tổng của một mảng số nguyên [ở đây](day10_codes/sum_in_many_methods.c)
#### Lưu ý
1. Mặc dù tên của mảng có thể dùng được như một biến con trỏ, nhưng nó không phải là một biến con trỏ. Khi đó, việc thay đổi giá trị tên mảng bằng một giá trị mới là không khả thi. Cố gắng thay đổi (bằng `a++, a--` hay `a=...`) sẽ gây ra lỗi không compile được.
Ví dụ:
```c
while(*a != 0)
{
    a++; //Sai cách
}
```
Nếu cần di chuyển qua các phần tử của mảng bằng phép tăng/giảm con trỏ, hãy sao chép địa chỉ đầu mảng vào một biến con trỏ rồi thay đổi biến con trỏ đó.
```c
int *p = a;
while(*p != 0)
{
    p++; //Đúng cách
}
```
Để kiểm chứng điều trên, xem đoạn code [ở đây](day10_codes/pointer_array_warning.c)

2. Ta có thể dùng thêm từ khóa `const` khi khai báo tham số đầu vào là mảng hằng số. 
Đối với biến bình thường, giá trị của nó được "copy" vào hàm và mọi thay đổi liên quan đến tham số tương ứng với biến không làm thay đổi biến đó. Tuy nhiên, một mảng được dùng làm tham số của hàm không được bảo vệ khỏi việc thay đổi giá trị của từng phần tử trong nó. 

3. Mặc dù việc khai báo tham số là một mảng và khai báo tham số là một con trỏ là giống nhau, điều này không đúng với biến. 
Xét khai báo sau:
```
int a[10];
```
Ở khai báo này, trình biên dịch sẽ cấp phát bộ nhớ cho 10 số nguyên.
Tuy nhiên, ở khai báo sau:
```
int *a;
```
Ở đó, trình biên dịch sẽ cấp phát bộ nhớ cho 1 biến con trỏ. Khi đó, nó không còn là mảng như trường hợp trên nữa. Việc cố gắng sử dụng nó như một mảng có thể gây ra lỗi lớn không mong muốn.

4. Ta có thể truyền một đoạn của mảng vào hàm yêu cầu mảng. 
Ví dụ như ta sẽ tìm giá trị lớn nhất của mảng b, từ phần tử số 5 đến phần tử số 14, ta có thể viết như sau:
```
find_largest(&b[5], 10);
```
### 2. Sử dụng con trỏ làm tên mảng
Ở phần trên, ta có thể sử dụng tên mảng làm con trỏ. Vậy ta có thể làm được điều ngược lại không? Câu trả lời là có.
Để kiểm chứng điều đó, chương trình tham khảo có thể xem [ở đây](day10_codes/array_name_pointer.c)
Ở chương trình này, trình biên dịch coi `p[i]` giống như `*(p+i)`. Đây là cú pháp hợp lệ của phép toán số học lên con trỏ.