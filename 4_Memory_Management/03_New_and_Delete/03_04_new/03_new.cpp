/*
New Operator
Description
In C++ we can encounter need for memory allocation. Memory allocation is technique of memory management
where programs and services are assigned to use host computer memory. This process is know for owning and
reserving parts of computer memory, generally to performs some program related tasks. We have two types of
memory management: dynamic and static.
Generally memory operations via user programs are performed with dynamic allocation.
Dynamic allocation is allocated on Heap, while typical and local variables are allocated on Stack.

Way of usage of dynamic allocation in C++ is performed via operator new. New operator is used
by C++ for request to perform memory allocation on Heap. Before any action, couple of requests
needs to be fulfilled for successful allocation. First of all we need to have sufficient memory
and we need to know which type of data ( what size of memory) we are reserving for our usage.
After these requirements are fulfilled we can perfom memory allocation. Next action is allocation of
memory and return of memory address in heap.
General purpose syntax is:

    pointer = new type-specifier

In this context we can see that pointer is used to access this newly created data.
We are using pointers because this performed actions returns memory address.
Technique for usage of memory addresses in C++ is usage of pointers. Next in line is
type-specifier. This can be any user defined or default defined data type (classes, structures, char, int, float, double).
Besides that, data types could be array like structures, where we can defined arrays of mentioned data types.

    // Declaration of pointer
    int *pointer = NULL;
    // allocating memory for int data type - number
    // and assigning newly returned address to pointer
    pointer = new int;

We can see here that this pointer is only way to retrieved newly created data. With pointers and
their arithmetics we can access, change and move our allocated data. Also we can notice that this
pointer is pointing to allocated memory, but don't have any specific data stored.
Luckily, default constructor of int data type is used to set default value to 0. Logical behavior would be
to have nothing on this address, but we need to keep in mind that computer memory is very dynamic and busy place.
Thousands, maybe even millions of operations are done in this part of computer so probably, some process or our
operating system used this part of memory where we allocated our int type.
At the moment of allocation this part wasn't used by any process so it was available and large enough
to be reserved by our integer data. But probably, someone else has be using this space and we can encounter
some "garbage" there. By garbage we mean that this address contains some value which was left behind by last
usage of this memory. That is why this practice of allocating and not specifying our value of data in memory
is bad practice.
*/


// Example program
#include <iostream>

int main()
{
    double *ptr = new double(23);
    double *arr_ptr =  new double[4];
    arr_ptr[2] = 2;
    for( int i = 0; i<3; i++) {
        *ptr = ++ *ptr;
        //同一ptr, 一直改 指到的值而已, 所以ptr 不變
        std::cout<< "ptr Address: "<<ptr<<", ptr Value: "<<*ptr<<std::endl;
        //arr_ptr 一直是array 的頭, 所以不變, 後面用 [] 來表示address跳動
        std::cout<< "arr_ptr Address array: "<<arr_ptr<<",array address:"<<&arr_ptr[i]<<" Value array: "<<arr_ptr[i]<<std::endl;
    }
}
// OUTPUT:
/*
Address: 0x1a809e0 Value: 24
Address array: 0x1a80a00 Value array: 0
Address: 0x1a809e0 Value: 25
Address array: 0x1a80a00 Value array: 0
Address: 0x1a809e0 Value: 26
Address array: 0x1a80a00 Value array: 0
*/
