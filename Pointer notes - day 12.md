# Pointer notes - day 12
### 1. Con trỏ và xâu có thể thay đổi độ dài
Con trỏ có thể trỏ tới các phần tử của một xâu có thể thay đổi độ dài. Một biến con trỏ bình thường có thể được dùng để trỏ tới một phần tử của một xâu VLA(Variable length array - xâu có thể thay đổi độ dài) 1 chiều:
```c
void f(int n)
{
    int a[n], *p;
    p = a;
    ...
}
```
Khi xâu VLA có nhiều hơn một chiều, kiểu dữ liệu của biến con trỏ sẽ phụ thuộc vào độ dài của từng chiều, ngoại trừ chiều đầu tiên. Xét đoạn ví dụ sau:
```c
void f(int m, int n)
{
    int a[m][n], (*p)[n];
    p = a;
    ...
}
```
Bởi vì kiểu dữ liệu của `p` phụ thuộc vào `n` - không phải là hằng số, ta nói kiểu dữ liệu của `p` là **kiểu dữ liệu có thể thay đổi**. Tuy nhiên, tính hợp lệ của phép gán `p=a` thường không được xác định bởi trình biên dịch. Ví dụ như đoạn code sau chỉ đúng khi m = n:
```c
void f(int m, int n)
{
    int a[m][n], (*p)[m];
    p = a;
    ...
}
```
Nếu m khác n, mọi phép tính sau đó liên quan đến p có thể gây ra lỗi không xác định.

Kiểu dữ liệu có thể thay đổi có thể vướng một số điều kiện cụ thể. Điều kiện quan trọng nhất là khai báo biến với kiểu dữ liệu này phải được thực hiện ở trong hàm. 

Phép tính với con trỏ cũng có thể hoạt động với xâu VLA. 
#### Lưu ý:
Tính năng này chỉ có trên phiên bản C99

### 2. Luyện tập về mối quan hệ giữa con trỏ và xâu.
Bài tập duy nhất: Viết hàm sau:

```c
double inner_product (const double *a, const double *b,
int n) ;
```
Hàm này, về cơ bản là tính tích vô hướng của hai vector `a` và `b` có n phần tử.

Lời giải tham khảo: [ở đây](day12_codes/exercise_pointer.c)

