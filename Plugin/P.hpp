#ifndef PLUGIN_P_HPP
#define PLUGIN_P_HPP

// This project
#include <XY/A.hpp>

namespace plugin {

  class P : public xy::A
  {
  public:
    P(int32_t val_ = 1024, int32_t val2_ = 2048);
    virtual ~P();
    uint32_t val2() const;
    friend std::ostream & operator<<(std::ostream & out_, const P & p_);
    virtual std::string to_string() const;

  private:
    uint32_t _val2_;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar_, const unsigned int version_);
  };

}

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(plugin::P, "plugin::P")

#endif // PLUGIN_P_HPP
