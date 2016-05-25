// Ourselves:
#include <XY/A.hpp>

namespace xy {

  A::A(int32_t val_) : _val_(val_)
  {
  }

  A::~A()
  {
  }

  uint32_t A::val() const
  {
    return _val_;
  }

  std::ostream & operator<<(std::ostream & out_, const A & a_)
  {
    out_ << "{val=" << a_._val_ << '}';
    return out_;
  }

  // virtual
  std::string A::to_string() const
  {
    std::ostringstream repr;
    repr << *this;
    return repr.str();
  }

}
