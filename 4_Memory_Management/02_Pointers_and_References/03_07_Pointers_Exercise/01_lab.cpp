/*
LAB 1
Objectives
    In this example we are going to make an implementation of memory allocation C++
    via pointers. Using operators new and delete we are going to successfuly allocate
    and free memory (deallocation). Using pointers we are enabled to manipulate content
    of memory which has been allocated for usage.

Steps
    Create new cpp file
    include standard iostream header
    Using pointer syntax declared integer type pointer
    Allocate memory of integer size via operator new
    Set this part of memory to specific integer
    Print memory address
    Print memory address value
    Free taken memory from the heap
    Exit script
*/
#include<iostream>

int main(){
    int *ptr = nullptr;
    ptr = new int(10);

    std::cout << "memory address:" << ptr << std::endl;
    std::cout << "memory address value:" << *ptr << std::endl;

    delete ptr;

    return 0;

}
