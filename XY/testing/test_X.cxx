
// Standard library:
#include <iostream>
#include <fstream>

/// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// Ourselves:
#include <XY/config.hpp>

#if BSTCUD_WITH_EOS == 1
#include <eos/portable_oarchive.hpp>
#include <eos/portable_iarchive.hpp>
#endif

// Ourselves:
#include <XY/X.hpp>

int main(void)
{
  {
    {
      std::ofstream file("test_X.xml");
      boost::archive::xml_oarchive oa(file);
      xy::X x(666);
      std::clog << "x = " << x << std::endl;
      oa & BOOST_SERIALIZATION_NVP(x);
    }

    {
      std::ifstream file("test_X.xml");
      boost::archive::xml_iarchive ia(file);
      xy::X x(0);
      ia & BOOST_SERIALIZATION_NVP(x);
      std::clog << "loaded x = " << x << std::endl;
    }
  }

#if BSTCUD_WITH_EOS == 1
  {
    {
      std::ofstream file("test_X.data");
      eos::portable_oarchive oa(file);
      xy::X x(666);
      std::clog << "x = " << x << std::endl;
      oa & BOOST_SERIALIZATION_NVP(x);
    }

    {
      std::ifstream file("test_X.data");
      eos::portable_iarchive ia(file);
      xy::X x(0);
      ia & BOOST_SERIALIZATION_NVP(x);
      std::clog << "loaded x = " << x << std::endl;
    }
  }
#endif

  return 0;
}
