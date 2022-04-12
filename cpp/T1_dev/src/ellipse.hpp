#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.hpp"

namespace tampio
{
    class Ellipse : public Shape
    {
    public:
        Ellipse(double radx, double rady, const point_t &center);
        double getArea() const;

    private:
        void scaleParameters(const point_t &center, double factor);
        point_t center_;
        double radx_, rady_;
    };

}

#endif
