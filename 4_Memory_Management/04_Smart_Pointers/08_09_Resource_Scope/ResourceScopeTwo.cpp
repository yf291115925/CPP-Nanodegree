/*
This example shows the differences between various scopes in C++. 
It uses the same variable name in same program but for different purposes. 
Using global, namespace and function scope will enable us to declare same variable 
name with different set of data for correspoding scope

1.  Declare global variable as part of global scope
2.  Put it in global space, free from any function or closure({})
3.  Declare namespace test and name variable with same name but different value
4.  Create function called func which will use declaration of same 
    variable with different value
5.  Print that variable inside function
6.  In main function declare local variable
7.  Print global variable with :: (global resource specificator)
8.  Print namespace variable with test::variable_name
9.  Call function func
10. Print local variable
*/

#include <iostream>

namespace namespace_test {
  int val = 5;
}

int val = 10;

void func() {
  int val = 15;
  std::cout << " Function val: " << val << std::endl;
}

int main() {
  int val = 20;

  std::cout << " Global val: " << ::val << std::endl;
  std::cout << " Namespace val: " << namespace_test::val << std::endl;
  func();
  std::cout << " Local val: " << val << std::endl;
  return 0;
}