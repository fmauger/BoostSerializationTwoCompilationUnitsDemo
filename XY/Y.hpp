#ifndef XY_Y_HPP
#define XY_Y_HPP

// Standard library:
#include <iostream>

// Third Party:
// - Boost:
#include <boost/cstdint.hpp>
#include <boost/serialization/access.hpp>

// This project:
#include <XY/X.hpp>

namespace xy {

  class Y
  {
  public:
    Y(const X  & x_);
    const X & x() const;
    friend std::ostream & operator<<(std::ostream & out_, const Y & y_);

  private:
    X _x_;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar_, const unsigned int version_);
  };

}

#endif // XY_Y_HPP
