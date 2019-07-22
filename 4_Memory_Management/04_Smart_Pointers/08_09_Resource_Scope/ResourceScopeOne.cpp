/*
This example illustrates usage of namespaces 
in C++. With this techique we can create a centralized contained 
scope of data which can be used in other parts of application. 
We are going to create a namespace called math, where we are 
going to add typical mathematical constants.

1. Declare namespace called math
1. Inside of the namespace declare common mathematical constants
1. Declare pi, euler, square root of 2 , and logarithm of 2
1. Use main to print namespace variables
1. Use resource scope specificator to access namespace variables
*/

#include <iostream>

namespace math {
  const double pi = 3.141592653;
  const double euler = 2.718281828;
  const double sqrt2 = 1.414213562;
  const double ln2 = 0.6931471;
}  // namespace math

int main() {
  std::cout << math::pi << std::endl;
  std::cout << math::euler << std::endl;
  std::cout << math::sqrt2 << std::endl;
  std::cout << math::ln2 << std::endl;

  return 0;
}