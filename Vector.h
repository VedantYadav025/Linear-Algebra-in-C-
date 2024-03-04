#include <iostream>
#include <vector>

#include "Matrix.h"
namespace LinearAlgebra {
template <typename T>
class Vector {
 private:
  long long int size;
  std::vector<T> arr;

 public:
  Vector(const long long int& n);
  Vector dot(const Vector& v2);
};

template <typename T>
Vector<T>::Vector(const long long int& n) : std::vector<T> arr(n) {}

template <typename T>
Vector<T> Vector<T>::dot(const Vector& v2) {
  if (this->size != v2.size)
    throw std::invalid_argument("Size mismatch for dot product\n");
  T sum = 0;
  for (int i = 0; i < v2.size; i++) sum += this->arr[i] * v2.arr[i];
}

}  // namespace LinearAlgebra
