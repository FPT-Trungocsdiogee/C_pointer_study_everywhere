#include <stdio.h>
void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / 3600;
    *min = (total_sec % 3600) / 60;
    *sec = total_sec % 60;
}
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