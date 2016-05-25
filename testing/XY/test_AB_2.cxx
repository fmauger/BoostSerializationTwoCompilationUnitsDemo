
// Standard library:
#include <iostream>
#include <fstream>

/// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// Ourselves:
#include <XY/A.hpp>
#include <XY/B.hpp>

int main(void)
{
  {
    std::clog << "Serializing..." << std::endl;
    std::ofstream file("test_AB_2.xml");
    boost::archive::xml_oarchive oa(file);
    xy::A * a_ptr  = new xy::A(1);
    xy::A * b_ptr  = new xy::B(2, 3);
    xy::A * b2_ptr = new xy::B(4, 5);
    std::clog << "a  = " << a_ptr->to_string() << std::endl;
    std::clog << "b  = " << b_ptr->to_string() << std::endl;
    std::clog << "b2 = " << b2_ptr->to_string() << std::endl;
    oa & BOOST_SERIALIZATION_NVP(a_ptr);
    oa & BOOST_SERIALIZATION_NVP(b_ptr);
    oa & BOOST_SERIALIZATION_NVP(b2_ptr);
    delete a_ptr;
    delete b_ptr;
    delete b2_ptr;
  }

  {
    std::clog << "Deserializing..." << std::endl;
    std::ifstream file("test_AB_2.xml");
    boost::archive::xml_iarchive ia(file);
    xy::A * a_ptr  = 0;
    xy::A * b_ptr  = 0;
    xy::A * b2_ptr = 0;
    ia & BOOST_SERIALIZATION_NVP(a_ptr);
    ia & BOOST_SERIALIZATION_NVP(b_ptr);
    ia & BOOST_SERIALIZATION_NVP(b2_ptr);
    std::clog << "a  = " << a_ptr->to_string() << std::endl;
    std::clog << "b  = " << b_ptr->to_string() << std::endl;
    std::clog << "b2 = " << b2_ptr->to_string() << std::endl;
    delete a_ptr;
    delete b_ptr;
    delete b2_ptr;
  }

  return 0;
}
