/*
Pointers to Other Object Types
Although the type of object being pointed to must be included in a pointer declaration,
pointers hold the same kind of value for every type of object:

just a memory address to where the object is stored.

In the following code, a vector is declared.

Write your own code to create a pointer to the address of that vector.
Then, dereference your pointer and print the value of the first item in the vector.
*/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void pointers_to_objects(){
    cout<< __func__ <<"\n";

    // Vector v is declared and initialized to {1, 2, 3}
    vector<int> v {1, 2, 3};

    // Declare and initialize a pointer to the address of v here:
    vector<int> *pointer_to_v;
    pointer_to_v = &v;

    // The following loops over each int a in the vector v and prints.
    // Note that this uses a "range-based" for loop:
    // https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-for-range
    for (int a: v) {
        cout << a << "\n";
    }

    // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    for (int i=0; i<v.size();++i) {
        cout << (*pointer_to_v)[i]<< "\n";
    }
    // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    cout << "The first element of v is: " << (*pointer_to_v)[0] << "\n";

}


void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    (*j)++;

    /*
        When using pointers with functions, some care should be taken.
        If a pointer is passed to a function and then assigned to a variable in the function
        that goes out of scope after the function finishes executing, then the pointer
        will have undefined behavior at that point - the memory it is pointing to might be overwritten by other parts of the program.
    */
}

void Passing_Pointers_to_Function(){
    cout<< __func__ <<"\n";

    int i = 1;
    cout << "The value of i is: " << i << "\n";

    // Declare a pointer to i:
    int* pi = &i;
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";

}


//pass reference , name is j
int* AddOne(int& j)
{
    // Increment the referenced int and return the
    // address of j.
    j++;
    cout << "The address of j is: " << &j << "\n";

    return &j;
}


void Returning_Pointer_from_Function(){
    cout<< __func__ <<"\n";

    int i = 1;
    cout << "The value of i is: " << i << "\n";

    // Declare a pointer and initialize to the value
    // returned by AddOne:

    int* my_pointer = AddOne(i);
    cout << "The value of i is now: " << i << "\n";
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
    //check addr
    cout << "The address of i is: " << &i << "\n";
    cout << "The value of my_pointer is: " << my_pointer << "\n";
    // my_pointer has its own addr
    cout << "The addr of my_pointer is: " << &my_pointer << "\n";

}

int main(){
    pointers_to_objects();
    Passing_Pointers_to_Function();
    Returning_Pointer_from_Function();
}
