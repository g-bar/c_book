/* Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing. */

#include <stdio.h>

static char daytab[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, unsigned int month, unsigned int day, unsigned int *yearday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month == 0 || month > 12 || day > *(*(daytab + leap) + month))
        return 1; // Err

    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);

    *yearday = day;

    return 0; // Success
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (yearday - leap > 365)
        return 1;

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;

    return 0;
}