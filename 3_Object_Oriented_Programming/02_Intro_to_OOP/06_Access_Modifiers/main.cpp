#include <iostream>

class Date {
    private:
        int day;
        int month;
        int year;

    public:
        void SetDate(int day, int month, int year);
        int GetDay();
        int GetMonth();
        int GetYear();
};

void Date::SetDate(int day, int month, int year)
{
    int day_numbers[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year % 4 == 0 && year % 100 != 0 || year% 400 == 0)
        day_numbers[1]++;

    if(year < 1 || day < 1 || month < 1 || month > 12 || day > day_numbers[month - 1])
        throw std::domain_error("Invalid date!");

    Date::day = day;
    Date::month = month;
    Date::year = year;
}

int Date::GetDay()
{
    return day;
}

int Date::GetMonth()
{
    return month;
}

int Date::GetYear()
{
    return Date::year;
}

int main()
{
   Date date;
   date.SetDate(29, 2, 2019);
   std::cout << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear()  << "\n";
}
