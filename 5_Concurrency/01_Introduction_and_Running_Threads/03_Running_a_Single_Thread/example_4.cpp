#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work 1 in thread\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 2 in thread\n";
}

int main() {
  // create thread
  std::thread t(threadFunction);

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work 1 in main\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 2 in main\n";

  // wait for thread to finish
  t.join();

  return 0;
}