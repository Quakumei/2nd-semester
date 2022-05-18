#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <iostream>

namespace tampio
{
  struct DataStruct
  {
    long long key1 = 0;
    unsigned long long key2 = 0;
    std::string key3 = "";
    bool operator<(const DataStruct&) const;
  };

  struct DelimeterIO
  {
    char exp;
  };
  struct LongLongIO
  {
    long long& ref;
  };
  struct UnsignedLongLongIO
  {
    unsigned long long& ref;
  };
  std::string serialize(unsigned long long);

  struct StringIO
  {
    std::string& ref;
  };
  struct LabelIO
  {
    std::string exp;
  };

  std::istream& operator>>(std::istream& in, DelimeterIO&& dest);
  std::istream& operator>>(std::istream& in, LongLongIO&& dest);
  std::istream& operator>>(std::istream& in, UnsignedLongLongIO&& dest);
  std::istream& operator>>(std::istream& in, StringIO&& dest);
  std::istream& operator>>(std::istream& in, LabelIO&& dest);
  std::istream& operator>>(std::istream& in, DataStruct& dest);
  std::ostream& operator<<(std::ostream& out, const DataStruct& dest);
}
#endif
