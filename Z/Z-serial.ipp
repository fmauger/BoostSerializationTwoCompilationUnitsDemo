#ifndef Z_Z_SERIAL_IPP
#define Z_Z_SERIAL_IPP

// Ourselves:
#include <Z/Z.hpp>

// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>

namespace z {

  template <class Archive>
  void Z::serialize(Archive & ar_, const unsigned int version_)
  {
    ar_ & boost::serialization::make_nvp("y", _y_);
    ar_ & boost::serialization::make_nvp("x", _x_);
    return;
  }

}

#endif // Z_Z_SERIAL_IPP
