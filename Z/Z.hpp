#ifndef Z_Z_HPP
#define Z_Z_HPP

// Standard library:
#include <iostream>

// This project:
#include <XY/X.hpp>
#include <XY/Y.hpp>

namespace z {

  class Z
  {
  public:
    Z(const xy::Y & y_, const xy::X & x_);
    const xy::Y & y() const;
    const xy::X & x() const;
    friend std::ostream & operator<<(std::ostream & out_, const Z & z_);

  private:
    xy::Y _y_;
    xy::X _x_;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar_, const unsigned int version_);
  };

}

#endif // Z_Z_HPP
