
// Standard library:
#include <iostream>
#include <fstream>

// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>

// Ourselves:
#include <XY/X.hpp>

int main(void)
{
  std::ofstream file("test_X_2.xml");
  boost::archive::xml_oarchive oa(file);
  xy::X x(666);
  std::clog << "x = " << x << std::endl;
  oa & BOOST_SERIALIZATION_NVP(x);
  return 0;
}
