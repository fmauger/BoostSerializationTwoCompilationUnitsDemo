
// Standard library:
#include <iostream>
#include <fstream>

/// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// Ourselves:
#include <XY/X.hpp>

int main(void)
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
    xy::X x;
    ia & BOOST_SERIALIZATION_NVP(x);
    std::clog << "loaded x = " << x << std::endl;
  }

  return 0;
}
