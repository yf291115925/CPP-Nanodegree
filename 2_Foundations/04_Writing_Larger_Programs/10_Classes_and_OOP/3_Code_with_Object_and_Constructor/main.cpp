/*
Adding a Constructor
The best way to fix this is to add a constructor to the Car class.
The constructor allows you to instantiate new objects with the data that you want.
In the next code cell, we have added a constructor for Car that allows the number and color to be passed in.
This means that each Car object can be created with those variables.
*/

#include <iostream>
#include <string>
using std::string;
using std::cout;

class Car {
  public:
    void PrintCarData()
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    void IncrementDistance()
    {
        distance++;
    }

    // Adding a constructor here:
    Car(string c, int n)
    {
        // Setting the class attributes with
        // The values passed into the constructor.
        color = c;
        number = n;
    }

    string color;
    int distance = 0;
    int number;
};

int main()
{
    // Create class instances for each car.
    Car car_1 = Car("green", 1);
    Car car_2 = Car("red", 2);
    Car car_3 = Car("blue", 3);

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();
}

/*
This is now beginning to look better. 
The main is more organized than when we first started, 
although there is a little more code overall to accomodate the class definition. 
At this point, you might want to separate your class definition into it's own .h and .cpp files. 
We'll do that in the next concept!
*/
