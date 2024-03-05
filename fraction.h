#include <algorithm>
class Fraction {
 private:
  long long int num_, den_;

 public:
  Fraction(const long long int& num, const long long int& den);
  Fraction operator+(const Fraction& f);
  Fraction operator-(const Fraction& f);
};

Fraction::Fraction(const long long int& num, const long long int& den) {
  this->num_ = num;
  this->den_ = den;
}

Fraction Fraction::operator+(const Fraction& f) {
  long long int num = this->num_ * f.den_ + this->den_ * f.num_;
  long long int den = this->den_ * f.den_;
  long long int div = gcd(num, den);
  num = num / div;
  den = den / div;
  Fraction addition(num, den);
  return addition;
}

Fraction Fraction::operator-(const Fraction& f) {
  long long int num = this->num_ * f.den_ - this->den_ * f.num_;
  long long int den = this->den_ * f.den_;
  long long int div = gcd(num, den);
  num = num / div;
  den = den / div;
  Fraction minus(num, den);
  return minus;
}

long long int gcd(const long long int& a, const long long int& b) {
  int result = std::min(a, b);
  while (result > 0) {
    if (a % result == 0 && b % result == 0) {
      break;
    }
    result--;
  }

  // Return gcd of a and b
  return result;
}