#ifndef SHAPE_H
#define SHAPE_H

#include <ostream>
#include "base-types.hpp"

namespace tampio
{
  class Shape
  {
  public:
    enum ShapeType
    {
      UNKNOWN = 0,
      RECTANGLE,
      CIRCLE,
      ELLIPSE
    };

    Shape() = default;
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &p) = 0;
    void move(double dx, double dy);
    void scale(double factor);
    void printPoints(std::ostream &) const;

  protected:
    virtual void scaleParameters(double factor) = 0;
  };
}
#endif
