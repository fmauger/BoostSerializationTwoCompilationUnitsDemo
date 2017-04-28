// Standard library:
#include <memory>
#include <iostream>

// This project
#include <XY/PluginSupport.hpp>
#include <Plugin/Plugin.hpp>

namespace plugin {

  struct init_lib
  {
    init_lib()
    {
      std::clog << "[info] init_lib::init_lib: Instantiate libPlugin system Plugin..." << std::endl;
      _plugin_.reset(new Plugin(0.5));
      std::clog << "[info] init_lib::init_lib: Address : " << _plugin_.get() << std::endl;
      std::clog << "[info] init_lib::init_lib: Register system Plugin..." << std::endl;
      xy::plugin_deck::instance().set_current_plugin(_plugin_.get());
      xy::plugin_deck::instance().print(std::clog);
      return;
    }

    ~init_lib()
    {
      std::clog << "[info] init_lib::~init_lib: Deregister system Plugin..." << std::endl;
      xy::plugin_deck::instance().reset_current_plugin(_plugin_.get());
      std::clog << "[info] init_lib::~init_lib: Destroy system Plugin..." << std::endl;
      _plugin_.reset();
      return;
    }

    xy::BasePlugin * plugin()
    {
      return _plugin_.get();
    }

  private:

    std::unique_ptr<Plugin> _plugin_;

    static init_lib _initLib_; // Singleton

  };

  init_lib init_lib::_initLib_;

}
