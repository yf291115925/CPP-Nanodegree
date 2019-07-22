/*
Exercise: Virtual Functions

Polymorphism is one of the crucial components of OOP within C++. In this lab,
you'll use virtual methods and see their role in class interfaces and in the process of inheritance.




Virtual methods are declared (and possibly defined) in a base class, and are meant
to be overridden by derived classes. This approach creates interfaces for your classes at the base level.

=> Virtual methods 專門被宣告在base class 裡面, 就是打算讓 derived class  個別去實做
=> 在base class 只是定義要做的界面
=> 如果沒加 const = 0 在最後, 你在base class 可實做可不實做, 如果加了 const = 0, 在base class 可以留下空白, 就只是個prototypes
=> 加了 const = 0 表示一定要有個dervied class 實做




Here, you'll start with a Shape class as the base class for geometrical 2D entities.
Geometrical shapes (closed curves) can be described by an area and the length of their perimeter.
area and perimeter_length should be methods of the base class interface.

You'll declare each of these as virtual functions with a const = 0 flag to identify them as prototypes in the base class like this:

    class Shape {
        public:
            Shape() {}
            virtual double Area() const = 0;
            virtual double PerimeterLength() const = 0;
    };
We said that in the base class, virtual methods can but do not have to be implemented.
If we delegate with instruction = 0 we are notifying compiler that this (base) class doesn’t
have virtual method implementation but every other derived class is required to implement this method.



要實做的 derived class 要用 下面的語法

virtual double Function() const override{

}




OBJECTIVES
    1.Create base class called Shape.
    2.Chose mutual characteristics of every shape in geometry.
    3.Divide it in individual logical responsibilities.
    4.Design methods for base class and make them pure virtual functions const = 0.
    5.Write the derived classes.
        Inherit parent Shape class.
        Write derived implementation of overridden base methods.
    6.Test in main()

*/


// include iostream for printing
#include <iostream>
#include <cmath>
// Define pi constant
#define PI 3.1415926


class Shape{
// Define Shape base class
// strictly base class because its interface is pure virtual methods
public:
    // Define public empty constructor
    Shape(){}
    // Define public virtual Area() and PerimeterLength()
    virtual double Area() const = 0;
    virtual double PerimeterLength() const = 0 ;
        //const = 0 specifier in interface is telling the compiler that this method must be implemented in one of the derived classes
        // For this class it is just part of the interface
};

class Rectangle : public Shape{
// Define Rectangle to inherit publicly from Shape

    // Declare private attributes width and height
private:
    double width = 0;
    double height = 0;
public:
    // Declare public constructor
    Rectangle(double w, double h) :width(w), height(h){}

    // Override virtual base class functions
    virtual double Area() const override{
        std::cout << "Rectangle Area:" << width * height << "\n";
        return width * height;
    }

    virtual double PerimeterLength() const override {
        std::cout << "Rectangle PerimeterLength:" <<2*(width + height)<< "\n";
        return 2*(width + height);
    }
        // Overriding methods
};

class Circle : public Shape{
// Define Circle to inherit publicly from Shape

    // Declare private attributes radius
private:
    double radius = 0;
public:
    Circle(double r): radius(r){}
    // Declare public constructor
    // Override virtual base class functions
    // 這些　virtual function 如果沒實做, main 中宣告 object 時就會報錯
    virtual double Area() const override{
        std::cout << "Circle Area:" <<PI*pow(radius,2)<< "\n";
        return  PI*pow(radius,2);
    }

    virtual double PerimeterLength() const override{
        std::cout << "Circle PerimeterLength:" <<2*PI*radius<< "\n";
        return 2*PI*radius;
    }
};

int main(){
    // Test in main()
    // Generic containter of Shapes (array) :
    Shape** shapes = new Shape*[2];
    shapes[0] = new Circle(12.31);
    shapes[1] = new Rectangle(10, 6);
    for (int i = 0;i < 2;i++) {
        std::cout << "Area: " << shapes[i]->Area()<< "\n";
        std::cout << "Perimeter: " << shapes[i]->PerimeterLength() << "\n";

        }
}







//
