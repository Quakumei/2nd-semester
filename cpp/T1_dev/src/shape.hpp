#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>
#include <ostream>
#include "base-types.hpp"

namespace tampio
{
  class Shape
  {
  public:
    enum ShapeType
    {
      UNKNOWN,
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
    void scale(const point_t &center, double factor);
    void printPoints(std::ostream &) const;

  protected:
    virtual void scaleParameters(const point_t &center, double factor) = 0;

  private:
    void scaleFrame(const point_t &center, double factor);
  };
}
#endif
