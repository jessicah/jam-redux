#include <bitset>
#include <cassert>
#include <ostream>

#pragma once

template<typename T>
struct FlagSet
{
  FlagSet() = default;
  FlagSet(const FlagSet &o) : bitset(o.bitset) {}

  FlagSet &operator|=(const T &val)
  {
    set_true(val);
    return *this;
  }

  FlagSet &operator&=(const T &val)
  {
    bool tmp = bitset[static_cast<unsigned>(val)] ? true : false;
    bitset.reset();
    bitset[static_cast<unsigned>(val)] = tmp;
    return *this;
  }

  FlagSet &operator|=(const FlagSet &o)
  {
    bitset |= o.bitset;
    return *this;
  }

  FlagSet &operator&=(const FlagSet &o)
  {
    bitset &= o.bitset;
    return *this;
  }

  FlagSet &operator=(const FlagSet &o)
  {
    bitset = o.bitset;
    return *this;
  }

  FlagSet operator&(const T&val)
  {
    FlagSet ret(*this);
    ret &= val;

    assert(ret.bitset.count() <= 1);
    return ret;
  }

  FlagSet operator&(const FlagSet &val)
  {
    FlagSet ret(*this);
    ret.bitset &= val.bitset;

    return ret;
  }

  FlagSet operator|(const T&val)
  {
    FlagSet ret(*this);
    ret |= val;

    assert(ret.bitset.count() >= 1);
    return ret;
  }

  FlagSet operator|(const FlagSet &val)
  {
    FlagSet ret(*this);
    ret.bitset |= val.bitset;

    return ret;
  }

  FlagSet operator~()
  {
    FlagSet cp(*this);
    cp.bitset.flip();

    return cp;
  }

  operator bool() const
  {
    return bitset.any();
  }

  bool operator==(const FlagSet &o) const
  {
    return bitset == o.bitset;
  }

  std::size_t size() const
  {
    return bitset.size();
  }

  std::size_t count() const
  {
    return bitset.count();
  }

  FlagSet &set()
  {
    bitset.set();
    return *this;
  }

  FlagSet &reset()
  {
    bitset.reset();
    return *this;
  }

  FlagSet &flip()
  {
    bitset.flip();
    return *this;
  }

  FlagSet &set(const T &val, bool value = true)
  {
    bitset.set(static_cast<unsigned>(val), value);
    return *this;
  }

  FlagSet &reset(const T&val)
  {
    bitset.reset(static_cast<unsigned>(val));
    return *this;
  }

  FlagSet &flip(const T &val)
  {
    bitset.flip(static_cast<unsigned>(val));
    return *this;
  }

  bool operator[](const T&val)
  {
    return bitset[static_cast<unsigned>(val)];
  }

  friend std::ostream& operator<<(std::ostream& stream, const FlagSet& me)
  {
    return stream << me.bitset;
  }

private:
  std::bitset<32> bitset;

  void set_true(const T&val)
  {
    bitset[static_cast<unsigned>(val)] = 1;
  }

};

template<typename T>
std::enable_if_t<std::is_enum<T>::value, FlagSet<T>>
operator|(const T &lhs, const T &rhs)
{
  FlagSet<T> bs;
  bs |= lhs;
  bs |= rhs;

  return bs;
}
