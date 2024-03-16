#include "dataStruct.hpp"

bool ravinskij::DataStruct::operator<(const DataStruct& rhs) const
{
  if (key1 == rhs.key1)
  {
    if (key2 == rhs.key2)
    {
      return key3.size() < rhs.key3.size();
    }
    return key2 < rhs.key2;
  }
  return key1 < rhs.key1;
}

bool ravinskij::DataStruct::operator>(const DataStruct& rhs) const
{
  return rhs < *this;
}

bool ravinskij::DataStruct::operator<=(const DataStruct& rhs) const
{
  return !(*this > rhs);
}

bool ravinskij::DataStruct::operator>=(const DataStruct& rhs) const
{
  return !(*this < rhs);
}

bool ravinskij::DataStruct::operator==(const DataStruct& rhs) const
{
  return !(*this < rhs) && !(*this > rhs);
}

bool ravinskij::DataStruct::operator!=(const DataStruct& rhs) const
{
  return !(*this == rhs);
}

std::istream& ravinskij::operator>>(std::istream& in, DataStruct& data)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }

  DataStruct temp;
  in >> temp.key1 >> temp.key2 >> temp.key3;
  if (in)
  {
    data = temp;
  }
  return in;
}

std::ostream& ravinskij::operator<<(std::ostream& out, const DataStruct& data)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  out << data.key1 << ' ' << data.key2 << ' ' << data.key3;
  return out;
}
