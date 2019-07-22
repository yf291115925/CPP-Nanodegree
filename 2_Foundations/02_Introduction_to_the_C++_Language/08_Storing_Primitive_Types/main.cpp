/* Primitive types
C++ has several "primitive" variable types, which are things like ints (integers), strings, floats, and others. These should be similar to variable types in other programming languages you have used.
*/

#include <iostream>
#include <string>
using std::cout;

int main() {
    // Declaring and initializing an int variable.
    int a = 9;
    
    // Declaring a string variable without initializing right away.
    std::string b;
    
    // Initializing the string b.
    b = "Here is a string";
    
    cout << a << "\n";
    cout << b << "\n";
}
