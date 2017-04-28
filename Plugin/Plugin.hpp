#ifndef PLUGIN_HPP
#define PLUGIN_HPP

// Standard library:
#include <string>

// This project
#include <XY/A.hpp>
#include <XY/PluginSupport.hpp>

namespace plugin {

  class Plugin : public xy::BasePlugin
  {
  public:

    Plugin(const double prob_);
    virtual ~Plugin();
    virtual xy::A * create();
    virtual std::string id() const;

  private:
    double _prob_ = 0.5;

  };

}

#endif // PLUGIN_HPP
