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
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &obj);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const tampio::point_t &new_pos);
    void move(double dx, double dy);

  private:
    point_t a_, b_;
    void scaleParameters(const point_t &center, double factor);
  };
  std::ostream &operator<<(std::ostream &os, const tampio::Rectangle &obj);

}

#endif
