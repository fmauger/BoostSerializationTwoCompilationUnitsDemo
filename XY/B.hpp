#ifndef XY_B_HPP
#define XY_B_HPP

// Standard library:
#include <iostream>

// Third Party:
// - Boost:
#include <boost/cstdint.hpp>
#include <boost/serialization/access.hpp>

// This project
#include <XY/A.hpp>

namespace xy {

  class B : public A
  {
  public:
    B(int32_t val_ = 666, int32_t val2_ = 12);
    virtual ~B();
    uint32_t val2() const;
    friend std::ostream & operator<<(std::ostream & out_, const B & b_);
    virtual std::string to_string() const;

  private:
    uint32_t _val2_;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar_, const unsigned int version_);
  };

}

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(xy::B, "xy::B")

#endif // XY_B_HPP
