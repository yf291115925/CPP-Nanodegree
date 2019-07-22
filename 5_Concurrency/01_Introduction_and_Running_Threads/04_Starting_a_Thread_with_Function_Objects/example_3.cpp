#include <iostream>
#include <thread>

class Vehicle {
  public:
    Vehicle(int id) {
      _id = id;
    }
    void operator()() {
      std::cout << "Vehicle #" << _id << " has been created" << std::endl;
    }

  private:
    int _id;
};

int main() {
  // create thread
  std::thread t = std::thread(Vehicle(1));  // Use copy initialization

  // do something in main()
  std::cout << "Finished work in main \n";

  // wait for thread to finish
  t.join();

  return 0;
}