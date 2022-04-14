#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "circle.hpp"

double tampio::Circle::getArea() const
{
  return M_PI * rad_ * rad_; // S = pi * R^2
}
void tampio::Circle::scaleParameters(const point_t& center, double factor)
{
  rad_ *= factor;
  center_ = center_ + (center_ - center) * factor;
}
tampio::Circle::Circle(double rad, const point_t& center) :
    rad_((rad > 0) ? rad : throw std::logic_error("Circle radius must be bigger than 1")),
    center_(center)
{
  frame_ = rectangle_t(rad * 2, rad * 2, center);
}
