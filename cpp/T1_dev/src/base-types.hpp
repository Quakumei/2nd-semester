#ifndef BASETYPES_H
#define BASETYPES_H

namespace tampio
{
  struct point_t
  {
    double x, y;
    point_t();
    point_t(double x, double y);
  };

  struct rectangle_t
  {
    double width, height;
    point_t pos;
    rectangle_t();
    rectangle_t(double w_new, double h_new, const point_t &pos_new);
  };

  point_t operator+(point_t const &lhs, point_t const &rhs);
  point_t operator-(point_t const &lhs, point_t const &rhs);
  point_t operator*(point_t const &lhs, double factor);
  point_t operator/(point_t const &lhs, double factor);
}
#endif
