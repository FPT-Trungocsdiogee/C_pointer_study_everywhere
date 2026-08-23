# Pointer notes - day 1

### 1. Giới thiệu về C pointer:

Pointer - con trỏ - là một tính năng quan trọng và thường khó hiểu nhất trong C. Nó được dùng trong rất nhiều ứng dung, đặc biệt là nhúng.

Pointer gồm 2 loai: Con trỏ biến, con trỏ hàm

### 2\. Con trỏ biến

#### 2.1. Giới thiệu

Trong máy tính hiện đại, bộ nhớ được chia thành nhiều bytes, với mỗi byte chứa 1 thông tin độ dài 8 bits:



|0|1|0|1|0|0|1|1|
|-|-|-|-|-|-|-|-|



&#x20;Ở bảng trên là 1 byte thông tin

1 byte luôn có 1 địa chỉ riêng để phân biệt nó với các byte khác trong bộ nhớ. Nếu bộ nhớ có n byte địa chỉ, ta có thể tưởng tượng từng địa chỉ như bảng dưới:

|Địa chỉ|Nội dung|
|-|-|
|0|01010100|
|1|00110011|
|...||
|n-1|00110011|



Một chương trình có thể thực thi được gồm mã và dữ liệu(biến). Mỗi biến trong chương trình sẽ chiếm 1 hoặc nhiều hơn 1 byte trong bộ nhớ.

Địa chỉ của byte đầu tiên được coi là địa chỉ của biến.



Mặc dù các địa chỉ của byte được biểu diễn bằng các số, khoảng giá trị của chúng có thể khác so với số nguyên, nên việc chứa chúng trong các biến số nguyên thông thường là không cần thiết. 

Nhưng chúng ta có thể chứa chúng trong biến đặc biệt: **Biến con trỏ**



Khi chúng ta chứa địa chỉ của biến i trong biến con trỏ p, ta nói rằng p "trỏ tới" i. 



Nói cách khác, con trỏ chính là địa chỉ của biến. Biến con trỏ là biến có thể chứa địa chỉ. 



