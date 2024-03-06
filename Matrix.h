#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

namespace LinearAlgebra {
template <typename T>
class Matrix {
 private:
  long long int n_rows, n_cols;
  std::vector<std::vector<T>> arr;

 public:
  // Constructor (inputs : number of rows, number of columns)
  Matrix(long long int rows, long long int cols);
  /*
    Matrix Addition, Substraction, Multiplication
  */
  std::pair<long long int, long long int> getSize();
  std::vector<std::vector<T>> getArray();
  Matrix operator+(const Matrix& M1);
  Matrix operator-(const Matrix& M1);
  Matrix operator^(const long long int& power);
  Matrix matmul(const Matrix& M1);
  Matrix transpose();
  bool isSymmetric();
  bool isUpperTriangular();
  bool isLowerTriangular();

  T l2Norm();
  T trace();
  /*
    Scalar Multiplication
  */
  template <typename U>
  friend Matrix<U> operator*(const U& scalar, Matrix<U>& M);
  /*
    Input and Output Operators
  */
  template <typename U>
  friend std::istream& operator>>(std::istream& input, Matrix<U>& M);
  template <typename U>
  friend std::ostream& operator<<(std::ostream& output, Matrix<U>& M);
};

template <typename T>
std::pair<long long int, long long int> Matrix<T>::getSize() {
  std::pair<long long int, long long int> size =
      std::make_pair(this->n_rows, this->n_cols);
  return size;
}

template <typename T>
std::vector<std::vector<T>> Matrix<T>::getArray() {
  return this->arr;
}

template <typename T>
Matrix<T>::Matrix(long long int rows, long long int cols)
    : arr(rows, std::vector<T>(cols)) {
  n_rows = rows;
  n_cols = cols;
}

template <typename T>
std::istream& operator>>(std::istream& input, Matrix<T>& M) {
  for (long long int i = 0; i < M.n_rows; i++) {
    for (long long int j = 0; j < M.n_cols; j++) {
      input >> M.arr[i][j];
    }
  }
  return input;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, Matrix<T>& M) {
  for (long long int i = 0; i < M.n_rows; i++) {
    for (long long int j = 0; j < M.n_cols; j++) {
      output << M.arr[i][j] << " ";
    }
    std::cout << "\n";
  }
  return output;
}

template <typename T>
Matrix<T> operator*(const T& scalar, Matrix<T>& M) {
  for (long long int i = 0; i < M.n_rows; i++) {
    for (long long int j = 0; j < M.n_cols; j++) {
      M.arr[i][j] *= scalar;
    }
  }
  return M;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& M1) {
  if ((this->n_rows != M1.n_rows) || (this->n_cols != M1.n_cols)) {
    throw std::invalid_argument("Matrices must be of same size\n");
  }
  long long int add_rows = M1.n_rows;
  long long int add_cols = M1.n_cols;
  Matrix<T> Addition(add_rows, add_cols);
  for (long long int i = 0; i < add_rows; i++) {
    for (long long int j = 0; j < add_cols; j++) {
      Addition.arr[i][j] = M1.arr[i][j] + this->arr[i][j];
    }
  }
  return Addition;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& M1) {
  if ((this->n_rows != M1.n_rows) || (this->n_cols != M1.n_cols)) {
    throw std::invalid_argument("Matrices must be of same size\n");
  }
  long long int subs_rows = M1.n_rows;
  long long int subs_cols = M1.n_cols;
  Matrix<T> Substraction(subs_rows, subs_cols);
  for (long long int i = 0; i < subs_rows; i++) {
    for (long long int j = 0; j < subs_cols; j++) {
      Substraction.arr[i][j] = this->arr[i][j] - M1.arr[i][j];
    }
  }
  return Substraction;
}

template <typename T>
Matrix<T> Matrix<T>::matmul(const Matrix<T>& M1) {
  if (this->n_cols != M1.n_rows) {
    throw std::invalid_argument("Matrix shape mismatch\n");
  }
  Matrix<T> product(this->n_rows, M1.n_cols);
  for (long long int i = 0; i < product.n_rows; i++) {
    for (long long int j = 0; j < product.n_cols; j++) {
      T sum = 0;
      for (int k = 0; k < this->n_cols; k++) {
        sum += this->arr[i][k] * M1.arr[k][j];
      }
      product.arr[i][j] = sum;
    }
  }
  return product;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() {
  long long int cols = this->n_rows;
  long long int rows = this->n_cols;
  Matrix<T> transpose_matrix(rows, cols);
  for (long long int i = 0; i < rows; i++) {
    for (long long int j = 0; j < cols; j++) {
      transpose_matrix.arr[i][j] = this->arr[j][i];
    }
  }
  return transpose_matrix;
}

template <typename T>
T Matrix<T>::trace() {
  if (this->n_rows != this->n_cols)
    throw std::invalid_argument(
        "Traces are only defined for square matrices\n");
  T sum = 0;
  for (long long int i = 0; i < this->n_rows; i++) sum += this->arr[i][i];
  return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator^(const long long int& power) {
  if (this->n_rows != this->n_cols)
    throw std::invalid_argument("Matrix shape mismatch\n");
  Matrix<T> matrix_power(this->n_rows, this->n_cols);
  for (int i = 0; i < power; i++) {
    if (i == 0)
      matrix_power = *this;
    else
      matrix_power = matrix_power.matmul(*this);
  }
  return matrix_power;
}

template <typename T>
T Matrix<T>::l2Norm() {
  T sum = 0;
  for (long long int i = 0; i < this->n_rows; i++) {
    for (long long int j = 0; j < this->n_cols; j++) {
      sum += pow(this->arr[i][j], 2);
    }
  }
  return sum;
}

template <typename T>
bool Matrix<T>::isSymmetric() {
  if (this->n_rows != this->n_cols) {
    std::cout << "Only square matrices can be symmetric\n";
    return false;
  }
  for (long long int i = 0; i < this->n_rows; i++) {
    for (long long int j = 0; j < this->n_cols; j++) {
      if (this->arr[i][j] != this->arr[j][i]) return false;
    }
  }
  return true;
}

template <typename T>
bool Matrix<T>::isUpperTriangular() {
  for (long long int i = 0; i < this->n_rows; i++) {
    for (long long int j = 0; j < i; j++) {
      if (this->arr[i][j] != 0) return false;
    }
  }
  return true;
}

template <typename T>
bool Matrix<T>::isLowerTriangular() {
  Matrix<T> transpose = this->transpose();
  return transpose.isUpperTriangular();
}

}  // namespace LinearAlgebra
