
// Standard library:
#include <iostream>
#include <fstream>

/// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// Ourselves:
#include <Z/Z.hpp>

int main(void)
{
  {
    std::ofstream file("test_Z.xml");
    boost::archive::xml_oarchive oa(file);
    xy::X x(666);
    xy::Y y(xy::X(12));
    z::Z  z(y, x);
    std::clog << "z = " << z << std::endl;
    oa & BOOST_SERIALIZATION_NVP(z);
  }

  {
    std::ifstream file("test_Z.xml");
    boost::archive::xml_iarchive ia(file);
    xy::X x(0);
    xy::Y y(xy::X(0));
    z::Z  z(y, x);
    ia & BOOST_SERIALIZATION_NVP(z);
    std::clog << "loaded z = " << z << std::endl;
  }

  return 0;
}
