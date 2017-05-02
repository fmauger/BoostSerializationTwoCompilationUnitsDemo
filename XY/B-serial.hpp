#ifndef XY_B_SERIAL_IPP
#define XY_B_SERIAL_IPP

// Ourselves:
#include <XY/B.hpp>

// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/base_object.hpp>

namespace xy {

  template <class Archive>
  void B::serialize(Archive & ar_, const unsigned int /* version_ */)
  {
    ar_ & boost::serialization::make_nvp("xy__A", boost::serialization::base_object<A>(*this));
    ar_ & boost::serialization::make_nvp("val2", _val2_);
    return;
  }

}

#endif // XY_B_SERIAL_IPP
