#ifndef SHAPE_H
#define SHAPE_H

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

    Shape(){};
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    rectangle_t getFrameRect() const;
    void move(const point_t &p);
    void move(double dx, double dy);
    void scale(const point_t &center, double factor);
    void printPoints(std::ostream &) const;

  protected:
    virtual void scaleParameters(const point_t &center, double factor) = 0;
    rectangle_t frame_;

  private:
    void scaleFrame(const point_t &center, double factor);
  };
} // namespace tampio
#endif
