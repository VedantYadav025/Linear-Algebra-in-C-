#include <iostream>

#include "Matrix.h"
int main() {
  Matrix<int> M1(3, 3);
  Matrix<int> M2(3, 3);
  std::cout << "Enter first Matrix\n";
  std::cin >> M1;
  std::cout << "Enter second Matrix\n";
  std::cin >> M2;
  Matrix<int> M1_transpose = M1.transpose();
  std::cout << M1_transpose;
  Matrix<int> M_product = M1.matmul(M2);
  return 0;
}