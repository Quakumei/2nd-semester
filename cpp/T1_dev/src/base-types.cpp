#include "base-types.hpp"

tampio::point_t::point_t(double x_new, double y_new) :
    x(x_new),
    y(y_new)
{}

tampio::point_t::point_t() :
    x(0),
    y(0)
{}

tampio::point_t tampio::operator+(tampio::point_t const &lhs, tampio::point_t const &rhs)
{
  return tampio::point_t(lhs.x + rhs.x, lhs.y + rhs.y);
}

tampio::point_t tampio::operator-(tampio::point_t const &lhs, tampio::point_t const &rhs)
{
  return tampio::point_t(lhs.x - rhs.x, lhs.y - rhs.y);
}

tampio::point_t tampio::operator*(tampio::point_t const &lhs, double factor)
{
  return tampio::point_t(lhs.x * factor, lhs.y * factor);
}

tampio::point_t tampio::operator/(tampio::point_t const &lhs, double factor)
{
  return lhs * (1 / factor);
}

tampio::rectangle_t::rectangle_t() :
    width(0),
    height(0),
    pos(point_t(0, 0))
{}
tampio::rectangle_t::rectangle_t(double w_new, double h_new, const point_t &pos_new) :
    width(w_new),
    height(h_new),
    pos(pos_new)
{}
