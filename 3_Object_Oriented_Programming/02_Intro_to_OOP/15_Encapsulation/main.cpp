/*
Debugging Exercise

Debugging in C++ can be tedious, but learning how to read the error messages and figure out what went
wrong is a super important skill to develop!

In the code below, we've introduced a few small errors.
Press the Compile & Run button to see what errors occur.
Then see if you can clean them up! Scroll down to see a solution if you get stuck.
*/

// Encapsulation
// #include <iostream>  

// class Encapsulation {
//   private
//     int x;  // data encapsulated (hidden) within the class
    
//   public
//     void Set(int a)  // interface to set the value of variable x
//     {
//       x = a
//     }

//     int Get() // interface to get the value of variable x
//     {
//       return x;
    
// };

// int main()
// {
//   Encapsulation obj;
//   obj.Set(5);
//   std::cout << obj.Get() << "\n";
// }


// Encapsulation
#include<iostream>

class Encapsulation{
  private:
    // data hidden from outside world
    int x;
  public:  // <- error 1 was here
    // function to set value of  
    // variable x
    void Set(int a) {
      x = a;  // <- error 2 was here
    }

    // function to return value of
    // variable x
    int Get() {
      return x;
    }  // <- error 3 was here
};

// main function
int main(){
  Encapsulation obj;
  obj.Set(5);
  std::cout << obj.Get() << "\n";
}