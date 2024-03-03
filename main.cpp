#include <iostream>

#include "Matrix.h"
int main() {
  Matrix<int> M1(3, 3);
  Matrix<int> M2(3, 3);
  std::cout << "Enter first Matrix\n";
  std::cin >> M1;
  std::cout << "Enter second Matrix\n";
  std::cin >> M2;
  Matrix<int> M = M1 ^ 2;
  std::cout << M;
  return 0;
}