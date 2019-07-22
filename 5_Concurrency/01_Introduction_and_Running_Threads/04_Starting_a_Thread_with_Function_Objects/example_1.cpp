#include <iostream>
#include <thread>

class Vehicle {
  public:
    void operator()() {
      std::cout << "Vehicle object has been created \n";
    }
};

int main() {
  // create thread
  std::thread t((Vehicle()));  // C++'s most vexing parse

  // do something in main()
  std::cout << "Finished work in main \n";

  // wait for thread to finish
  t.join();

  return 0;
}