#ifndef Z_C_SERIAL_IPP
#define Z_C_SERIAL_IPP

// Ourselves:
#include <Z/C.hpp>

// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/base_object.hpp>

namespace z {

  template <class Archive>
  void C::serialize(Archive & ar_, const unsigned int version_)
  {
    ar_ & boost::serialization::make_nvp("xy__B", boost::serialization::base_object<xy::B>(*this));
    ar_ & boost::serialization::make_nvp("val3", _val3_);
    return;
  }

}

#endif // Z_C_SERIAL_IPP
