
#include "rectangle.hpp"

double tampio::Rectangle::getArea() const
{
  rectangle_t frame = getFrameRect();
  return frame.height * frame.width;
}
void tampio::Rectangle::scaleParameters(const point_t &center, double factor)
{
  a_ = a_ + (a_ - center) * factor;
  b_ = b_ + (b_ - center) * factor;
}
tampio::Rectangle::Rectangle(const point_t &a, const point_t &b)
{
  if (b.x - a.x < 0 && b.y - a.y < 0)
  {
    throw std::logic_error("Rectangle edges must be placed correctly.");
  }
  a_ = a;
  b_ = b;
}

tampio::Rectangle::Rectangle(const rectangle_t &rect) :
    a_(rect.pos - point_t{rect.width / 2, rect.height / 2}),
    b_(rect.pos + point_t{rect.width / 2, rect.height / 2})
{}

std::ostream &tampio::operator<<(std::ostream &os, const tampio::Rectangle &obj)
{
  os << obj.a_.x << " " << obj.a_.y << " " << obj.b_.x << " " << obj.b_.y;
  return os;
}

tampio::rectangle_t tampio::Rectangle::getFrameRect() const
{
  return rectangle_t{b_.x - a_.x, b_.y - a_.y, a_ + (b_ - a_) / 2};
}

void tampio::Rectangle::move(const point_t &p)
{
  *this = Rectangle(rectangle_t{b_.x - a_.x, b_.y - b_.y, p});
}
