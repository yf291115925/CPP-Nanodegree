#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work in thread\n";
}

int main() {
  // create thread
  std::thread t(threadFunction);

  // detach thread and continue with main
  t.detach();

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work in main\n";

  return 0;
}