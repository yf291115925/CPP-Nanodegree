/*
References

As mentioned previously, a reference is another name given to an existing variable.
On the left hand side of any variable declaration, the & operator can be used to declare a reference.
*/


#include <iostream>
using std::cout;

int main()
{
    int i = 1;

    // Declare a reference to i.
    int& j = i;

    //check address
    cout << "i address: " << &i <<",j address: "<< &j<<"\n";

    cout << "The value of j is: " << j << "\n";

    // Change the value of i.
    i = 5;
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is now: " << j << "\n";

    // Change the value of the reference.
    // Since reference is just another name for the variable,
    // th
    j = 7;
    cout << "The value of j is now: " << j << "\n";
    cout << "The value of i is changed to: " << i << "\n";
}
