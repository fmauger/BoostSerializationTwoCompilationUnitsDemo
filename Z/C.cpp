// Ourselves:
#include <Z/C.hpp>

namespace z {

  C::C(int32_t val_, int32_t val2_, int32_t val3_)
    :xy:: B(val_, val2_), _val3_(val3_)
  {
  }

  C::~C()
  {
  }

  uint32_t C::val3() const
  {
    return _val3_;
  }

  std::ostream & operator<<(std::ostream & out_, const C & c_)
  {
    out_ << "{val=" << c_.val()
         << ";val2=" << c_.val2()
         << ";val3=" << c_.val3()
         << '}';
    return out_;
  }

  // virtual
  std::string C::to_string() const
  {
    std::ostringstream repr;
    repr << *this;
    return repr.str();
  }

}
