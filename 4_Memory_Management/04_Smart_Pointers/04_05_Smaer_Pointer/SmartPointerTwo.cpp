/*
A shared_ptr is a container for raw pointers. It is a reference counting
ownership model, i.e. it upholds the reference count of its contained
pointer in correlation with all of the shared_ptr copies. Basically,
any time a new pointer points to a memory block an incrementation of
the counter happens. Likewise, it decrements when the destructor of
the object is called.

1.  Declare simple class called A
2.  Add one method which is non - return type
3.  Print something in it
4.  Declare new pointer shared_ptr which is same type as declared class
5.  Using constructor syntax,as part of declaration of pointer declare new class
A instace
6.  Using pointer reference syntax "->" invoke class method
7.  Use .get() method to retrieve memory address from declared pointer
8.  Use use_count method to display current number of references to pointer
memory address
9.  Try to print both addresses via get()
10. Use .reset() method to release first pointer memory
11. Try same thing
12. Notice that info is transfered to next pointer as copy from previous ones
*/

#include <iostream>
#include <memory>
using namespace std;

class A {
  public:
    void show() { 
      cout << "A::classMethod" << endl; 
    }
};

int main() {
  shared_ptr<A> ptr_1(new A);
  ptr_1->show();
  cout << ptr_1.get() << endl;
  cout << endl;

  shared_ptr<A> ptr_2(ptr_1);
  ptr_2->show();
  cout << ptr_1.get() << endl;
  cout << ptr_2.get() << endl;
  cout << endl;

  // Returns the number of shared_ptr objects
  // referring to the same managed object.
  cout << ptr_1.use_count() << endl;
  cout << ptr_2.use_count() << endl;
  cout << endl;

  // Relinquishes ownership of p1 on the object
  // and pointer becomes NULL
  ptr_1.reset();
  cout << ptr_1.get() << endl;
  cout << ptr_2.use_count() << endl;
  cout << ptr_2.get() << endl;
  cout << endl;

  return 0;
}