#ifndef XY_A_SERIAL_IPP
#define XY_A_SERIAL_IPP

// Ourselves:
#include <XY/A.hpp>

// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>

namespace xy {

  template <class Archive>
  void A::serialize(Archive & ar_, const unsigned int version_)
  {
    ar_ & boost::serialization::make_nvp("val", _val_);
    return;
  }

}

#endif // XY_A_SERIAL_IPP
