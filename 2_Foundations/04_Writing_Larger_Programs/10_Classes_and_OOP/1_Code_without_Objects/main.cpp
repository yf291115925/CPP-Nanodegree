/*
Code without Objects
Suppose you were writing a program to model several cars.
In your program, you want to keep track of each car's color and the distance the car has traveled,
and you want to be able to increment this distance and print out the car's properties.

You could write something like the code below to accomplish this:
*/

#include <iostream>
#include <string>
using std::string;
using std::cout;

int main()
{
    // Variables to hold each car's color.
    string car_1_color = "green";
    string car_2_color = "red";
    string car_3_color = "blue";

    // Variables to hold each car's initial position.
    int car_1_distance = 0;
    int car_2_distance = 0;
    int car_3_distance = 0;

    // Increment car_1's position by 1.
    car_1_distance++;

    // Print out the position and color of each car.
    cout << "The distance that the " << car_1_color << " car 1 has traveled is: " << car_1_distance << "\n";
    cout << "The distance that the " << car_2_color << " car 2 has traveled is: " << car_2_distance << "\n";
    cout << "The distance that the " << car_3_color << " car 3 has traveled is: " << car_3_distance << "\n";

}

/*
This works for the few cars that are defined in the program,
but if you wanted the program to keep track of many cars this would be cumbersome.
You would need to create a new variables for every car, and the code would quickly become cluttered.
One way to fix this would be to define a Car class with those variables as attributes,
along with a few class methods to increment the distance traveled and print out car data.
*/
