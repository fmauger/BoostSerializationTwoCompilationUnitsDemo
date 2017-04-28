#ifndef PLUGIN_P_SERIAL_IPP
#define PLUGIN_P_SERIAL_IPP

// Ourselves:
#include <Plugin/P.hpp>

// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/base_object.hpp>

namespace plugin {

  template <class Archive>
  void P::serialize(Archive & ar_, const unsigned int version_)
  {
    ar_ & boost::serialization::make_nvp("xy__A", boost::serialization::base_object<xy::A>(*this));
    ar_ & boost::serialization::make_nvp("val2", _val2_);
    return;
  }

}

#endif // PLUGIN_P_SERIAL_IPP
