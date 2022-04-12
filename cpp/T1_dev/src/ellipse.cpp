#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

#include "ellipse.hpp"

double tampio::Ellipse::getArea() const
{
    return M_PI * radx_ * rady_; // S = pi * ry * rx;
}
void tampio::Ellipse::scaleParameters(const point_t &center, double factor)
{
    radx_ *= factor;
    rady_ *= factor;
    center_ = center_ + (center_ - center) * factor;
}
tampio::Ellipse::Ellipse(double radx, double rady, const point_t&  center) :
                        radx_((radx > 0) ? radx : throw std::logic_error("Ellipse radiuses must be bigger than 1")),
                        rady_((rady > 0) ? rady : throw std::logic_error("Ellipse radiuses must be bigger than 1")),
                        center_(center)
{
    frame_ = rectangle_t(radx*2, rady*2, center);
}


