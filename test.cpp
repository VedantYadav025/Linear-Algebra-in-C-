#pragma once

#include "Matrix.h"
#include <iostream>

int main() {
  LinAlg::Matrix<int> M(3, 3);
  std::cin >> M;
  std::cout << M.transpose() << "\n";
  return 0;
}

/*
 * M1<int> + M2<float> --> M3<float>
 *
 * static_cast<Matrix<int>> M1 + M2 --> M3  --> preffered, because it is type
 * safe and C++ is a type safe language
 */
