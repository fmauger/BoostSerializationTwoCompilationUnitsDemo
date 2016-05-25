
// Standard library:
#include <iostream>
#include <fstream>

/// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>

// Ourselves:
#include <Z/Z.hpp>
#include <Z/Z-serial.ipp>

int main(void)
{
  std::ofstream file("test_Z.xml");
  boost::archive::xml_oarchive oa(file);
  xy::X x(666);
  xy::Y y(xy::X(12));
  z::Z  z(y, x);
  std::clog << "z = " << z << std::endl;
  oa & BOOST_SERIALIZATION_NVP(z);
  return 0;
}
