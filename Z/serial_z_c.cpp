/// Third Party:
// - Boost:
// Supported archives:
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

// XY:
#include <XY/config.hpp>

#if BSTCUD_WITH_EOS == 1
#include <eos/portable_iarchive.hpp>
#include <eos/portable_oarchive.hpp>
#endif // BSTCUD_WITH_EOS

// Ourselves:
#include <Z/Z-serial.hpp>
#include <Z/C-serial.hpp>

// Instantiate serialize methods for all supported archives:

template void z::Z::serialize(boost::archive::polymorphic_iarchive &, const unsigned int);
template void z::Z::serialize(boost::archive::polymorphic_oarchive &, const unsigned int);
template void z::Z::serialize(boost::archive::text_iarchive &, const unsigned int);
template void z::Z::serialize(boost::archive::text_oarchive &, const unsigned int);
template void z::Z::serialize(boost::archive::xml_iarchive &, const unsigned int);
template void z::Z::serialize(boost::archive::xml_oarchive &, const unsigned int);
#if BSTCUD_WITH_EOS == 1
template void z::Z::serialize(eos::portable_iarchive &, const unsigned int);
template void z::Z::serialize(eos::portable_oarchive &, const unsigned int);
#endif // BSTCUD_WITH_EOS

template void z::C::serialize(boost::archive::polymorphic_iarchive &, const unsigned int);
template void z::C::serialize(boost::archive::polymorphic_oarchive &, const unsigned int);
template void z::C::serialize(boost::archive::text_iarchive &, const unsigned int);
template void z::C::serialize(boost::archive::text_oarchive &, const unsigned int);
template void z::C::serialize(boost::archive::xml_iarchive &, const unsigned int);
template void z::C::serialize(boost::archive::xml_oarchive &, const unsigned int);
#if BSTCUD_WITH_EOS == 1
template void z::C::serialize(eos::portable_iarchive &, const unsigned int);
template void z::C::serialize(eos::portable_oarchive &, const unsigned int);
#endif // BSTCUD_WITH_EOS

// Used after the inclusion of supported archives:
BOOST_CLASS_EXPORT_IMPLEMENT(z::C)

// end
