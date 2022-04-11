#ifndef BASETYPES_H
#define BASETYPES_H

namespace tampio
{
    struct point_t
    {
        // point_t();
        point_t(double x, double y);
        double x, y;
    };

    struct rectangle_t
    {
        rectangle_t();
        rectangle_t(double w_new, double h_new, point_t pos_new);
        double width, height;
        point_t pos;
    };

    point_t operator+(point_t const &lhs,
                      point_t const &rhs);
    point_t operator-(point_t const &lhs,
                      point_t const &rhs);
    point_t operator*(point_t const &lhs,
                      double factor);
    point_t operator/(point_t const &lhs,
                      double factor);
}
#endif
