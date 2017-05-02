
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
#include <XY/A.hpp>
#include <XY/B.hpp>

int main(void)
{
  {
    {
      std::ofstream file("test_AB.xml");
      boost::archive::xml_oarchive oa(file);
      xy::A * a_ptr  = new xy::A(1);
      xy::A * b_ptr  = new xy::B(2, 3);
      xy::A * b2_ptr = new xy::B(4, 5);
      std::clog << "a  = " << a_ptr->to_string() << std::endl;
      std::clog << "b  = " << b_ptr->to_string() << std::endl;
      std::clog << "b2 = " << b2_ptr->to_string() << std::endl;
      std::clog << "Serializing..." << std::endl;
      oa & BOOST_SERIALIZATION_NVP(a_ptr);
      oa & BOOST_SERIALIZATION_NVP(b_ptr);
      oa & BOOST_SERIALIZATION_NVP(b2_ptr);
      std::clog << "Done." << std::endl;
      delete a_ptr;
      delete b_ptr;
      delete b2_ptr;
    }

    {
      std::ifstream file("test_AB.xml");
      boost::archive::xml_iarchive ia(file);
      xy::A * a_ptr  = nullptr;
      xy::A * b_ptr  = nullptr;
      xy::A * b2_ptr = nullptr;
      std::clog << "Deserializing..." << std::endl;
      ia & BOOST_SERIALIZATION_NVP(a_ptr);
      ia & BOOST_SERIALIZATION_NVP(b_ptr);
      ia & BOOST_SERIALIZATION_NVP(b2_ptr);
      std::clog << "Done." << std::endl;
      std::clog << "loaded a  = " << a_ptr->to_string() << std::endl;
      std::clog << "loaded b  = " << b_ptr->to_string() << std::endl;
      std::clog << "loaded b2 = " << b2_ptr->to_string() << std::endl;
      delete a_ptr;
      delete b_ptr;
      delete b2_ptr;
    }
  }

#if BSTCUD_WITH_EOS == 1
  {
    {
      std::ofstream file("test_AB.data");
      eos::portable_oarchive oa(file);
      xy::A * a_ptr  = new xy::A(1);
      xy::A * b_ptr  = new xy::B(2, 3);
      xy::A * b2_ptr = new xy::B(4, 5);
      std::clog << "a  = " << a_ptr->to_string() << std::endl;
      std::clog << "b  = " << b_ptr->to_string() << std::endl;
      std::clog << "b2 = " << b2_ptr->to_string() << std::endl;
      std::clog << "Serializing..." << std::endl;
      oa & BOOST_SERIALIZATION_NVP(a_ptr);
      oa & BOOST_SERIALIZATION_NVP(b_ptr);
      oa & BOOST_SERIALIZATION_NVP(b2_ptr);
      std::clog << "Done." << std::endl;
      delete a_ptr;
      delete b_ptr;
      delete b2_ptr;
    }

    {
      std::ifstream file("test_AB.data");
      eos::portable_iarchive ia(file);
      xy::A * a_ptr  = nullptr;
      xy::A * b_ptr  = nullptr;
      xy::A * b2_ptr = nullptr;
      std::clog << "Deserializing..." << std::endl;
      ia & BOOST_SERIALIZATION_NVP(a_ptr);
      ia & BOOST_SERIALIZATION_NVP(b_ptr);
      ia & BOOST_SERIALIZATION_NVP(b2_ptr);
      std::clog << "Done." << std::endl;
      std::clog << "loaded a  = " << a_ptr->to_string() << std::endl;
      std::clog << "loaded b  = " << b_ptr->to_string() << std::endl;
      std::clog << "loaded b2 = " << b2_ptr->to_string() << std::endl;
      delete a_ptr;
      delete b_ptr;
      delete b2_ptr;
    }
  }
#endif

  return 0;
}
