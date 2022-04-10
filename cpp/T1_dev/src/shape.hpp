#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.hpp"

namespace tampio
{
    class Shape
    {
    public:
        Shape() {
            frame_ = rectangle_t();
        };
        virtual ~Shape() = default;

        virtual double getArea() const = 0;
        virtual rectangle_t getFrameRect() const = 0;
        virtual void scale(double factor) = 0;
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
