// Ourselves:
#include <XY/B.hpp>

namespace xy {

  B::B(int32_t val_, int32_t val2_) : A(val_), _val2_(val2_)
  {
  }

  B::~B()
  {
  }

  uint32_t B::val2() const
  {
    return _val2_;
  }

  std::ostream & operator<<(std::ostream & out_, const B & b_)
  {
    out_ << "{val=" << b_.val() << ";val2=" << b_.val2() << '}';
    return out_;
  }

  // virtual
  std::string B::to_string() const
  {
    std::ostringstream repr;
    repr << *this;
    return repr.str();
  }

}
