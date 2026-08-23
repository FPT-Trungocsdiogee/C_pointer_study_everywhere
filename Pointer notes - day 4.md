# Pointer notes - day 4
Những ngày qua, chúng ta đã tìm hiểu về khái niệm con trỏ, cách khai báo con trỏ trong C và những lưu ý khi khai báo. Khi đó, một câu hỏi khác mà chúng ta có thể nghĩ ra, rằng: "Con trỏ sẽ được ứng dụng như thế nào khi chúng ta học C?". Từ ngày hôm nay, chúng ta sẽ trả lời câu hỏi đó, cùng tìm hiểu về cách dùng con trỏ trong các ứng dụng cụ thể trong lập trình C.

## 1. Dùng con trỏ làm đầu vào của hàm 
Ta thường truyền đối số (Argument) vào hàm bằng cách truyền giá trị trực tiếp vào hàm(Pass by value). Cách này, nói đơn giản, mỗi đối số được truyền vào sẽ **cung cấp bản sao giá trị** cho một tham số tương ứng, và hàm sẽ thực hiện tính toán dựa trên những tham số đó. Chính vì việc cung cấp bản sao đó, mọi thay đổi của tham số không làm thay đổi đối số ban đầu. 
Tuy nhiên, một số bài toán sẽ có yêu cầu về việc viết hàm để thay đổi biến bên ngoài hàm, ví dụ như bài toán đảo giá trị của hai biến như đoạn code dưới đây:
```c{.line-numbers}
#include <stdio.h>
void valueSwitch(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main(void)
{
    int x = 5, y = 10;
    printf("Before switch: x = %d, y = %d\n", x, y);
    
    valueSwitch(x, y);
    printf("After value switch: x = %d, y = %d\n", x, y);

    return 0;
}
```
Ở đây,hàm `valueSwitch` là hàm thực hiện phép đổi biến, mà phương pháp truyền Pass by value được sử dụng. 
Kết quả như sau:
```
Before switch: x = 5, y = 10
After value switch: x = 5, y = 10
```
Từ kết quả trên, ta thấy sau khi đổi biến, giá trị của x và y không đổi. Như vậy, Pass by value không phù hợp để giải bài toán này. Khi đó ta cần cách truyền đối số khác phù hợp với yêu cầu của bài toán đổi biến.
Con trỏ có thể đưa ra cho chúng ta lời giải khác: Thay vì truyền biến x là đối số của hàm, ta sẽ truyền đối số **&x - con trỏ của x**. Khi đó ta sẽ chuyển cách khai báo tham số p trong hàm từ biến thường thành biến con trỏ. Khi hàm được gọi, giá trị của p lúc đó là &x -  địa chỉ của x. Khi đó, ta dùng *p để truy cập vào giá trị của x, thông qua con trỏ p. Mỗi lần *p xuất hiện trong thân hàm sẽ là một lần biến x được truy cập gián tiếp(**indirect reference**). Qua đó, hàm có thể truy cập và thay đổi giá trị cùng một lúc. 
Để có thể thấy được tác dụng của cách này, ta có thể sửa lại chương trình trên như sau:
```c{.line-numbers}
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
```
Kết quả chạy chương trình trên như sau:
``` 
Before switch: x = 5, y = 10
After value switch: x = 5, y = 10
After reference switch: x = 10, y = 5
```
Kết quả này cho ta thấy được hiệu quả của phương pháp con trỏ đã nói ở trên. Nó được gọi là **Pass by reference**. Nó sẽ là phương pháp được sử dụng nhiều trong việc lập trình C nói chung và C embedded nói riêng.
### Có thể bạn chưa biết
Việc sử dụng phương pháp Pass by reference không hoàn toàn là phương pháp mới. Chúng ta luôn dùng nó khi gọi hàm `scanf`. 
Ta có thể xét ví dụ sau:
```
scanf("Random string: %d, %b, %x", &var1, &var2, &var3);
```
Ở đó dấu `&` được đặt ở trước tên từng biến `var1, var2, var3` để hàm `scanf` được cung cấp địa chỉ(hay con trỏ) của 3 biến trên. Nếu không có, hàm sẽ được cung cấp bởi từng value (giá trị) của từng biến.
Mặc dù hàm này yêu cầu đối số là biến con trỏ, nhưng điều này sẽ khiến bạn bất ngờ: Không phải lúc nào dấu `&` được đứng trước mọi biến. 
Ví dụ dưới đây làm bạn phải bất ngờ:
```c{.line-numbers}
#include <stdio.h>
int main(void)
{
    int i, *p;
    p = &i;

    printf("Enter an integer: ");
    scanf("%d", p); //Using pointer to read input
    printf("You entered: %d\n", i);

    return 0;
}
```
Yêu cầu bài toán rất đơn giản: Nhập số nào in số đó
Kết quả khi chạy chương trình dùng đoạn mã này:
```
Enter an integer: 15
You entered: 15
```
Kết quả cho ta thấy: Chương trình vẫn hoạt động đúng yêu cầu bài toán đưa ra. Vậy tại sao có hiện tượng này nhỉ?
Câu trả lời nằm ở dòng số 8: Khi ta đã khai báo `p = &i;`, p sẽ chứa địa chỉ của i, scanf sẽ đọc số nguyên và lưu vào biến i như bình thường.
### Lưu ý
* Cách viết sau là không chính xác:
```
scanf('%d', &p);
```
Khi đó hàm sẽ lưu số nguyên đã đọc vào biến p, thay vì biến i. Nó có thể dẫn đến việc chương trình bị sai. Điều này có thể thực hiện bằng cách bổ sung câu lệnh vào chương trình ví dụ. Khi đó kết quả trả về như sau. Chúng cho ta thấy rằng không nên viết như vậy vì có thể tạo ra undefined behavior.
```    
Lần 1:      
Enter an integer: 15
You entered: 0

Lần 2:
Enter an integer: 20
You entered: 0

```
* Không nên viết như chương trình sau:
```
#include <stdio.h>

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

    referenceSwitch(x, y); //Reference passing - wrong
    printf("After reference switch: x = %d, y = %d\n", x, y);
    return 0;
}
```
Kết quả:
```
PS D:\C_study\C_notes\C_pointer_notes\day4_codes> gcc .\demo_wrong_argument.c -o demo_wrong_argument.exe
.\demo_wrong_argument.c: In function 'main':                                                                                                                                     
.\demo_wrong_argument.c:14:21: error: passing argument 1 of 'referenceSwitch' makes pointer from integer without a cast [-Wint-conversion]                                       
   14 |     referenceSwitch(x, y); //Reference passing                                                                                                                           
      |                     ^                                                                                                                                                    
      |                     |                                                                                                                                                    
      |                     int                                                                                                                                                  
.\demo_wrong_argument.c:3:27: note: expected 'int *' but argument is of type 'int'                                                                                               
    3 | void referenceSwitch(int *a, int *b) //Switching function using reference passing                                                                                        
      |                      ~~~~~^                                                                                                                                              
.\demo_wrong_argument.c:14:24: error: passing argument 2 of 'referenceSwitch' makes pointer from integer without a cast [-Wint-conversion]                                       
   14 |     referenceSwitch(x, y); //Reference passing                                                                                                                           
      |                        ^                                                                                                                                                 
      |                        |                                                                                                                                                 
      |                        int                                                                                                                                               
.\demo_wrong_argument.c:3:35: note: expected 'int *' but argument is of type 'int'                                                                                               
    3 | void referenceSwitch(int *a, int *b) //Switching function using reference passing                                                                                        
      |                              ~~~~~^                                                                                                                                      

```
Ở dòng 14 của chương trình, ta có thể thấy hai đối số không được truyền vào đúng cách.
Vì hàm yêu cầu hai đối số đều là biến con trỏ, trong khi giá trị của biến đang được truyền vào. Thay vì nó sẽ sửa giá trị của biến x và y (như một số người nghĩ), nó sẽ sửa địa chỉ của ô nhớ có địa chỉ là giá trị của x và y.
Đối với hàm tự khai báo, nó có thể báo lỗi như trên. Nhưng với hàm `scanf`, việc truyền con trỏ không thành công thường không được báo lỗi khi biên dịch.
## 2. Sử dụng `const` để bảo vệ hằng số khi truyền biến con trỏ vào hàm
Trong một số trường hợp, hằng số cũng được dùng để truyền vào hàm số. Nhưng tại sao phương pháp Pass by reference lại được ưa chuộng hơn để thực hiện việc này? 
Câu trả lời: Phương pháp Pass by value mất nhiều thời gian và không gian lưu trữ nếu hằng số cần nhiều không gian bộ nhớ để lưu trữ một giá trị lớn.
Ta có thể dùng từ khóa `const` để khai báo một hằng số mà con trỏ của nó được truyền vào hàm. Nó được đặt trước kiểu dữ liệu của tham số, giống như khai báo biến hằng. Ví dụ như sau:
```c
void f(const int *p)
{
    *p = 0 //Sai
}
```
Việc thay đổi tham số hằng (lúc khai báo có sử dụng từ khóa này) có thể được tìm thấy bởi trình biên dịch. 
