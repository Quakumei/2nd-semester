#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <ostream>

#include "shape.hpp"

namespace tampio
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &a, const point_t &b);
    Rectangle(const rectangle_t &rect);
    double getArea() const;
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &obj)
    {
      os << obj.a_.x << " " << obj.a_.y << " " << obj.b_.x << " " << obj.b_.y;
      return os;
    }

  private:
    void scaleParameters(const point_t &center, double factor);
    point_t a_, b_;
  };

}

#endif
