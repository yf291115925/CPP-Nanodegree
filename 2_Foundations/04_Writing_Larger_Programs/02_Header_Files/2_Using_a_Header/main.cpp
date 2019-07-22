/*

Using a Header
One other way to solve the code problem above (without rearranging the functions) would have been to declare each function at the top of the file.
A function declaration is much like the first line of a function definition - it contains the return type,
function name, and input variable types. The details of the function definition are not needed for the declaration though.

To avoid a single file from becomming cluttered with declarations and definitions for every function,
it is customary to declare the functions in another file, called the header file.
In C++, the header file will have filetype .h, and the contents of the header file must be included at the top of the .cpp file.
See the following example for a refactoring of the code above into a header and a cpp file.
*/



// The contents of header_example.h are included in
// the corresponding .cpp file using quotes:

//find .h in the same directory as the .cpp file
#include "header_example.h"

#include <iostream>
using std::cout;

void OuterFunction(int i)
{
    InnerFunction(i);
}

void InnerFunction(int i)
{
    cout << "The value of the integer is: " << i << "\n";
}

int main()
{
    int a = 5;
    OuterFunction(a);
}
