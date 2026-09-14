# Pointer notes - day 11
Những ngày qua, chúng ta đã dành thời gian tìm hiểu và thực hành với con trỏ trỏ tới mảng 1 chiều. Vậy có cách nào kết hợp được con trỏ và mảng nhiều chiều không?
Câu trả lời là có, hôm nay ta sẽ tìm hiểu chính về cách kết hợp con trỏ và mảng hai chiều. Ta có thể áp dụng tương tự khi kết hợp nó với mảng 3 hay 4 hay nhiều chiều hơn.
### 1. Xử lí các phần tử của mảng hai chiều
C lưu trũ dữ liệu trong một mảng hai chiều theo thứ tự ưu tiên hàng. Nói cách khác, phần tử của hàng 0 sẽ đứng đầu mảng, theo sau là phần tử hàng 1, phần tử của hàng 2,... Chúng có thể được biểu diễn như sau:
|Hàng 0||||Hàng 1||||Hàng 2|||
|-|-|-|-|-|-|-|-|-|-|-|
|Phần tử 0|Phần tử 1|...|Phần tử $a_1$|Phần tử 0|Phần tử 1|...|Phần tử $a_2$|Phần tử 0|Phần tử 1|...|

Chúng ta có thể tận dụng layout này khi kết hợp nó và con trỏ. Nếu chúng ta sử dụng một con trỏ `p` trỏ tới phần tử đầu tiên (tức là phần tử 0 ở hàng 0), chúng ta có thể truy cập từng phần tử bằng cách tăng biến con trỏ `p`.
Xét một chương trình ví dụ khởi tạo một mảng hai chiều ngẫu nhiên như sau:
```c{.line-numbers}
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("Enter the number of rows and columns: ");
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];
    for(int *p = &arr[0][0]; p <= &arr[rows-1][cols-1]; p++)
    {
        *p = rand();
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
Ở dòng thứ 9-12, ta coi mảng hai chiều này được bố trí như bảng trên, ta có thể viết như trên để thay thế vòng lặp lồng nhau.
Khi đó, vòng lặp bắt đầu từ việc `p` trỏ tới `arr[0][0]`. Sau đó `p++` sẽ trỏ tới `arr[0][1], arr[0][2], ...`. Khi `p` trỏ tới `arr[0][cols - 1]` - phần tử cuối của hàng 0, `p++` sẽ trỏ tới `arr[1][0]`. Quy trình này lặp lại đến khi `p` trỏ tới phần tử cuối cùng của mảng.
### 2. Xử lí các hàng của mảng hai chiều
Ở chương trình trên, vòng lặp lồng `for` được sử dụng để in ma trận ra màn hình theo từng hàng. Vậy có cách nào để thực hiện việc đó, cũng như mọi xử lí hàng nói chung, mà dùng con trỏ không? 
Câu trả lời là có. Khi đó ta có thể viết theo hai cách sau:
* `p = &a[i][0]`
* `p = a[i]`

Vậy tại sao ta lại có thể viết được theo 2 cách trên, đặc biệt là cách thứ hai? Để giải thích cho câu hỏi này, ta nhắc lại về phép toán ở ngày hôm qua: Đối với mọi mảng `a`, phép toán a[i] tương đương với *(a+i). Nên `a[i][0]`tương đương với `*(a[i] + 0)`, tương đương với `*a[i]`. 
Để ví dụ cho cách viết ở trên, xét hàm in mảng hai chiều theo hàng như sau:
```c
void print_array(int rows, int cols, int arr[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int *p = arr[i]; p < arr[i] + cols; p++)
        {
            printf("%d ", *p);
        }
        printf("\n");
    }
}
```
Bởi `arr[i]` là con trỏ trỏ tới hàng `i` của mảng hai chiều `arr`, nên ta có thể truyền `a[i]` vào một hàm yêu cầu mảng một chiều. Nói cách khác, một hàm phù hợp với mảng một chiều cũng có thể xử lí dữ liệu từ một hàng của mảng hai chiều.
### 3. Xử lí các cột của mảng hai chiều
Việc xử lí theo cột của mảng hai chiều sẽ khó hơn, bởi vì mảng được lưu trữ theo từng hàng, không phải từng cột. Hàm dưới đây sẽ in ma trận chuyển vị của ma trận `arr` cho trước:
```c
void print_transpose(int rows, int cols, int arr[rows][cols])
{
    int (*p)[cols];
    for(int j = 0; j < cols; j++)
    {
        for(p = &arr[0]; p < &arr[rows]; p++)
        {
            printf("%d ", (*p)[j]);
        }
        printf("\n");
    }
}
```
Ở đây, `p` được khai báo là con trỏ trỏ tới một mảng số nguyên có độ dài `cols`. Các dấu ngoặc xung quanh `*p` ở `(*p)[cols]` là bắt buộc. Nếu không , `p` sẽ được hiểu là mảng gồm các con trỏ, không phải là con trỏ trỏ tới một mảng. `p++` đưa `p` trỏ tới phần tử đầu tiên của hàng tiếp theo. Ở biểu thức `(*p)[j]`, `*p` biểu thị một hàng của `arr`, nên biểu thức trên sẽ lựa chọn phần tử ở cột `j` của hàng đó. Các dấu ngoặc trong biểu thức trên là cần thiết, bởi vì nếu không có, trình biên dịch sẽ hiểu `*p[j]` là `*(p[j])`.


Để xem kết quả chạy chương trình của từng hàm trong mục 2 và 3, xem chương trình [ở đây](day11_codes/init_2d_array_2.c).
### 4. Sử dụng tên của mảng nhiều chiều như con trỏ
Chúng ta có thể sử dụng tên mảng như một con trỏ, không quan trọng mảng đó có bao nhiêu chiều. Tuy nhiên, có một số lưu ý cần phải chú ý. 
Ví dụ, xét một mảng hai chiều được khai báo như sau:
```c
int a[rows][cols];
```
Khi đó, `a` sẽ trỏ tới `a[0]`, không phải `a[0][0]`. C thường hiểu một mảng nhiều chiều là một mảng to gồm các phần tử mà mỗi phần tử là một mảng con một chiều. Khi sử dụng nó như một con trỏ, nó là biến con trỏ trỏ tới một mảng số nguyên có độ dài `cols`. Khi đó, ta có thể viết lại hàm `print_transpose` như sau:
```c
void print_transpose2(int rows, int cols, int arr[rows][cols])
{
    int (*p)[cols]; //Khai báo con trỏ p trỏ đến mảng 1 chiều có cols phần tử
    for(int j = 0; j < cols; j++)
    {
        for(p = arr; p < arr + rows; p++)
        {
            printf("%d ", (*(p))[j]);
        }
        printf("\n");
    }
}
```
Kết quả có thể xem [ở đây](day11_codes/init_2d_array_2.c).