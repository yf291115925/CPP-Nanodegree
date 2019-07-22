/*
Delete Operator

Description
Having in mind that we have ability to manually allocate memory using C++,
it is required to have mutual technique for data deallocation. This process is literally
reversed process for data allocation. When you use delete operator on a given memory address,
this means that compiler is going to this address in memory and deleting its content where the
process is finished when this part of memory is marked as unoccupied (free).

    // memory is released in memory where
    // pointer-variable is pointing
    delete pointer-variable;

Releasing block of memory, occupied by array - like data structure is done similary as
complementary allocation. We use square brackets (" [ ] "), to signal that we are deallocating
block of memory which allocated on a given address.

    // this is going to release whole array which
    // pointer is pointing to
    delete[] pointer-variable;
*/
//Example

#include <iostream>
// Illustration of memory allocation and deallocation
int main() {

    int *ptr = nullptr;

    //When using new, best practice in coding states that we need to enclose it within a try-catch block.
    //The new operator throws an exception and does not return a value. To force the new operator
    //to return a value, you canuse the nothrow qualifier as shown below:

    ptr = new(std::nothrow) int;
    if (!ptr) {
     std::cout << "Mem alloc failed!" << std::endl;
    }
    else {
        // assigning value to newly allocated address
        *ptr = 31;
        // checking our pointer state:
        std::cout<<" Address is: " << ptr << std::endl;
        std::cout<<" Value is: " << *ptr << std::endl;
    }

    // We are creating pointer to array of integers
    int *arr_ptr = new(std::nothrow) int[3];
    // We are storing new values to created array
    // 0 1 4
    for (int i=0; i<3; i++)
        arr_ptr[i] = (i*i);

    // Writing our arr_ptr pointer info:

    for (int i=0; i<3; i++) {
        // notice notation for retrieval of memory address
        // in array pointers ( we are using references)
        std::cout<<" Address is: " << &arr_ptr[i] << std::endl;
        std::cout<<" Value is: " << arr_ptr[i] << std::endl;
    }

    // Before our program is finished, we have responsibility
    // to deallocate all of our allocated memory:

    // integer pointer
    delete ptr;
    // array of integers pointer - block of memory
    delete[] arr_ptr;

    return 0;
}


//Now we can easily see why term such as "memory leakage" is causing headaches
//to many C++ developers. This language provides many possibilities and tools
//for solving problems in different engineering areas, but with these possibilities
//we have complementary responsibilities. Memory leakage is in 95% of cases caused with
//forgotten or bad usage of delete operator which is mostly not following particular new operator.
