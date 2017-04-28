
// Standard library:
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <dlfcn.h>

/// Third Party:
// - Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// This project
#include <XY/PluginSupport.hpp>

int main(void)
{
  xy::plugin_deck & sysPlugDeck = xy::plugin_deck::instance();
  sysPlugDeck.print(std::clog);

  std::clog << "Loading libPlugin DLL..." << std::endl;
  void * libPluginHandle = dlopen("libPlugin.so", RTLD_NOW); //RTLD_LAZY);
  sysPlugDeck.print(std::clog);

  xy::BasePlugin * plugFactory = nullptr;
  if (sysPlugDeck.has_current_plugin()) {
    plugFactory = &sysPlugDeck.current_plugin();
    std::clog << "Plugin factory @" << plugFactory << std::endl;
  }

  std::string filename = "test_Plugin.xml";

  typedef std::shared_ptr<xy::A> xy_a_sp;
  {
    std::vector<xy_a_sp> coll;
    std::clog << "Serializing..." << std::endl;
    std::ofstream file(filename.c_str());
    boost::archive::xml_oarchive oa(file);
    for (std::size_t i = 0; i < 20; i++) {
      // std::clog << " + Object #" << i << std::endl;
      xy_a_sp ptr(plugFactory->create());
      coll.push_back(ptr);
      std::clog << "back = " << coll.back()->to_string() << std::endl;
    }
    oa & BOOST_SERIALIZATION_NVP(coll);
  }

  {
    std::vector<xy_a_sp> coll;
    std::clog << "Deserializing..." << std::endl;
    std::ifstream file(filename.c_str());
    boost::archive::xml_iarchive ia(file);
    ia & BOOST_SERIALIZATION_NVP(coll);
    for (std::size_t i = 0; i < coll.size(); i++) {
      std::clog << "loaded back = " << coll[i]->to_string() << std::endl;
    }
  }

  std::clog << "Closing libPlugin DLL..." << std::endl;
  dlclose (libPluginHandle);
  return 0;
}
