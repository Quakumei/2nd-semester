#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"

void tampio::Shape::move(const tampio::point_t &new_pos)
{
  frame_.pos = new_pos;
}

void tampio::Shape::move(double dx, double dy)
{
  move(getFrameRect().pos + point_t{dx, dy});
}

void tampio::Shape::scaleFrame(const point_t &center, double factor)
{
  frame_.pos = center + (frame_.pos - center) * factor;
  frame_.height *= factor;
  frame_.width *= factor;
}

void tampio::Shape::scale(double factor)
{
  if (factor < 0)
  {
    throw std::logic_error("Scale factor must be positive.");
  }
  point_t center = getFrameRect().pos;
  scaleFrame(center, factor);
  scaleParameters(center, factor);
}

// tampio::rectangle_t tampio::Shape::getFrameRect() const
// {
//   return frame_;
// }

void tampio::Shape::printPoints(std::ostream &os) const
{
  tampio::Rectangle rectangle(frame_);
  os << rectangle;
}
