/*

Friends
(把base class private member, 讓 衍伸class 的body 可以使用)


In C++, friend classes provide an alternative inheritance mechanism to derived classes.
=> Friend class 提供一個繼承的替代方案

The main difference between classical inheritance and friend inheritance is that a
friend class can access private members of the base class,
which isn't the case for classical inheritance.
=> 與傳統繼承不同的地方是, friend 繼承是可以讓這個friend class 存取base class private 的成員, 這個在傳統的繼承是作不到的
(讓base class 的 private 成員, 在derived class 的body 中使用, 不是透過object.xxx 來用)

In classical inheritance, a derived class can only access public and protected members of the base class.
傳統繼承,的延伸class 只可以存取base class的 public, protected 成員





Instructions
In this exercise you will experiment with friend classes. In the notebook below, implement the following steps:

    Declare a class Rectangle.
    Define a class Square.
    Add class Rectangle as a friend of the class Square.
    Add a private attribute side to class Square.
    Create a public constructor in class Square that initializes the side attribute.
    Add private members width and height to class Rectangle.
    Add a Rectangle() constructor that takes a Square as an argument.
    Add an Area() function to class Rectangle.
*/
// Example solution for Rectangle and Square friend classes
#include <assert.h>
#include <iostream>
// Declare class Rectangle
// 注意, 這邊只要你 Declare, 不是要你create 全部
// 先宣告, 不下面 square 不會過
class Rectangle;


// Define class Square as friend of Rectangle
// 這邊是 define 就是要全部了
class Square{

public:
// Add public constructor to Square, initialize side
    Square(int s): side(s){}
    void test(){
        std::cout << side << std::endl;
    }
private:
    // Add friend class Rectangle
    // 只有在這邊說, 我要分享我的private 成員給我的好朋友 Rectangle
    // 它才有可能使用到我的side
    friend class Rectangle;
    // Add private attribute side
    int side;
};


// 這裡才真的定義 Rectangle class

// Define class Rectangle
class Rectangle{
public:

    // 這邊能直接用 s.side, 是因為上面有把 Retangle class 加進去 Square 的 friend class
    // 因為原本 side 是 square 的 private member, 只能在 Square body 中使用
    // 讓Rectangle 成為friend 後, 才能在Rectangle 的body 中使用
    Rectangle(Square& s): width(s.side),height(s.side){};
    // Add public function to Rectangle: Area()
    float Area() const{
        return width*height;
    }
private:
    // Add private attributes width, height;
    float width;
    float height;
// Define a Rectangle constructor that takes a Square

// Define Area() to compute area of Rectangle
};
// Update main() to pass the tests
int main()
{
    Square square(4);
    square.test();
    //std::cout << square.side << std::endl;//會報錯, 因為是 private
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
    std::cout << rectangle.Area() <<  std::endl;
}
