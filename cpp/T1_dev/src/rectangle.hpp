#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

namespace tampio
{
    class Rectangle : public Shape
    {
    public:
        Rectangle(const point_t& a, const point_t& b);
        Rectangle(const rectangle_t& rect);
        double getArea() const;
    private:
        void scaleParameters(const point_t& center, double factor);
        point_t a_, b_;
        rectangle_t frame_;
    };
}

#endif
