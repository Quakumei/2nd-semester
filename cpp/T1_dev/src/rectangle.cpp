#include "rectangle.hpp"

double tampio::Rectangle::getArea() const
{
    return frame_.height * frame_.width;
}
void tampio::Rectangle::scaleParameters(const point_t& center, double factor)
{
    a_ = center + (center - a_) * factor;
    b_ = center + (center - b_) * factor;
}
tampio::Rectangle::Rectangle(
        const point_t &a,
        const point_t &b) :
    a_(a),
    b_(b)
{}
