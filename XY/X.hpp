#ifndef XY_X_HPP
#define XY_X_HPP

// Standard library:
#include <iostream>

// Third Party:
// - Boost:
#include <boost/cstdint.hpp>
#include <boost/serialization/access.hpp>

namespace xy {

  class X
  {
  public:
    X(int32_t val_ = 42);
    uint32_t val() const;
    friend std::ostream & operator<<(std::ostream & out_, const X & x_);

  private:
    uint32_t _val_;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar_, const unsigned int version_);
  };

}

#endif // XY_X_HPP
