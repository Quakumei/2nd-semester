#include <stdexcept>
#include "circle.hpp"

double tampio::Circle::getArea() const
{
  return M_PI * rad_ * rad_;
}
void tampio::Circle::scaleParameters(const point_t &center, double factor)
{
  rad_ *= factor;
  center_ = center_ + (center_ - center) * factor;
}
tampio::Circle::Circle(double rad, const point_t &center) :
    center_(center)
{
  if (rad <= 0)
  {
    throw std::logic_error("Circle radius must be bigger than 0");
  }
  rad_ = rad;
  frame_ = rectangle_t{rad * 2, rad * 2, center};
}
