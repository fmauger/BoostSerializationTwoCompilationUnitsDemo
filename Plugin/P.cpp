// Ourselves:
#include <Plugin/P.hpp>

namespace plugin {

  P::P(int32_t val_, int32_t val2_)
    :xy:: A(val_), _val2_(val2_)
  {
  }

  P::~P()
  {
  }

  uint32_t P::val2() const
  {
    return _val2_;
  }

  std::ostream & operator<<(std::ostream & out_, const P & p_)
  {
    out_ << "plugin::P@{val=" << p_.val()
         << ";val2=" << p_.val2()
         << '}';
    return out_;
  }

  // virtual
  std::string P::to_string() const
  {
    std::ostringstream repr;
    repr << *this;
    return repr.str();
  }

}
