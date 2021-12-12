// Copyright by MaryMorgan

#include <iostream>
#include "ptr.hpp"


int main() {
  std::cout << "test"<<"\n";

  int *p = new int{6};

  SharedPtr sp1(p);
  std::cout << sp1.use_count() << std::endl;
  SharedPtr sp2(sp1);
  std::cout << sp2.use_count() << std::endl;
  return 0;
}
