#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

namespace tampio
{
  class Circle : public Shape
  {
  public:
    Circle(double rad, const point_t &center);
    double getArea() const;

  private:
    void scaleParameters(const point_t &center, double factor);
    double rad_;
    point_t center_;
  };

} // namespace tampio

#endif
