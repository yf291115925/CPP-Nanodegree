#include <iostream>
#include <thread>

int main() {
  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concurrency with " << nCores
            << " cores available" << std::endl;

  return 0;
}