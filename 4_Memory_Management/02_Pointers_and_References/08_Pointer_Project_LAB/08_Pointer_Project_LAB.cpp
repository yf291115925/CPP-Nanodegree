/*
Pointer Project LAB
Description
Using pointers we are going to create first part of our project.
In this lab using knowledge from pointers and references we are going to create our
generic class called "PtrDetails". This class defines an element that is stored in the
garbage collection information list.

Steps
    Declare generic class PtrDetails
    Create generics via templates
    all attributes and methods are going to be public, because they are going to be used by other classes
    create attribute for refcount
    create attribute memPtr as generic pointer for storage of basic info about memory
    create bool attribute isArray for recognition of memory type allocated
    create attribute arraySize for working with array allocation
    Declare constructor for PtrDetails which will have two parameters
    First constructor paremeter is going to be pointer and second which is not required,
        is going to be size of eventual array in memory
    We need to construct logic of the constructor which will set isArray attribute if size is larger then 0
    Create overload operator == which will be used for comparison between to PtrDetails
        object in lists. It is mandatory

*/
//還不確定是不是最後結果, 先記著
template <class T>
class PtrDetails
{
  public:
    // TODO: Implement PtrDetails
    int refcount;
    T *memPtr;
    bool isArray;
    int arraySize;

    PtrDetails(T *ptr, int sizeInMem): memPtr(ptr), arraySize(sizeInMem){
        if (sizeInMem > 0)
            isArray = true;
        }else{
            isArray = false;
        }

};
// operator== defines a comparison between two objects

template <class T>
bool operator==(const PtrDetails<T> &obj_1,
                const PtrDetails<T> &obj_2)
{
    // TODO: Implement operator
    if (obj_1->memPtr == obj_2->memPtr){
        return true;
    }else{
        return false;
    }

}
