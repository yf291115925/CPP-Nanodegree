#include <iostream>
#include <string>
using std::string;
using std::cout;

// The Car class
class Car {
  public:
    // Method to print data.
    void PrintCarData()
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    // Method to increment the distance travelled.
    void IncrementDistance()
    {
        distance++;
    }

    // Class/object attributes
    string color;
    int distance = 0;
    int number;
};

int main()
{
    // Create class instances for each car.
    Car car_1, car_2, car_3;

    // Set each instance's color.
    car_1.color = "green";
    car_2.color = "red";
    car_3.color = "blue";

    // Set each instance's number.
    car_1.number = 1;
    car_2.number = 2;
    car_3.number = 3;

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();

}

/*
This looks ok, and you have reduced the number of variables in main, so you might see how this could be more organized going forward.
However, there is now a lot more code than you started with, and the main doesn't seem much more organzied.
The code above still sets the attributes for each car after the car has been created.
*/
