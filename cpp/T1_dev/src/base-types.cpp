#include "base-types.hpp"

tampio::point_t::point_t(
        double x_new,
        double y_new) :
    x(x_new),
    y(y_new)
{}

tampio::point_t operator+(tampio::point_t const&  lhs,
        tampio::point_t const& rhs)
{
    return tampio::point_t(lhs.x + rhs.x, lhs.x + rhs.y);
}

tampio::point_t operator-(tampio::point_t const& lhs,
        tampio::point_t const& rhs)
{
    return tampio::point_t(lhs.x - rhs.x, lhs.x - rhs.y);
}

tampio::point_t operator*(tampio::point_t const &lhs,
        double factor)
{
    return tampio::point_t(lhs.x * factor, lhs.y * factor);
}

tampio::rectangle_t::rectangle_t() :
    width(0),
    height(0),
    pos(point_t(0,0))
{}
tampio::rectangle_t::rectangle_t(double w_new,
                    double h_new,
                    point_t pos_new) :
    width(w_new),
    height(h_new),
    pos(pos_new)
{}