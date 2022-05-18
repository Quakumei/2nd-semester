#include <bitset>
#include <iomanip>
#include "DataStruct.hpp"
#include "iofmtguard.hpp"

std::istream& tampio::operator>>(std::istream& in, DelimeterIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    // std::clog << "bad sentry delimiter\n";
    return in;
  }
  char c = '0';
  in >> c;
  if (in && (c != dest.exp))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::istream& tampio::operator>>(std::istream& in, LongLongIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    // std::clog << "bad sentry llio\n";
    return in;
  }
  long long number = 0;
  char l1 = '0', l2 = '0';
  in >> number;
  in >> l1 >> l2;
  dest.ref = number;
  if ((l1 != l2) && !(l1 == 'l' || l1 == 'L'))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::istream& tampio::operator>>(std::istream& in, UnsignedLongLongIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    // std::clog << "bad sentry ullio\n";
    return in;
  }
  std::string tmp = "";
  in >> DelimeterIO{'0'};
  char c = 0;
  in >> c;
  do
  {
    tmp += c;
  } while (in >> c && c != ':' && (c == '0' || c == '1'));
  in.putback(':');
  tmp.erase(0, 1);
  dest.ref = std::bitset< 32 >(tmp).to_ullong();
  return in;
}

std::istream& tampio::operator>>(std::istream& in, StringIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    // std::clog << "bad sentry stringio\n";
    return in;
  }
  return std::getline(in >> DelimeterIO{'"'}, dest.ref, '"');
}

std::istream& tampio::operator>>(std::istream& in, LabelIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    // std::clog << "bad sentry labelio\n";
    return in;
  }
  std::string data = "";
  if ((in >> data) && (data != dest.exp))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::istream& tampio::operator>>(std::istream& in, DataStruct& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    // std::clog << "bad sentry datastruct\n";
    return in;
  }
  DataStruct input;
  bool key1 = false, key2 = false, key3 = false;
  {
    using sep = DelimeterIO;
    // using label = LabelIO;
    using sll = LongLongIO;
    using ull = UnsignedLongLongIO;
    using str = StringIO;
    in >> sep{'('} >> sep{':'};
    for (int i = 0; i < 3; i++)
    {
      std::string label = "";
      in >> label;
      if (label == "key1")
      {
        in >> sll{input.key1} >> sep{':'};
        key1 = true;
      }
      else if (label == "key2")
      {
        in >> ull{input.key2} >> sep{':'};
        key2 = true;
      }
      else if (label == "key3")
      {
        in >> str{input.key3} >> sep{':'};
        key3 = true;
      }
    }
    in >> sep{')'};
  }
  if (in && key1 && key2 && key3)
  {
    dest = input;
  }
  return in;
}

bool tampio::DataStruct::operator<(const DataStruct& oth) const
{
  if (this->key1 == oth.key1)
  {
    if (this->key2 == oth.key2)
    {
      return this->key3.size() < oth.key3.size();
    }
    return this->key2 < oth.key2;
  }
  return this->key1 < oth.key1;
}

std::ostream& tampio::operator<<(std::ostream& out, const DataStruct& src)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  iofmtguard fmtguard(out);
  out << "(:key1 " << src.key1 << "ll";
  std::string binary = static_cast< std::bitset< 32 > >(src.key2).to_string();
  binary.erase(0, binary.find_first_not_of('0'));
  out << ":key2 0b" << binary;
  out << ":key3 \"" << src.key3 << "\":)";
  return out;
}
