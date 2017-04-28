// Ourselves:
#include <XY/PluginSupport.hpp>

// Standard library:
#include <stdexcept>

namespace xy {

  void plugin_deck::set_current_plugin(BasePlugin * plug_)
  {
    _current_ = plug_;
  }

  void plugin_deck::reset_current_plugin(BasePlugin * plug_)
  {
    if (plug_ == nullptr || _current_ == plug_) {
      _current_ = nullptr;
    }
  }

  bool plugin_deck::has_current_plugin() const
  {
    return _current_ != nullptr;
  }

  BasePlugin & plugin_deck::current_plugin()
  {
    if (! has_current_plugin()) {
      throw std::logic_error("No plugin factory in the deck!");
    }
    return *_current_;
  }

  void plugin_deck::print(std::ostream & out_) const
  {
    out_ << "plugin_deck: " << std::endl;
    out_ << "+-- Current plugin: ";
    if (_current_ == nullptr) {
      out_ << "<none>";
    } else {
      out_ << _current_;
    }
    out_ << std::endl;
  }

  // static
  plugin_deck & plugin_deck::_instance_priv_()
  {
    static std::unique_ptr<plugin_deck> _deck;
    if (!_deck) {
      _deck.reset(new plugin_deck);
    }
    return *_deck.get();
  }

  // static
  plugin_deck & plugin_deck::instance()
  {
    return plugin_deck::_instance_priv_();
  }

  BasePlugin::BasePlugin()
  {
  }

  BasePlugin::~BasePlugin()
  {
  }

}
