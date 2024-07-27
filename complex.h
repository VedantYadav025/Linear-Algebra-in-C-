#include <cmath>
#include <istream>
#include <ostream>
#include <utility>
#include <vector>
// how to check if a variable is not complex
template <typename T> class complex {
public:
  complex();
  complex(const T &real, const T &img);
  template <typename P>
  friend std::ostream &operator<<(std::ostream &output, const complex<P> &num);
  template <typename P>
  friend std::istream &operator>>(std::istream &input, const complex<P> &num);
  complex operator+(const complex &c) const;
  complex operator-(const complex &c) const;
  complex conjugate() const;
  double mod() const;
  complex operator*(const complex &c) const;
  complex operator=(const std::pair<T, T> &c);
  bool operator==(const complex &c) const;
  friend complex<double>
  randn(const double &mean,
        const double &var); // returns a complex number drawn from a gaussian

private:
  T real_, img_;
  complex<double> inverse() const;
};

template <typename T> complex<T>::complex() : real_(0), img_(0) { ; }

template <typename T>
complex<T>::complex(const T &real, const T &img) : real_(real), img_(img) {
  ;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const complex<T> &num) {
  if (num.img_ > 0)
    output << num.real_ << "+" << num.img_ << "j";
  else if (num.img_ == 0)
    output << num.real_;
  else
    output << num.real_ << "-" << num.img_ << "j";
  return output;
}

template <typename T>
std::istream &operator>>(std::istream &input, const complex<T> &num) {
  T real, img;
  input >> real;
  input >> img;
  return img;
}

template <typename T>
complex<T> complex<T>::operator+(const complex<T> &c) const {
  complex<T> add(this->real_ + c.real_, this->img_ + c.img_);
  return add;
}

template <typename T>
complex<T> complex<T>::operator-(const complex<T> &c) const {
  complex<T> add(this->real_ - c.real_, this->img_ - c.img_);
  return add;
}

template <typename T> complex<T> complex<T>::conjugate() const {
  complex<T> conj(this->real_, -this->img_);
  return conj;
}

template <typename T> double complex<T>::mod() const {
  double mod = std::sqrt(this->real_ * this->real_ + this->img_ * this->img_);
  return mod;
}

template <typename T>
complex<T> complex<T>::operator*(const complex<T> &c) const {
  T real = this->real_ * c.real_ - this->img_ * c.img_;
  T img = this->real_ * c.img_ + this->img_ * c.real_;
  complex<T> mult(real, img);
  return mult;
}

template <typename T>
complex<T> complex<T>::operator=(const std::pair<T, T> &c) {
  complex<T> num(c.first, c.second);
  return num;
}

template <typename T> bool complex<T>::operator==(const complex<T> &c) const {
  return (this->real_ == c.real_ && this->img_ == c.img_);
}
template <typename T> complex<double> complex<T>::inverse() const {
  double mod = this->mod();
  double inverse_mod = 1 / mod;
  complex<double> inverse(this->real_ / mod, -this->img_ / mod);
  return inverse;
}
