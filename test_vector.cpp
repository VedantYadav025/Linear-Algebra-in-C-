#pragma once
#include <iostream>

#include "Vector.h"

int main() {
  int n;
  std::cin >> n;
  LinearAlgebra::Vector<int> v(n);
  std::cin >> v;
  return 0;
}