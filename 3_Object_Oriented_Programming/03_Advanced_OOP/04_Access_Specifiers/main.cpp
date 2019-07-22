
/*
Instructions
    Update the derived classes so that one has protected inheritance and one has private inheritance.
    Try to access a protected member from main(). Is it possible?
    Try to access a private member from main(). Is it possible?
    Try to access a member of the base class from within the derived class that has protected inheritance. Is it possible?
    Try to access a member of the base class from within the derived class that has private inheritance. Is it possible?


*/

// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;

};

class Bicycle : protected Vehicle {
public:
    bool kickstand = true;
    void set_wheel(int w){
        wheels = w;
    }
};



class Scooter : private Vehicle {
public:
    bool electric = false;
    void set_wheel(int w){
        wheels = w;
    }
};



int main()
{


    //Case1: protected, private 繼承後, 不能直接存取原本 public 的變數
    //我們可以利用以前方法, 在自己class 裡面做一個public 的get fun 來存取 此變數
    Car car;
    car.wheels=4;


    Bicycle bicycle;
    //bicycle.wheels=2;//因為用protected 繼承, wheels 在  bicycle中視為protected, 無法直接存
    bicycle.set_wheel(2);//pass
    Scooter scooter;
    //scooter.wheels=2;// wheels對 scooter 來說是private 的, 不能直接存取
    scooter.set_wheel(2);
};
