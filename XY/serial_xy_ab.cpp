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
#include <XY/config.hpp>

#if BSTCUD_WITH_EOS == 1
#include <eos/portable_iarchive.hpp>
#include <eos/portable_oarchive.hpp>
#endif // BSTCUD_WITH_EOS

#include <XY/X-serial.hpp>
#include <XY/Y-serial.hpp>
#include <XY/A-serial.hpp>
#include <XY/B-serial.hpp>

// Instantiate serialize methods for all supported archives:
template void xy::X::serialize(boost::archive::polymorphic_iarchive &, const unsigned int);
template void xy::X::serialize(boost::archive::polymorphic_oarchive &, const unsigned int);
template void xy::X::serialize(boost::archive::text_iarchive &, const unsigned int);
template void xy::X::serialize(boost::archive::text_oarchive &, const unsigned int);
template void xy::X::serialize(boost::archive::xml_iarchive &, const unsigned int);
template void xy::X::serialize(boost::archive::xml_oarchive &, const unsigned int);
#if BSTCUD_WITH_EOS == 1
template void xy::X::serialize(eos::portable_iarchive &, const unsigned int);
template void xy::X::serialize(eos::portable_oarchive &, const unsigned int);
#endif // BSTCUD_WITH_EOS

template void xy::Y::serialize(boost::archive::polymorphic_iarchive &, const unsigned int);
template void xy::Y::serialize(boost::archive::polymorphic_oarchive &, const unsigned int);
template void xy::Y::serialize(boost::archive::text_iarchive &, const unsigned int);
template void xy::Y::serialize(boost::archive::text_oarchive &, const unsigned int);
template void xy::Y::serialize(boost::archive::xml_iarchive &, const unsigned int);
template void xy::Y::serialize(boost::archive::xml_oarchive &, const unsigned int);
#if BSTCUD_WITH_EOS == 1
template void xy::Y::serialize(eos::portable_iarchive &, const unsigned int);
template void xy::Y::serialize(eos::portable_oarchive &, const unsigned int);
#endif // BSTCUD_WITH_EOS

template void xy::A::serialize(boost::archive::polymorphic_iarchive &, const unsigned int);
template void xy::A::serialize(boost::archive::polymorphic_oarchive &, const unsigned int);
template void xy::A::serialize(boost::archive::text_iarchive &, const unsigned int);
template void xy::A::serialize(boost::archive::text_oarchive &, const unsigned int);
template void xy::A::serialize(boost::archive::xml_iarchive &, const unsigned int);
template void xy::A::serialize(boost::archive::xml_oarchive &, const unsigned int);
#if BSTCUD_WITH_EOS == 1
template void xy::A::serialize(eos::portable_iarchive &, const unsigned int);
template void xy::A::serialize(eos::portable_oarchive &, const unsigned int);
#endif // BSTCUD_WITH_EOS

template void xy::B::serialize(boost::archive::polymorphic_iarchive &, const unsigned int);
template void xy::B::serialize(boost::archive::polymorphic_oarchive &, const unsigned int);
template void xy::B::serialize(boost::archive::text_iarchive &, const unsigned int);
template void xy::B::serialize(boost::archive::text_oarchive &, const unsigned int);
template void xy::B::serialize(boost::archive::xml_iarchive &, const unsigned int);
template void xy::B::serialize(boost::archive::xml_oarchive &, const unsigned int);
#if BSTCUD_WITH_EOS == 1
template void xy::B::serialize(eos::portable_iarchive &, const unsigned int);
template void xy::B::serialize(eos::portable_oarchive &, const unsigned int);
#endif // BSTCUD_WITH_EOS
// Used after the inclusion of supported archives:
BOOST_CLASS_EXPORT_IMPLEMENT(xy::B)

// end
