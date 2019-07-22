#include <iostream>
#include <thread>

class Vehicle {
  public:
    Vehicle() {
      _id = 0;
    }
    void addID(int id) { 
      _id = id; 
    }
    void printID() { 
      std::cout << "Vehicle ID=" << _id << std::endl; 
    }

  private:
    int _id;
};

int main() {
  // create thread
  std::shared_ptr<Vehicle> v(new Vehicle);
  std::thread t =
      std::thread(&Vehicle::addID, v, 1);  // call member function on object v

  // wait for thread to finish
  t.join();

  // print Vehicle id
  v->printID();

  return 0;
}