#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

namespace tampio
{
    class Rectangle : public Shape
    {
    public:
        Rectangle(const point_t& a, const point_t& b);
        double getArea() const override;
    private:
        void scaleParameters(const point_t& center, double factor) override;
        point_t a_, b_;
    };
}

#endif
