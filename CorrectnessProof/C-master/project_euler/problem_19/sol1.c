
#include <stdio.h>


char get_month_days(short month)
{
    if (month == 1) 
        return 28;
    else if (month <= 6) 
    {
        if (month & 0x01)
            return 30;
        else
            return 31;
    }

    

    if (month & 0x01)
        return 31;

    return 30;
}


char is_leap_year(short year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;

    return 0;
}

#ifdef DEBUG

const char *day_string(int day)
{
    switch (day)
    {
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    default:
        return "Shouldn't see this!";
    }
}
#endif


int main(int argc, char **argv)
{
    int count_sundays = 0;
    const short start_year = 1901;
    const short end_year = 2000;

    
    char start_day = 2;

    for (int year = start_year; year <= end_year; year++)
    {
        char is_leap = is_leap_year(year);
        for (char month = 0; month < 12; month++)
        {
            
            if (year == end_year && month == 11)
                continue;

            int days = get_month_days(month);

            if (is_leap && month == 1) 
                days++;

#ifdef DEBUG
            if (year == end_year)
            {
                printf("Year: %d\t Month: %d\t Days: %d\t First of day: %s\n",
                       year, month, days, day_string(start_day));
            }
#endif

            
            start_day = ((days % 7) + start_day) % 7;

            
            if (start_day == 0)
                count_sundays++;
        }
    }

    printf(
        "Total number of Sundays that happened on the 1st of a month in the "
        "last century: %d\n",
        count_sundays);

    return 0;
}
