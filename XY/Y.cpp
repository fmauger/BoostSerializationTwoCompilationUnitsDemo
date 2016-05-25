// Ourselves:
#include <XY/Y.hpp>

namespace xy {

  Y::Y(const X & x_) : _x_(x_)
  {
  }

  const X & Y::x() const
  {
    return _x_;
  }

  std::ostream & operator<<(std::ostream & out_, const Y & y_)
  {
    out_ << "{x=" << y_._x_ << '}';
    return out_;
  }

}
