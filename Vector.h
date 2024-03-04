#pragma once
#include <iostream>
#include <vector>

namespace LinearAlgebra {
template <typename T>
class Vector {
 private:
  long long int size;
  std::vector<T> arr;

 public:
  Vector(const long long int& n);
  Vector dot(const Vector& v2);
  Vector operator+(const Vector& v2);
  Vector operator-(const Vector& v2);
  template <typename U>
  friend std::ostream& operator<<(std::ostream& output, Vector<U>& v);
  template <typename U>
  friend std::istream& operator>>(std::istream& input, Vector<U>& v);
};

template <typename T>
Vector<T>::Vector(const long long int& n) : arr(n) {
  this->size = n;
}

template <typename T>
Vector<T> Vector<T>::dot(const Vector& v2) {
  if (this->size != v2.size)
    throw std::invalid_argument("Size mismatch for dot product\n");
  T sum = 0;
  for (int i = 0; i < v2.size; i++) sum += this->arr[i] * v2.arr[i];
  return sum;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector& v2) {
  if (this->size != v2.size)
    throw std::invalid_argument("Size mismatch for vector addition\n");
  Vector<T> sum(v2.size);
  for (int i = 0; i < v2.size; i++) {
    sum.arr[i] = this->arr[i] + v2.arr[i];
  }
  return sum;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector& v2) {
  if (this->size != v2.size)
    throw std::invalid_argument("Size mismatch for vector addition\n");
  Vector<T> minus(v2.size);
  for (int i = 0; i < v2.size; i++) {
    minus.arr[i] = this->arr[i] - v2.arr[i];
  }
  return minus;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, Vector<T>& v) {
  for (int i = 0; i < v.size; i++) output << v.arr[i] << " ";
  output << "\n";
  return output;
}

template <typename T>
std::istream& operator>>(std::istream& input, Vector<T>& v) {
  for (int i = 0; i < v.size; i++) input >> v.arr[i];
  return input;
}

}  // namespace LinearAlgebra
