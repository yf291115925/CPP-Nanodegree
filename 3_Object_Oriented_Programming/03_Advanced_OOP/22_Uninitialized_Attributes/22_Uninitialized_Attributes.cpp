#include <assert.h>
#include <exception>
#include <iostream>

class Date {
public:
  // TODO: Define a constructor to initialize the member variables
  Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}
  void SetDate(int day, int month, int year);
  int Day() const { return day_; }
  int Month() const { return month_; }
  int Year() const { return year_; }

private:
  int day_;
  int month_;
  int year_;
};

void Date::SetDate(int day, int month, int year) {
  int day_numbers[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (year < 1 || day < 1 || month < 1 || month > 12 ||
      day > day_numbers[month - 1])
    throw std::domain_error("Invalid date!");

  Date::day_ = day;
  Date::month_ = month;
  Date::year_ = year;
}

int main() {
  Date date(12, 12, 2010);
  assert(date.Month() == 12);
  Date date2(43, 12, 2010);
  assert(date2.Day() != 43);
  return 0;
}