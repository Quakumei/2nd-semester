#ifndef IOFMTGUARD_HPP
#define IOFMTGUARD_HPP

#include <iostream>

namespace tampio
{
  class iofmtguard
  {
  public:
    iofmtguard(std::basic_ios< char >& s);
    ~iofmtguard();

  private:
    std::basic_ios< char >& s_;
    char fill_;
    std::basic_ios< char >::fmtflags fmt_;
  };
}
#endif
