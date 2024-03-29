#pragma once

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

namespace LinearAlgebra {
template <typename T>
class Matrix {
 private:
  uint64_t rows_, cols_;
  std::vector<std::vector<T>> arr_;

 public:
  // Constructor (inputs : number of rows, number of columns)
  Matrix(uint64_t rows, uint64_t cols);
  /*
    Matrix Addition, Substraction, Multiplication
  */
  std::pair<uint64_t, uint64_t> getSize();
  std::vector<std::vector<T>> getArray();
  void setArray(const std::vector<std::vector<T>>& arr);
  Matrix operator+(const Matrix& M1);
  Matrix operator-(const Matrix& M1);
  Matrix operator^(const uint64_t& power);
  Matrix operator=(const Matrix& M);
  Matrix matmul(const Matrix& M1);
  Matrix transpose();
  Matrix<float> toFloat();
  Matrix resize(const uint64_t& new_row, const uint64_t& new_column);
  Matrix<T> subMatrix(const uint64_t& row_to_be_deleted,
                      const uint64_t& col_to_be_deleted);
  T determinantLaplace();
  bool isSymmetric();
  bool isUpperTriangular();
  bool isLowerTriangular();
  bool isZero();
  std::pair<Matrix, Matrix> lu();

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
void Matrix<T>::setArray(const std::vector<std::vector<T>>& arr) {
  this->arr_ = arr;
  return;
}

template <typename T>
std::pair<uint64_t, uint64_t> Matrix<T>::getSize() {
  std::pair<uint64_t, uint64_t> size = std::make_pair(this->rows_, this->cols_);
  return size;
}

template <typename T>
std::vector<std::vector<T>> Matrix<T>::getArray() {
  return this->arr;
}

template <typename T>
Matrix<T>::Matrix(uint64_t rows, uint64_t cols)
    : arr_(rows, std::vector<T>(cols)) {
  rows_ = rows;
  cols_ = cols;
}

template <typename T>
std::istream& operator>>(std::istream& input, Matrix<T>& M) {
  for (uint64_t i = 0; i < M.rows_; i++) {
    for (uint64_t j = 0; j < M.cols_; j++) {
      input >> M.arr_[i][j];
    }
  }
  return input;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, Matrix<T>& M) {
  for (uint64_t i = 0; i < M.rows_; i++) {
    for (uint64_t j = 0; j < M.cols_; j++) {
      output << M.arr_[i][j] << " ";
    }
    std::cout << "\n";
  }
  return output;
}

template <typename T>
Matrix<T> operator*(const T& scalar, Matrix<T>& M) {
  for (uint64_t i = 0; i < M.rows_; i++) {
    for (uint64_t j = 0; j < M.cols_; j++) {
      M.arr[i][j] *= scalar;
    }
  }
  return M;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& M1) {
  if ((this->rows_ != M1.rows_) || (this->cols_ != M1.cols_)) {
    throw std::invalid_argument("Matrices must be of same size\n");
  }
  uint64_t add_rows = M1.rows_;
  uint64_t add_cols = M1.cols_;
  Matrix<T> Addition(add_rows, add_cols);
  for (uint64_t i = 0; i < add_rows; i++) {
    for (uint64_t j = 0; j < add_cols; j++) {
      Addition.arr_[i][j] = M1.arr_[i][j] + this->arr_[i][j];
    }
  }
  return Addition;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& M1) {
  if ((this->rows_ != M1.rows_) || (this->cols_ != M1.cols_)) {
    throw std::invalid_argument("Matrices must be of same size\n");
  }
  uint64_t subs_rows = M1.rows_;
  uint64_t subs_cols = M1.cols_;
  Matrix<T> Substraction(subs_rows, subs_cols);
  for (uint64_t i = 0; i < subs_rows; i++) {
    for (uint64_t j = 0; j < subs_cols; j++) {
      Substraction.arr_[i][j] = this->arr_[i][j] - M1.arr_[i][j];
    }
  }
  return Substraction;
}

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& M) {
  if (this == &M) return this;
  M.rows_ = this->rows_;
  M.cols_ = this->cols_;
  for (uint64_t i = 0; i < this->rows_; i++) {
    for (uint64_t j = 0; j < this->cols_; j++) {
      M.arr_[i][j] = this->arr_[i][j];
    }
  }
  return M;
}

template <typename T>
Matrix<T> Matrix<T>::matmul(const Matrix<T>& M1) {
  if (this->cols_ != M1.rows_)
    throw std::invalid_argument("Matrix shape mismatch\n");
  Matrix<T> product(this->rows_, M1.cols_);
  for (uint64_t i = 0; i < product.rows_; i++) {
    for (uint64_t j = 0; j < product.cols_; j++) {
      T sum = 0;
      for (int k = 0; k < this->cols_; k++) {
        sum += this->arr_[i][k] * M1.arr_[k][j];
      }
      product.arr_[i][j] = sum;
    }
  }
  return product;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() {
  uint64_t cols = this->rows_;
  uint64_t rows = this->cols_;
  Matrix<T> transpose_matrix(rows, cols);
  for (uint64_t i = 0; i < rows; i++) {
    for (uint64_t j = 0; j < cols; j++) {
      transpose_matrix.arr_[i][j] = this->arr_[j][i];
    }
  }
  return transpose_matrix;
}

template <typename T>
T Matrix<T>::trace() {
  if (this->rows_ != this->cols_)
    throw std::invalid_argument(
        "Traces are only defined for square matrices\n");
  T sum = 0;
  for (uint64_t i = 0; i < this->rows_; i++) sum += this->arr_[i][i];
  return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator^(const uint64_t& power) {
  if (this->rows_ != this->cols_)
    throw std::invalid_argument("Matrix shape mismatch\n");
  Matrix<T> matrix_power(this->rows_, this->cols_);
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
  for (uint64_t i = 0; i < this->rows_; i++) {
    for (uint64_t j = 0; j < this->cols_; j++) {
      sum += pow(this->arr_[i][j], 2);
    }
  }
  return sqrt(sum);
}

template <typename T>
bool Matrix<T>::isSymmetric() {
  if (this->rows_ != this->cols_) {
    std::cout << "Only square matrices can be symmetric\n";
    return false;
  }
  for (uint64_t i = 0; i < this->rows_; i++) {
    for (uint64_t j = 0; j < this->cols_; j++) {
      if (this->arr_[i][j] != this->arr_[j][i]) return false;
    }
  }
  return true;
}

template <typename T>
bool Matrix<T>::isUpperTriangular() {
  for (uint64_t i = 0; i < this->rows_; i++) {
    for (uint64_t j = 0; j < i; j++) {
      if (this->arr_[i][j] != 0) return false;
    }
  }
  return true;
}

template <typename T>
bool Matrix<T>::isLowerTriangular() {
  Matrix<T> transpose = this->transpose();
  return transpose.isUpperTriangular();
}

template <typename T>
bool Matrix<T>::isZero() {
  bool is_zero = true;
  for (uint64_t i = 0; i < this->rows_; i++) {
    for (uint64_t j = 0; j < this->cols_; j++) {
      if (this->arr_[i][j] != 0) {
        is_zero = false;
        break;
      }
    }
  }
  return is_zero;
}

template <typename T>
Matrix<float> Matrix<T>::toFloat() {
  Matrix<float> M_float(this->rows_, this->cols_);
  std::vector<std::vector<float>> arr_float(this->rows_,
                                            std::vector<float>(this->cols_));
  for (uint64_t i = 0; i < this->rows_; i++) {
    for (uint64_t j = 0; j < this->cols_; j++) {
      arr_float[i][j] = static_cast<float>(this->arr_[i][j]);
    }
  }
  M_float.setArray(arr_float);
  return M_float;
}

template <typename T>
Matrix<T> Matrix<T>::subMatrix(const uint64_t& row_to_be_deleted,
                               const uint64_t& col_to_be_deleted) {
  if (row_to_be_deleted > this->rows_ || col_to_be_deleted > this->cols_) {
    throw std::invalid_argument("Index out of range\n");
  }

  if (this->rows_ == (T)1 || this->cols_ == (T)1) {
    throw std::invalid_argument("Size of matrix cannot be reduced further\n");
  }

  Matrix<T> sub_matrix(this->rows_ - 1, this->cols_ - 1);
  for (uint64_t i = 0; i < this->rows_ - 1; i++) {
    for (uint64_t j = 0; j < this->cols_ - 1; j++) {
      if (i < row_to_be_deleted && j < col_to_be_deleted)
        sub_matrix.arr_[i][j] = this->arr_[i][j];
      else if (i > row_to_be_deleted && j < col_to_be_deleted)
        sub_matrix.arr_[i][j] = this->arr_[i - 1][j];
      else if (i < row_to_be_deleted && j > col_to_be_deleted)
        sub_matrix.arr_[i][j] = this->arr_[i][j - 1];
      else if (i > row_to_be_deleted && j > col_to_be_deleted)
        sub_matrix.arr_[i][j] = this->arr_[i - 1][j - 1];
    }
  }
  return sub_matrix;
}

}  // namespace LinearAlgebra
