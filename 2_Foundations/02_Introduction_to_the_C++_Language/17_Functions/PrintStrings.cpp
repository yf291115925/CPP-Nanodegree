#include <iostream>
#include <string>
using std::cout;
using std::string;

// Write the PrintStrings function here.
void PrintStrings(string a, string b)
{
    cout << a << " " << b << "\n";
}


int main() 
{
    string s1 = "C++ is";
    string s2 = "super awesome.";
    
    // Uncomment the following line to call your function:
    PrintStrings(s1, s2);
}