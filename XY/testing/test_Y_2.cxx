
// Standard library:
#include <iostream>
#include <fstream>

/// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// Ourselves:
#include <XY/Y.hpp>

int main(void)
{
  {
    std::ofstream file("test_Y_2.xml");
    boost::archive::xml_oarchive oa(file);
    xy::Y y(xy::X(43));
    std::clog << "y = " << y << std::endl;
    oa & BOOST_SERIALIZATION_NVP(y);
  }

  {
    std::ifstream file("test_Y_2.xml");
    boost::archive::xml_iarchive ia(file);
    xy::Y y(xy::X(0));
    ia & BOOST_SERIALIZATION_NVP(y);
    std::clog << "loaded y = " << y << std::endl;
  }

  return 0;
}
