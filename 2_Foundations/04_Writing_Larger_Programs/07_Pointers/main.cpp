/*
Accessing a Memory Address
Each variable in a program stores its contents in the computer's memory, and each chunk of the memory has an address number.
For a given variable, the memory address can be accessed using an ampersand in front of the variable.
To see an example of this, execute the following code which displays the hexadecimal memory addresses of the variables i and j:
*/

#include <iostream>
using std::cout;

int Accessing_Memory_Address() {
    cout<< __func__ <<"\n";
    int i = 5;
    int j = 6;

    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    cout << "The address of j is: " << &j << "\n";
}


/*
At this point, you might be wondering why the same symbol & can be used to both access memory addresses and,
as you've seen before, pass references into a function. This is a great thing to wonder about.
The overloading of the ampersand symbol & and the * symbol probably contribute to much of the confusion around pointers.

    The symbols & and * have a different meaning, depending on which side of an equation they appear.

This is extremely important to remember. For the & symbol, if it appears on the left side of an equation
(e.g. when declaring a variable), it means that the variable is declared as a reference.
If the & appears on the right side of an equation, or before a previously defined variable, 
it is used to return a memory address, as in the example above.


Try using the cell above to create new variables and print out their addresses!

*/


void Storing_Memory_Address_int(){
    cout<< __func__ <<"\n";

    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;

    // Print the memory addresses of i and j 
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
    cout << "The address of variable pointer_to_i is: " << &pointer_to_i << "\n";
    //Getting an Object Back from a Pointer Address : de-reference
    cout << "The value of variable pointer_to_i is: " << *pointer_to_i << "\n";
}

void change_value_by_pointer(){
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;

    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";

    // The value of i is changed.
    i = 7;
    cout << "The new value of the variable i is                     : " << i << "\n";
    cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
}


int main(){
    Accessing_Memory_Address();
    Storing_Memory_Address_int();
    change_value_by_pointer();
}
