#pragma once
#include "Matrix.h"

std::vector<uint64_t> zeroRowIndices(
    const std::vector<std::vector<long long int>>& arr) {
  std::vector<uint64_t> zero_row_indices;
  for (uint64_t i = 0; i < arr.size(); i++) {
    bool is_zero = true;
    for (long long int j = 0; j < arr[0].size(); j++) {
      if (arr[i][j] != 0) {
        is_zero = false;
        break;
      }
      if (is_zero) zero_row_indices.push_back(i);
    }
  }
  return zero_row_indices;
}

namespace LinearAlgebra {
template <typename T>
Matrix<float> Matrix<T>::rref() {
  long long int zero_row_indices;
  
}
}  // namespace LinearAlgebra