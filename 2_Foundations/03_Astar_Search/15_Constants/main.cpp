/* Constants

This example highlights how to use const to promise not to modify a variable, 
even though the variable can only be evaluated at run time.

The example also show how to use constexpr to guarantee that a variable can be evaluated at compile time.
*/

#include <iostream>
#include <vector>


//j can cowork with a non-const i, but k can't
void example1(){
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                          // "But I promise not to change it after it is initialized."

    constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."

    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";
}


void example2(){
    const int i = 2; // "I promise not to change this."
    i++;             // "I just broke my promise."

    //will get error
    //main.cpp: In function ‘void example2()’:
    //main.cpp:41:6: error: increment of read-only variable ‘i’
    //     i++;             // "I just broke my promise."
}

void example3(){

    constexpr int i = 2;  // "i can be evaluated at compile time."
    i++;                  // "But changing a constexpr variable triggers an error."


    //main.cpp: In function ‘void example3()’:
    //main.cpp:53:6: error: increment of read-only variable ‘i’
    //     i++;                  // "But changing a constexpr variable triggers an error."

}


void example4(){
    //The compiler will catch a constexpr variable that cannot be evaluated at compile time.
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    constexpr int j = i * 2;  // "j can only be evaluated at run time, because i will get the value in run time."
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."

}


/*
A common usage of const is to guard against accidentally changing a variable,
especially when it is passed-by-reference as a function argument.
*/

int sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i : v)
        sum += i;
    return sum;
}

/*
The major difference between const and constexpr, is that constexpr must be evaluated at compile time.
*/

int main()
{
    example1();
    //example2();
    //example3();
    //example4();
    std::vector<int> v {0, 1, 2, 3, 4};
    std::cout << sum(v) << "\n";
}
