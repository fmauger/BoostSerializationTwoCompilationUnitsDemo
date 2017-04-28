// Ourselves:
#include <Plugin/Plugin.hpp>

// This project
#include <XY/B.hpp>
#include <Z/C.hpp>
#include <Plugin/P.hpp>

namespace plugin {

  Plugin::Plugin(const double prob_)
    : _prob_(prob_)
  {
  }

  Plugin::~Plugin()
  {
  }

  std::string Plugin::id() const
  {
    return std::string("plugin::Plugin");
  }

  xy::A * Plugin::create()
  {
    xy::A * obj = nullptr;
    double p = drand48();
    double p1 = 0.5 * _prob_;
    double p2 = _prob_;
    double p3 = 1.5 * _prob_;
    if (p < p1) {
      obj = new xy::B(42, 23);
    } else if (p < p2) {
      obj = new z::C(5, 6, 7);
    } else if (p < p3) {
      obj = new plugin::P(17, 15);
    } else {
      obj = new xy::A(234);
    }
    return obj;
  }

}
