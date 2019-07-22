/*
Multiple Inheritance
In this exercise, you'll get some practical experience with multiple inheritance.
If you have class Animal and another class Pet, then you can construct a class Dog,
which inherits from both of these base classes.
In doing this, you are able to incorporate attributes of multiple base classes.

Instructions
    Review class Dog, which inherits from both Animal and Pet.
    Declare a class Cat, with a member attribute color, that also inherits from both Animal and Pet.
    Instantiate an object of class Cat.
    Configure that object to pass the tests in main().

*/

/*


Exercise
In the code below, the Dog class inherits from both Animal and Pet.
Once you have examined the code below, add a Cat class that also inherits from Animal and Pet.

The Cat class should have the attribute string color.
Design the Cat class to pass the tests in the main() function.
*/




#include <iostream>
#include <string>
#include <assert.h>

class Animal {
public:
    double age;
};

class Pet {
public:
    std::string name;
};

// Dog derives from *both* Animal and Pet
class Dog : public Animal, public Pet {
public:
    std::string breed;
};


class Cat : public Animal, public Pet {
public:
    Cat(std::string n, double a,std::string c){
        color = c;
        name =n ;
        age = a;
    }
    std::string color;
    //繼承多個 base class 且用public 繼承過來, 所以都可以用
    void get_info(){
        std::cout << name << std::endl;
        std::cout << age << std::endl;
        std::cout << color << std::endl;

    }

};


int main()
{
    Cat cat("Max",10,"black");
    assert(cat.color == "black");
    assert(cat.age == 10);
    assert(cat.name == "Max");
    cat.get_info();
}
