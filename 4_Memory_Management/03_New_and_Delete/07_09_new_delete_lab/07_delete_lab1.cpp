/*
New and Delete LAB
LAB 1
Objectives 1
We are going to use new and delete operators for memory management.
In this example we are going to try to allocate piece of memory for storage
of integer number 10. After that, we are going to use delete operator for
freeing occupied memory before program exits. This is done to prevent memory leakage.
With this approach, where we always track our memory with pairing every new with delete
we are assuring our memory is always released after usage.

Steps 1
    Declare basic include -> iostream
    Declare main function
    Use pointer syntax to declare integer pointer
    use new operator to allocate memory space for one integer number via new syntax
    Assign that operation to declared pointer
    Print its address and value to make sure that we have right information
    Release occupied space before exiting
*/


#include <iostream>

int main(){
    int *intptr;
    intptr = new int(999);

    std::cout << "addr:"<< intptr << ",value:" << *intptr << std::endl;

    delete intptr;
}
