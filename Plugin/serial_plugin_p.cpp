/// Third Party:
// - Boost:
// Supported archives:
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

// Ourselves:
#include <Plugin/P-serial.hpp>

// Instantiate serialize methods for all supported archives:
template void plugin::P::serialize(boost::archive::polymorphic_iarchive &, const unsigned int);
template void plugin::P::serialize(boost::archive::polymorphic_oarchive &, const unsigned int);
template void plugin::P::serialize(boost::archive::text_iarchive &, const unsigned int);
template void plugin::P::serialize(boost::archive::text_oarchive &, const unsigned int);
template void plugin::P::serialize(boost::archive::xml_iarchive &, const unsigned int);
template void plugin::P::serialize(boost::archive::xml_oarchive &, const unsigned int);

// Used after the inclusion of supported archives:
BOOST_CLASS_EXPORT_IMPLEMENT(plugin::P)

// end