#pragma once
#include <iostream>

#include "matrix_algorithms.h"

int main() {
  LinearAlgebra::Matrix<int> M(3, 3);
  LinearAlgebra::Vector<int> v(3);
  LinearAlgebra::Vector<int> result(3);
  std::cin >> M;
  std::cin >> v;
  result = LinearAlgebra::vecmul(M, v);
  std::cout << result << "\n";
  return 0;
}