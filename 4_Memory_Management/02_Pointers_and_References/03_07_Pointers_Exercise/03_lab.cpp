/*
Lab 3
Objectives 3
In this example we are going to try to create dynamic array for integers.
With this we can get primitive overview of how some of the popular container
libraries in C++ work, such as : vector, queqe, stack etc. We know that dynamic
declaration of array was initially supported in C++, but we don't have option to do
resize or similar operation once array has been declared. Via pointers and access
to memory it is pretty simple. So we are going to try to create couple of functions.
First one is "createArr" which will create our array with specified size as input.
Second one is going to be "resizeArr" which will resize our array and preserve our data.
For the purpose of this example, to preserve simplicity we will only allow to expand
our array to specified number of places.

Steps 3
    include standard library iostream
    Declare createArr function. Its input parameters are just integer value
        which represent size of array.
    return type of this function is going to be pointer to integer values.
    Declare second function which will have input as integer value. This value is going
        to represent number of places with which we are going to expand our array
    declare main function.
    first function is going to allocate block of memory for integers. Its size is going
        to be input parameter.
    first function needs to declare pointer which will show to the newly allocated memory block
    Return that pointer as return value of the function
    second function is going to have three parameters,int pointer which will carry our array,
        and int variable, which will indicate how much we are going to expand our
        array and size variable, representing original size
    After that we need to create new pointer which will show to the newly allocated
        space which expanded by number of places specified by our input parameter.
        After using for loop we can copy data from old array to new one
    before exiting our function we need to delete old array memory block using delete[] operator
    Return value of our function is going to be newly created pointer, thus our
        return type of function is going to be pointer of type int
    in main function we can ask for input of size of the array.
    After successful input we can add our data via for loop
    Ask from user expansion info
    Expand our array with second function
    Print expanded array
*/

#include <iostream>

int* createArr(int n) {
    int *ptr = new int[n];
    return ptr;
}

int* resizeArr(int* ptr,int _size, int exValue) {
    int *newPtr = new int[_size + exValue];

    for (int i = 0; i < _size; i++ ){
        newPtr[i] = ptr[i];
    }
    delete [] ptr;
    return newPtr;
}

int main () {

int _size;
std:: cout<< "Size of array: " << std::endl;
std::cin >>_size;
    int *ptr = createArr(_size);
    std::cout<< "ptr addr: "<< ptr << std::endl;
    //assign value
    for(int i=0;i<_size;i++){

        ptr[i] = i*i;
    }
    //show result
    std::cout << "Created array: "<<std::endl;
    for(int i=0;i<_size;i++){
        std::cout<< ptr[i] << std::endl;
    }

    
    std::cout<< "Expand value: ";
    int expandVal;
    std::cin >> expandVal;
    ptr = resizeArr(ptr, _size, expandVal);
    std::cout<< "ptr addr: "<< ptr << std::endl;

    std::cout<< "Expanded array: " << std::endl;
    for(int i=0;i<(_size +expandVal);i++){
        std::cout<< ptr[i] << std::endl;
    }
    delete [] ptr;
    return 0;
}
