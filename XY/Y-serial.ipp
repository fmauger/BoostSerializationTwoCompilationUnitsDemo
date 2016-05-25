#ifndef XY_Y_SERIAL_IPP
#define XY_Y_SERIAL_IPP

// Ourselves:
#include <XY/Y.hpp>

// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>

namespace xy {

  template <class Archive>
  void Y::serialize(Archive & ar_, const unsigned int version_)
  {
    ar_ & boost::serialization::make_nvp("x", _x_);
    return;
  }

}

#endif // XY_Y_SERIAL_IPP
