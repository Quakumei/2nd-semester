#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"

void tampio::Shape::move(double dx, double dy)
{
  move(getFrameRect().pos + point_t{dx, dy});
}

void tampio::Shape::scale(double factor)
{
  if (factor < 0)
  {
    throw std::logic_error("Scale factor must be positive.");
  }
  point_t center = getFrameRect().pos;
  scaleParameters(center, factor);
}

// tampio::rectangle_t tampio::Shape::getFrameRect() const
// {
//   return frame_;
// }

void tampio::Shape::printPoints(std::ostream &os) const
{
  os << Rectangle(getFrameRect());
}
