#pragma once
#include "Matrix.h"
#include "Vector.h"

namespace LinearAlgebra {
template <typename T>
Vector<T> vecmul(Matrix<T>& M, Vector<T>& v) {
  std::vector<std::vector<T>> arr_matrix = M.getArray();
  std::vector<T> arr_vector = v.getArray();
  long long int size = (M.getSize()).first;
  Vector<T> product(size);
  for (int i = 0; i < size; i++) {
    T sum = 0;
    for (int j = 0; j < v.getSize(); j++) {
      sum += arr_matrix[i][j] * arr_vector[j];
    }
    product.setArray(i, sum);
  }
  return product;
}
}  // namespace LinearAlgebra