#pragma once

#include "Matrix.h"
#include <iostream>

/*
Matrix<double> M(2,2) = LinAlg::randn({2,2}, mean);
*/

int main() {
  LinAlg::Matrix<int> M(2, 2);
  M = {{1, 2}, {3, 4}};
  std::cout << M << "n";
  return 0;
}

/*
 * M1<int> + M2<float> --> M3<float>
 *
 * static_cast<Matrix<int>> M1 + M2 --> M3  --> preffered, because it is type
 * safe and C++ is a type safe language
 */
