// Ourselves:
#include <XY/X.hpp>

namespace xy {

  X::X(int32_t val_) : _val_(val_)
  {
  }

  uint32_t X::val() const
  {
    return _val_;
  }

  std::ostream & operator<<(std::ostream & out_, const X & x_)
  {
    out_ << "{val=" << x_._val_ << '}';
    return out_;
  }

}
