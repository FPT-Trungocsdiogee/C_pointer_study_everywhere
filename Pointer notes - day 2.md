# Pointer notes - day 2

### 1. Cách khai báo con trỏ biến trong C:
Về cách khai báo biến con trỏ, nó tương tự như việc khai báo biến thông thường, nhưng phải có dấu `*` ở giữa tên kiểu dữ liệu và tên biến

Ta có thể viết như sau:

* `int *p;` (Được dùng nhiều nhất, vì nó có thể làm rõ dấu * cũng là 1 phần khai báo biến ( theo ChatGPT :) ) )
* `int* p;`
* `int     *     p;`

Ta có thể viết như vậy vì khoảng trắng không có ý nghĩa cú pháp.

Dù nó được viết như thế nào, chúng đều cho ta biết được rằng: `p` là một biến con trỏ, nó có thể trỏ tới biến có kiểu dữ liệu là `int`.

Hơn nữa, chúng có thể được khai báo trong cùng 1 dòng, cùng với các biến khác:

`int i, j, a[10], b[20], *p, *q`

#### 1.1. Lưu ý

* Xét câu lệnh sau:

`int* p, q;`

Đọc xong, chắc nhiều người nghĩ rằng cả `p` và `q` đều là hai biến con trỏ. Thực tế là chỉ `p` là biến con trỏ vì dấu `*` gắn với biến q.

Vậy có cách nào để khai báo cả 2 biến này là biến con trỏ không?
Câu trả lời là: Bổ sung thêm dấu `*` ở trước mỗi biến:

`int *p, *q;`

* Mỗi biến con trỏ phải được trỏ tới các biến thuộc duy nhất 1 kiểu dữ liệu cụ thể. Ví dụ như sau:
```
int *p;  // Trỏ tới số nguyên
double *q; // Trỏ tới số thập phân
char *r; // Trỏ tới ký tự
```

### 2. Phép lấy địa chỉ của con trỏ - Address Operator

Kí hiệu phép lấy địa chỉ: `&`

Mục đích: Phép này được dùng để truy cập giá trị là địa chỉ của biến. 

Xét đoạn chương trình ví dụ:
```
#include <stdio.h>

int main()
{
    int i = 15, *p; //Khởi tạo biến i và biến con trỏ p
    p = &i; //Gán địa chỉ của biến i vào p
    printf("%x, %x", p, i);

    return 0;
}
```
Kết quả là những chuỗi hexa như sau:
```
Lần 1: e3c8add4, f
Lần 2: 5f41fc94, f
Lần 3: 294aa6a4, f
...
```
Ta có thể nhìn thấy giữa mỗi lần chạy thì kết quả của p và phép tính &i giống nhau, nhưng khi so giữa các lần chạy thì ngược lại. Sau mỗi lần chạy, một chuỗi kí tự hexa (4 bytes - 32 bits tùy máy tính, tùy IDE) được in ra, nhưng giá trị của i không đổi sau mỗi lần chạy.

Khi đó giá trị của p là giá trị của địa chỉ của biến i trong memory. 