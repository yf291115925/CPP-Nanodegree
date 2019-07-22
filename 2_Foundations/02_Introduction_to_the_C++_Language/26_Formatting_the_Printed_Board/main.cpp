
/*

In the previous exercises, you stored and printed the board as a vector<vector<int>>,
where only two states were used for each cell: 0 and 1. This is a great way to get started,
but as the program becomes more complicated, there will be more than two possible states for each cell.
Additionally, it would be nice to print the board in a way that clearly indicates open areas and obstacles,
just as the board is printed above.

To do this clearly in your code, you will learn about and use something called an enum.
An enum, short for enumerator, is a way to define a type in C++ with values that are restricted to a fixed range.
For an explanation and examples, see the notebook below.

*/


#include <iostream>
using std::cout;


/*
Enums
C++ allows you to define a custom type which has values limited to a specific range you list or "enumerate".
This custom type is called an "enum".

Suppose you were writing a program that stores information about each user's car, including the color.
You could define a Color enum in your program, with a fixed range of all the acceptable values:

We want to limited the possible colors.

    white
    black
    blue
    red

https://en.cppreference.com/w/cpp/language/enum

scoped enums
    => enum + class/structure + name {items}

unscoped enums (only remove the class/sturcture from scoped enums)
    => enum + name {items}

*/

void scoped_enum(){
    // Create the enum Color with fixed values.
    // scoped enum
    enum class Color {white,
                      black,
                      blue,
                      red};

    // Create a Color variable and set it to Color::blue.
    Color my_color;
    //assign
    my_color = Color::blue;

    // Test to see if my car is red.
    if (my_color == Color::red) {
        cout << "The color of my car is red!" << "\n";
    } else {
        cout << "The color of my car is not red." << "\n";
    }
}

void unscoped_enum(){

    enum Color {  white =0,
                  black,
                  blue,
                  red};

    Color my_color = blue;
    cout << my_color << "\n";
    // Test to see if my car is red.
    if (my_color == red) {
        cout << "The color of my car is red!" << "\n";
    } else {
        cout << "The color of my car is not red." << "\n";
    }
}

void enum_switch(){

    enum class keypad {up,down,left,right};

    keypad input;
    input = keypad::down;

    switch(input){
        case keypad::up:
            cout<<"up"<<"\n";
            break;
        case keypad::down:
            cout<<"down"<<"\n";
            break;
        case keypad::left:
            cout<<"left"<<"\n";
            break;
        case keypad::right:
            cout<<"right"<<"\n";
            break;
    }
}

int main()
{
    scoped_enum();
    unscoped_enum();
    enum_switch();
}
