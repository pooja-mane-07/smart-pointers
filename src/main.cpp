#include <iostream>

#include "unique_ptr.h"

class Resource {
  int value;

 public:
  Resource(int temp = 0) : value(temp) {}

  void display() const { std::cout << "Resource value: " << value << std::endl; }

  friend std::ostream& operator<<(std::ostream& out, const Resource& res);
};

std::ostream& operator<<(std::ostream& out, const Resource& res) {
  out << "Resource with value: " << res.value;
  return out;
}

int main() {
  UniquePointer<Resource> ptr1(new Resource(5));

  std::cout << "Demonstration of UniquePointer functionality:" << std::endl;
  std::cout << *ptr1 << std::endl;
  ptr1->display();

  ptr1.reset(new Resource(10));
  std::cout << "After reset:" << std::endl;
  std::cout << *ptr1 << std::endl;

  return 0;
}
