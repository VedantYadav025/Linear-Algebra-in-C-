#pragma once

#include <iostream>

#include "Matrix.h"
int main() {
  LinearAlgebra::Matrix<int> M1(3, 3);
  LinearAlgebra::Matrix<int> M2(3, 3);
  std::cout << "Enter first Matrix\n";
  std::cin >> M1;
  std::cout << "Enter second Matrix\n";
  std::cin >> M2;
  LinearAlgebra::Matrix<int> M = M1 + M2;
  std::cout << M;
  return 0;
}