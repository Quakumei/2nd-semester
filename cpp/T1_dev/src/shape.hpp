#include "base-types.hpp"

class Shape {
public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void scale(point_t pos, double factor) = 0;
    void move(const point_t& p);
    void move(double dx, double dy);
};

//TODO: Реализовать move'ы.
