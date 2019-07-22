/*
Function Order in a Single File
In the following code example, the functions are out of order, and the code will not compile. Try to fix this by rearranging the functions to be in the correct order.
*/


#include <iostream>
using std::cout;


void OuterFunction(int i)
{   
    //you have to define the InnerFunction befre call it.
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
