/*
The syntax for a while loop looks very similar to the syntax for the if statement.
*/

#include <iostream>
using std::cout;

int main() 
{
    auto i = 0;

    while (i < 5) {
      cout << i << "\n";
      i++;
    }
}