#include <iostream>

//now our class looks like:
class Date {
  private:
    int day;
    int month;
    int year;
  public:
    void SetDate(int day,int month,int year);
    std::string GetDate();
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
    Date::year =year;
}

std::string Date::GetDate() 
{
  std::string result = std::to_string(Date::day) + "/" + std::to_string(Date::month) + "/" + std::to_string(Date::year);

  return result;
}

int main() 
{
    Date birth_date;
    birth_date.SetDate(20, 2, 2019);
    std::cout << birth_date.GetDate() << "\n";
}