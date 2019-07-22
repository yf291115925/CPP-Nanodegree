#include <iostream>
#include <string>
#include <thread>

void printName(std::string &name, int waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  name += " (from Thread)";
  std::cout << name << std::endl;
}

int main() {
  std::string name("MyThread");

  // starting thread
  std::thread t(printName, std::ref(name), 50);

  // wait for thread before returning
  t.join();

  // print name from main
  name += " (from Main)";
  std::cout << name << std::endl;

  return 0;
}