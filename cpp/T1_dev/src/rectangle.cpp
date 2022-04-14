#include <cmath>
#include <iomanip>
#include <iostream>

#include "rectangle.hpp"

double tampio::Rectangle::getArea() const
{
  return frame_.height * frame_.width; // S = a * b
}
void tampio::Rectangle::scaleParameters(const point_t &center, double factor)
{
  a_ = center + (center - a_) * factor;
  b_ = center + (center - b_) * factor;
}
tampio::Rectangle::Rectangle(const point_t &a, const point_t &b)
{
  if (b.x - a.x < 0 && b.y - a.y < 0)
  {
    throw std::logic_error("Rectangle edges must be placed correctly.");
  }
  a_ = a;
  b_ = b;
  frame_ = rectangle_t(b.x - a.x, b.y - a.y, a + (b - a) / 2);
}
tampio::Rectangle::Rectangle(const rectangle_t &rect) :
    a_(rect.pos - point_t(rect.height / 2, rect.width / 2)),
    b_(rect.pos + point_t(rect.height / 2, rect.width / 2))
{
  frame_ = rect;
}
