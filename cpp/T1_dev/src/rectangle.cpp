#include <iostream>
#include <iomanip>

#include "rectangle.hpp"

double tampio::Rectangle::getArea() const
{
    double area = frame_.height * frame_.width;
    return (area >= 0) ? area : -area;
}
void tampio::Rectangle::scaleParameters(const point_t &center, double factor)
{
    a_ = center + (center - a_) * factor;
    b_ = center + (center - b_) * factor;
}
tampio::Rectangle::Rectangle(
    const point_t &a,
    const point_t &b) : a_(a),
                        b_(b)
{
    frame_ = rectangle_t(b.x - a.x, b.y - a.y, a + (b - a) / 2);
}
tampio::Rectangle::Rectangle(const rectangle_t &rect) : a_(rect.pos - point_t(rect.height / 2, rect.width / 2)),
                                                        b_(rect.pos + point_t(rect.height / 2, rect.width / 2))
{
    frame_ = rect;
}

std::ostream &tampio::operator<<(std::ostream &os, const tampio::Rectangle &obj)
{
    os.setf(std::ios::fixed);
    os.precision(1);
    os << obj.a_.x << " "
       << obj.a_.y << " "
       << obj.b_.x << " "
       << obj.b_.y;
    return os;
}
