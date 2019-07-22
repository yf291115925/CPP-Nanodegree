#include <iostream>
#include <string>
using std::cout;
using std::string;

int MultiplyByTwo_passbyvalue(int i) {
    i = 2*i;
    return i;
}

int MultiplyByTwo_passreference(int &i) {
    i = 2*i;
    return i;
}

int MultiplyByTwo_passpointer(int *i) {
    *i = 2*(*i);
    return *i;
}


void DoubleString(string &value) {
    // Concatentate the string with a space and itself.
    value = value + " " + value;
}

int main() {
    //Passing Values
    int a = 5;
    cout << "The int a equals: " << a << "\n";
    int b = MultiplyByTwo_passbyvalue(a);
    cout << "The int b equals: " << b << "\n";
    cout << "The int a still equals: " << a << "\n";

    //Passing ref
    int c = 5;
    cout << "The int c equals: " << c << "\n";
    int d = MultiplyByTwo_passreference(c);
    cout << "The int d equals: " << d << "\n";
    cout << "The int c equals: " << c << "\n";
    //pass pointer in C code
    int e = 5;
    cout << "The int e equals: " << e << "\n";
    int f = MultiplyByTwo_passpointer(&e);
    cout << "The int f equals: " << f << "\n";
    cout << "The int e equals: " << e << "\n";


    //Passing ref
    string s = "Hello";
    cout << "The string s is: " << s << "\n";
    DoubleString(s);
    cout << "The string s is now: " << s << "\n";
}
