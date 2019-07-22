/*

Instructions
    Add a new member variable to class Vehicle.
    Output that new member in main().
    Derive a new class from Vehicle, alongside Car and Bicycle.
    Instantiate an object of that new class.
    Print the object.

*/

#include <iostream>
#include <string>


class Vehicle {

  private:
      std::string model_name;
      int mileage = 0;
      int fuel_capacity=0;


  public:
    int wheels = 0;
    std::string color = "blue";
    std::string make  = "generic";

    void get_info() {
        std::cout << "This is a vehicle!, name: "<< model_name << "\n";
    }
    void set_name(std::string name){
        model_name = name;
    }

    void Print() const
    {
        std::cout << "This " << color << " " << make << " vehicle has " << wheels << " wheels!\n";
    }


};

class Car : public Vehicle {
public:
    bool is_cabriolet;//敞篷
};

class Truck : public Vehicle {
public:
    bool has_sleeping_cabin;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
};

class Scooter : public Vehicle {
public:
    bool electric = false;
};

int main() {
    Car c;
    c.is_cabriolet = true;
    c.set_name("tesla S");

    std::cout << c.is_cabriolet << "\n";
    c.get_info();



    Truck t;
    t.has_sleeping_cabin = false;
    std::cout << t.has_sleeping_cabin << "\n";
    t.set_name("Ford T");
    t.get_info();


    Scooter scooter;
    scooter.wheels = 2;
    scooter.Print();


};
