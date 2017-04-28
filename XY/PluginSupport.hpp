#ifndef XY_PLUGIN_SUPPORT_HPP
#define XY_PLUGIN_SUPPORT_HPP

// Standard library:
#include <string>
#include <memory>
#include <iostream>

/// Third Party:
// - Boost:
#include <boost/utility.hpp>

// This project
#include <XY/A.hpp>

namespace xy {

  class BasePlugin;

  class plugin_deck
    : boost::noncopyable
  {
  public:

    void set_current_plugin(BasePlugin *);

    void reset_current_plugin(BasePlugin * = nullptr);

    bool has_current_plugin() const;

    BasePlugin & current_plugin();

    void print(std::ostream & out_) const;

    static plugin_deck & instance();

  private:

    static plugin_deck & _instance_priv_();

    BasePlugin * _current_ = nullptr;

  };

  class BasePlugin
  {
  public:
    BasePlugin();
    virtual ~BasePlugin();
    virtual xy::A * create() = 0;
    virtual std::string id() const = 0;
  };

}

#endif // XY_PLUGIN_SUPPORT_HPP
