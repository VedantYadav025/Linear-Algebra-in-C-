#pragma once
#include <iostream>

#include "Vector.h"

int main() {
  LinearAlgebra::Vector<int> v(5);
  std::cin >> v;
  std::cout << v;
  return 0;
}