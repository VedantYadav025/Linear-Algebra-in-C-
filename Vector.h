#pragma once
#include <cmath>
#include <iostream>
#include <vector>

namespace LinearAlgebra {
template <typename T>
// A vector is just a matrix of the shape (n, 1)
class Vector {
 private:
  long long int size;
  std::vector<T> arr;

 public:
  long long int getSize();
  std::vector<T> getArray();
  void setArray(const long long int& index, const long long int& value);
  Vector(const long long int& n);
  Vector dot(const Vector& v2);
  Vector operator+(const Vector& v2);
  Vector operator-(const Vector& v2);
  Vector cross(const Vector& v2);
  template <typename U>
  friend std::ostream& operator<<(std::ostream& output, Vector<U>& v);
  template <typename U>
  friend std::istream& operator>>(std::istream& input, Vector<U>& v);
  double l2Norm();
};



template <typename T>
long long int Vector<T>::getSize() {
  return this->size;
}

template <typename T>
std::vector<T> Vector<T>::getArray() {
  return this->arr;
}

template <typename T>
void Vector<T>::setArray(const long long int& index,
                         const long long int& value) {
  this->arr[index] = value;
  return;
}

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

template <typename T>
double Vector<T>::l2Norm() {
  double squared_sum = 0;
  for (int i = 0; i < this->size; i++)
    squared_sum += this->arr[i] * this->arr[i];
  return sqrt(squared_sum);
}

template <typename T>
Vector<T> Vector<T>::cross(const Vector<T>& v2) {
  if ((this->size != v2.size)) throw std::invalid_argument("Vectors must be of the same size\n");
  else if (this->size > 3) throw std::invalid_argument("Cross product is only defined for vectors of dimmension less then 3\n");
}
}  // namespace LinearAlgebra
