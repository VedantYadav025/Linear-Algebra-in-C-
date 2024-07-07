#include <ostream>
template <typename T> class complex {
public:
  complex();
  complex(const T &real, const T &img);
  template <typename P>
  friend std::ostream &operator<<(std::ostream &output, const complex<P> &num);

private:
  T real_, img_;
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