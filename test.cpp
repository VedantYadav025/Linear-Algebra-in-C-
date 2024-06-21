#pragma once
#include <iostream>

#include "Matrix.h"

int main() {
  LinearAlgebra::Matrix<int> M1(3, 3);
  std::cin >> M1;
  int det = M1.determinantLaplace();
  std::cout << det << "\n";
  return 0;
}