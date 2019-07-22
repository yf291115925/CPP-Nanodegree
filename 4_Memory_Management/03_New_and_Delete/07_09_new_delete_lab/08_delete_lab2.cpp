/*
LAB 2
Objectives 2
We are going to use new and delete operators for memory management.
In this example we are going to try to allocate block of memory for storage of array of
integer numbers.Upon completion we are going to use for loop for storage of input data
to newly created array. After that, we are going to use delete array operator for freeing
occupied memory before program exits.

Steps 2
    Declare basic include -> iostream
    Declare main function
    Use pointer syntax to declare integer array pointer
    use new operator to allocate memory block for integer array
    Assign that operation to declared pointer
    Create for loop and use it to input new values from cin stream
    Print every memory address and value in array 1. Release occupied space before exiting
*/

#include <iostream>

int main(){
    int *ptr;
    ptr = new int[4];
    for (int i = 0; i < 4 ; i++){
        std::cin >> ptr[i];
    }


    for (int i = 0; i < 4 ; i++){
        std::cout<<"Number "<<ptr[i] << " is stored on " << (ptr + i) << " address."<<std::endl;
    }

    delete [] ptr;

}
