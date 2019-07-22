#include <iostream>

class Date {
    // Declare member variables
    public:
        int day;
        int month;
        int year;


        //In the class definition, we've also added the line public:, which is an "access modifier".

    //private
    public:
        // Declare member setter function
        void SetDate(int day, int month, int year);
};

// Define the SetDate() function

// First off is Date::, which is called the "namespace." Namespaces specify ownership.
//So this function, SetDate(), will be defined as part of the newly created class Date.

void Date::SetDate(int day, int month, int year)
{
    int day_numbers[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // TODO: Your code goes here to check if input year is a leap year
    // and if it is, give February 29 days
    /*
    https://en.wikipedia.org/wiki/Leap_year
    if (year is not divisible by 4) then (it is a common year)
    else if (year is not divisible by 100) then (it is a leap year)
    else if (year is not divisible by 400) then (it is a common year)
    else (it is a leap year)

    */
    if (year%4!=0){
        // common year
    }else if (year % 100 != 0){
        //leap year
        day_numbers[1]=29;
    }else if (year % 400 != 0){
        // common year
    }else{
        // leap year
        day_numbers[1]=29;
    }

    // Check for leap year
    //if(year % 4 == 0 && year % 100 != 0 || year% 400 == 0)
    //    day_numbers[1]++;


    // Validate inputs
    if(year < 1 || day < 1 || month < 1 || month > 12 || day > day_numbers[month - 1])
        throw std::domain_error("Invalid date!");

    // Set date
    // Date is the owner ship or namespace.
    Date::day = day;
    Date::month = month;
    Date::year = year;
}

// Test in main
int main()
{
   Date date;
   date.SetDate(29, 2, 2020);
   std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}
