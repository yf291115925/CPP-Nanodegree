/*

Composition
Composition is a closely related alternative to inheritance. Composition involves constructing ("composing")
classes from other classes, instead of inheriting traits from a parent class.

=>Composition 和 繼承是很相似
COmposition 是由其他的class 所組成, 而有別於從parent class 繼承來


A common way to distinguish "composition" from "inheritance" is to think about what an object can do,
rather than what it is. This is often expressed as "has a" versus "is a".


一個分辨要用 composition 或 inheritance 就是用 has a or is a 來解釋

    1. has a -> Composition
    2. is a -> Inheritance


From the standpoint of composition, a cat "has a" head and "has a" set of paws and "has a" tail.
=> 貓有頭, 貓has a 掌, has a 尾巴 ==> 用composition



From the standpoint of inheritance, a cat "is a" Aniamal.
=> 貓 is a Animal, 用 inheritance



There is no hard and fast rule about when to prefer composition over inheritance.

In general,
if a class needs only extend a small amount of functionality beyond what is already offered by another class,
it makes sense to inherit from that other class.
=>
    一般來說, 如果一個class 中, 只需要在base calss 上延伸少量的functionality, 且這些func 已經被其他的class 做了,
    延伸那個class




However, if a class needs to contain functionality from a
variety of otherwise unrelated classes, it makes sense to compose the class from those other classes.

=>
    然而, 如果一個class 需要做很多function 是從各種不相干的class 力面收集還的, 這
    就是直接從其他class compose (把A class object 當作input 傳進B , 藉此在B中可以取用 class A 的內容)

In this example, you'll practice working with composition in C++.
*/



/*

Instructions
In this exercise, you will start with a LineSegment class and create a Circle class.

Note that you will compose Circle from LineSegment, instead of inheriting Circle from LineSegment.
Specifically, the length attribute from LineSegment will become the circle's radius.


這個例子就是說明, Circle 中有一個 半徑, 這個半徑是 線段的一個變數, 因此用組合的 composition 就好
並不需要inheritance



    Create a class LineSegment.
    Declare an attribute length in class LineSegment.
    Define pi (3.14159) with a macro.
    Create a class Circle, composed of a LineSegment that represent's the circle's radius.
    Use this radius to calculate the area of the circle (area of a circle = \pi r^2πr2).
    Verify the behavior of Circle in main().
*/
#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
//static const float pi = 3.1415926;
#define PI 3.14159
// Define Line Class

class LineSegment{
public:
    // Define protected attribute length
    double get_len(){return length;}
    void set_len(double l){
        length = l;
    }
protected:
    double length;
};



// Define Circle subclass
class Circle{
    // Define public setRadius() and getArea()
public:
    //別忘了有扯的 memory 的construtor 要用這種表示法
    Circle(LineSegment& l):radius_(l){}

    void setRadius(LineSegment& r){
        radius_ = r;
    }

    double Area(){
        return PI*pow(Circle::radius_.get_len(),2);
    }

private:
    LineSegment& radius_;


};
// Test in main()
int main()
{
    LineSegment radius;
    radius.set_len(3);
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
    std::cout << circle.Area() << std::endl;

}
