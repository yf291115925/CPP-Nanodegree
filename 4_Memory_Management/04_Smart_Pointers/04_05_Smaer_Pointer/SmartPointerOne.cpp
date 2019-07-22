/*
Illustrate the use of unique_ptr in C++. With this example
use the common method when handling these type of pointers.

1.  Declare simple class called A
2.  Add one method which is non - return type
3.  Print something in it
4.  Declare new pointer unique_ptr which is same type as declared class
5.  Using constructor syntax, as part of declaration of pointer declare new class
    A instace
6.  Using pointer reference syntax "->" invoke class method
7.  Use .get() method to retrieve memory address from declared pointer
8.  Use move method to transfer memory data from first pointer to second one
9.  Try to print both addresses via get()
10. Add third pointer
11. Try same thing
12. Notice that info is transfered to next pointer without leaving copies in
    previous ones
*/

// C++ program to illustrate the use of unique_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
 public:
  void show() { 
    cout << "Class A::classMethod" << endl; 
    }
};

int main() {
  unique_ptr<A> ptr_1(new A);
  ptr_1->show();

  // returns the memory address of ptr_1
  cout << ptr_1.get() << endl;
  cout << endl;

  // transfers ownership to ptr_2
  unique_ptr<A>
  ptr_2 = move(ptr_1);
  ptr_2->show();
  cout << ptr_1.get() << endl;
  cout << ptr_2.get() << endl;
  cout << endl;

  // transfers ownership to ptr_3
  unique_ptr<A> ptr_3 = move(ptr_2);
  ptr_3->show();
  cout << ptr_1.get() << endl;
  cout << ptr_2.get() << endl;
  cout << ptr_3.get() << endl;

  return 0;
}
