#ifndef Z_C_HPP
#define Z_C_HPP

// This project
#include <XY/B.hpp>

namespace z {

  class C : public xy::B
  {
  public:
    C(int32_t val_ = 666, int32_t val2_ = 12, int32_t val3_ = 42);
    virtual ~C();
    uint32_t val3() const;
    friend std::ostream & operator<<(std::ostream & out_, const C & c_);
    virtual std::string to_string() const;

  private:
    uint32_t _val3_;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar_, const unsigned int version_);
  };

}

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(z::C, "z::C")

#endif // Z_C_HPP
