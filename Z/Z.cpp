// Ourselves:
#include <Z/Z.hpp>

namespace z {

  Z::Z(const xy::Y & y_, const xy::X & x_) : _y_(y_), _x_(x_)
  {
  }

  const xy::Y & Z::y() const
  {
    return _y_;
  }

  const xy::X & Z::x() const
  {
    return _x_;
  }

  std::ostream & operator<<(std::ostream & out_, const Z & z_)
  {
    out_ << "{y=" << z_.y() << ";x=" << z_.x() << '}';
    return out_;
  }

}
