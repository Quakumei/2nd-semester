#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"

void tampio::Shape::scaleFrame(const point_t &center, double factor)
{
  frame_.pos = center + (frame_.pos - center) * factor;
  frame_.height *= factor;
  frame_.width *= factor;
}

void tampio::Shape::scale(const point_t &center, double factor)
{
  if (factor < 0)
  {
    throw std::logic_error("Scale factor must be positive.");
  }
  scaleFrame(center, factor);
  scaleParameters(center, factor);
}

void tampio::Shape::printPoints(std::ostream &os) const
{
  tampio::Rectangle rectangle(getFrameRect());
  os << rectangle;
}

void tampio::Shape::move(double dx, double dy)
{
  move(getFrameRect().pos + point_t{dx, dy});
}