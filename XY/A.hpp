#ifndef XY_A_HPP
#define XY_A_HPP

// Standard library:
#include <string>
#include <iostream>
#include <sstream>

// Third Party:
// - Boost:
#include <boost/cstdint.hpp>
#include <boost/serialization/access.hpp>

namespace xy {

  class A
  {
  public:
    A(int32_t val_ = 42);
    virtual ~A();
    uint32_t val() const;
    friend std::ostream & operator<<(std::ostream & out_, const A & a_);
    virtual std::string to_string() const;

  private:
    uint32_t _val_;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar_, const unsigned int version_);
  };

}

#endif // XY_A_HPP
