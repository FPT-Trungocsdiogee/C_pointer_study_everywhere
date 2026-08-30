#include <stdio.h>
void split_date(int day_of_year, int year, int *month, int *day)
{
    int month_days[12];
    month_days[0] = 31;
    month_days[1] = 28;
    month_days[2] = 31;
    month_days[3] = 30;
    month_days[4] = 31;
    month_days[5] = 30;
    month_days[6] = 31;
    month_days[7] = 31;
    month_days[8] = 30;
    month_days[9] = 31;
    month_days[10] = 30;
    month_days[11] = 31;

    if (year % 4 == 0)
    {
        month_days[1] = 29;
    }

    *month = 0;
    while(day_of_year > month_days[*month])
    {
        day_of_year -= month_days[*month];
        (*month)++;
    }
    *day = day_of_year;
}
int main(void)
{
    printf("Enter day of year and year: ");
    int day_of_year, year;
    scanf("%d %d", &day_of_year, &year);
    int month = 0, day = 0;
    split_date(day_of_year, year, &month, &day);
    printf("Date: %d/%d/%d\n", day, month + 1, year);
}