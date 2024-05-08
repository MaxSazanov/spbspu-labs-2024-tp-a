#include "Polygon.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include "Point.hpp"
#include "PolygonFunctors.hpp"

std::istream& sazanov::operator>>(std::istream& in, Polygon& polygon)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  std::size_t vertexes = 0;
  in >> vertexes;
  if (vertexes < 3)
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  std::vector< Point > temp;
  temp.reserve(vertexes);
  for (std::size_t i = 0; in && i < vertexes; ++i)
  {
    Point p{ 0, 0 };
    if (in.peek() == '\n')
    {
      in.setstate(std::ios::failbit);
    }
    if (in >> p)
    {
      temp.push_back(p);
    }
  }
  if ((in.peek() != '\n' && !in.eof()) || temp.size() != vertexes)
  {
    in.setstate(std::ios::failbit);
  }
  else
  {
    polygon.points = temp;
  }
  return in;
}

std::ostream& sazanov::operator<<(std::ostream& out, const Polygon& polygon)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  using output_it_t = std::ostream_iterator< Point >;
  std::copy(
    polygon.points.cbegin(),
    polygon.points.cend(),
    output_it_t{out, " "}
  );
  return out;
}

double sazanov::Polygon::getArea() const
{
  using namespace std::placeholders;
  auto accumulateAreaPart = std::bind(AccumulatePolygonAreaPart{points[1]}, _1, _2, points[0]);
  return std::accumulate(points.begin(), points.end(), 0.0, accumulateAreaPart) / 2;
}

bool sazanov::Polygon::operator==(const sazanov::Polygon& rhs) const
{
  if (points.size() != rhs.points.size())
  {
    return false;
  }
  return std::equal(this->points.begin(), this->points.end(), rhs.points.begin());
}