/*
New and delete Project LAB
Description
We talked about how every new needs to be followed by delete. In our project,
where we are constructing garbage collector, which works on a same principle as shared_ptr,
we can see that concept of reference counting is simple. By using static container of data in our class,
where we are remembering every address which every instance pointer pointed in memory and how much
references specific memory holds in a given moment. Here in this context, valid usage of delete operator
is crucial. We are using collect method from the class to delete unused memory location.
We need to decide by our attributes when to use delete and when delete[]. We can see that this
method is only called in destructor. every time when any instance of Class pointer goes out scope
collect is called to delete any left over garbage (unused memory).
*/

//沒跑過, 先放著
// Collect garbage. Returns true if at least
// one object was freed.
template <class T, int size>
bool Pointer<T, size>::collect(){
    bool memfreed = false;
    typename std::list<PtrDetails<T> >::iterator p;
    do{
        // Scan refContainer looking for unreferenced pointers.
        for (p = refContainer.begin(); p != refContainer.end(); p++){
            // If in-use, skip.
            if (p->refcount > 0)
                continue;
            memfreed = true;
            // Remove unused entry from refContainer.
            refContainer.remove(*p);

            // Free memory unless the Pointer is null.
            if (p->memPtr){
                if (p->isArray){
                    delete[] p->memPtr; // delete array
                }
                else{
                    delete p->memPtr; // delete single element
                }
            }
            // Restart the search.
            break;
        }
    } while (p != refContainer.end());
    return memfreed;
}


// Destructor for Pointer.
template <class T, int size>
Pointer<T, size>::~Pointer(){

    typename std::list<PtrDetails<T> >::iterator p;

    p = findPtrInfo(addr);
    if (p->refcount)
        p->refcount--;
    // decrement ref count
    // Collect garbage when a pointer goes out of scope.
    collect();
    // For real use, you might want to collect unused memory less frequently,
    // such as after refContainer has reached a certain size, after a certain number of Pointers have gone out of scope,
    // or when memory is low.
}
