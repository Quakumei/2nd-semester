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
            UNKNOWN = 0, RECTANGLE, CIRCLE, ELLIPSIS
        };

        Shape() {
            //frame_ = rectangle_t();
        };
        virtual ~Shape() = default;
        virtual double getArea() const = 0;
        rectangle_t getFrameRect() const;
        void move(const point_t&  p);
        void move(double dx, double dy);
        void scale(const point_t& center, double factor);

    protected:
        virtual void scaleParameters(const point_t& center, double factor) = 0;
        rectangle_t frame_;

    private:
        void scaleFrame (double factor);
    };
}
#endif
