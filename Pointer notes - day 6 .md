# Pointer notes - day 6
### 1. Luyện tập sử dụng con trỏ trong viết hàm 
Dưới đây là những bài tập luyện tập cách sử dụng con trỏ làm đầu vào của hàm
1. Viết hàm được khai báo như sau:
```c
void avg_sum(double a[], int n, double *avg, double *sum)
```
Trong đó `a[n]` là mảng số thực gồm n phần tử, `avg, sum` là con trỏ trỏ tới lần lượt biến trung bình cộng và tổng các số trong mảng a
Chương trình kiểm tra kết quả trả về trong `main(void)`:
```c
int main(void)
{
    double a[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double avg, sum;
    avg_sum(a, 5, &avg, &sum);
    printf("Average: %.2f\n", avg);
    printf("Sum: %.2f\n", sum);
    return 0;
} 
```
[Lời giải tham khảo](day6_codes/exercise_3.c)

2. Viết hàm được khai báo như sau:
```c
void split_time(long total_sec, int *hr, int *min, int *sec)
``` 
Trong đó `total_sec` là thời gian được viết dưới dạng số giây tính từ 0h00, `hr, min, sec` là con trỏ trỏ tới các biến lưu thời gian theo thứ tự giờ (0-23), phút(0-59), giây(0-59)
Chương trình kiểm tra kết quả trả về trong `main(void)`:
```c
int main(void)
{
    printf("Enter total seconds: ");
    long total_sec;
    scanf("%ld", &total_sec);
    int hr, min, sec;
    split_time(total_sec, &hr, &min, &sec);
    printf("Time: %d hours, %d minutes, %d seconds\n", hr, min, sec);
    return 0;
}
```
[Lời giải tham khảo](day6_codes/exercise_5.c)

3. Viết hàm được khai báo như sau:
```c
void find_two_largest(int a[], int n, int *largest, int *second_largest)
``` 
Trong đó mảng `a[n]` là mảng gồm n số nguyên bất kì, `largest, second_largest` chỉ hai con trỏ trỏ tới biến lưu số lớn nhất và số lớn thứ hai của mảng `a[n]`
Chương trình kiểm tra kết quả trả về trong `main(void)`:
```c
int main(void)
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int largest, second_largest;
    find_two_largest(a, n, &largest, &second_largest);
    printf("Largest: %d\n", largest);
    printf("Second Largest: %d\n", second_largest);
    return 0;
}
```
[Lời giải tham khảo](day6_codes/exercise_6.c)

4. Viết hàm được khai báo như sau:
```c
void split_date(int day_of_year, int year, int *month, int *day)
```
Trong đó `day_of_year` là một số nguyên từ 1-366, chỉ một ngày cụ thể trong năm `year`. `month, day` là hai con trỏ trỏ vào biến lưu tháng tương đương (1-12) và ngày trong tháng đó (1-31)
Chương trình kiểm tra kết quả trả về trong `main(void)`:
```c
int main(void)
{
    printf("Enter day of year and year: ");
    int day_of_year, year;
    scanf("%d %d", &day_of_year, &year);
    int month = 0, day = 0;
    split_date(day_of_year, year, &month, &day);
    printf("Date: %d/%d/%d\n", day, month + 1, year);
}
```
[Lời giải tham khảo](day6_codes/exercise_7.c)
Bài tập sau luyện cách sử dụng con trỏ như giá trị trả về (Return values) của hàm số:

5. Viết hàm được khai báo như sau:
```c
int *find_first_even(int a[], int n)
```
Hàm này nhận mảng a gồm n số nguyên làm tham số, trả về địa chỉ của số chẵn đầu tiên trong mảng
Chương trình kiểm tra kết quả trả về trong `main(void)`:
```c
int main(void)
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    printf("Enter the elements: ");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int *first_even = find_first_even(a, n);
    if (first_even != NULL)
    {
        printf("First even number: %d\n", *first_even);
    }
    else
    {
        printf("No even number found.\n");
    }
}
```
[Lời giải tham khảo](day6_codes/exercise8.c)

Đó là các bài tập có thể luyện tập về viết hàm sử dụng con trỏ làm tham số và giá trị trả về của hàm.