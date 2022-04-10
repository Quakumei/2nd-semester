#include "shape.hpp"
#include <stdexcept>

void tampio::Shape::move(const tampio::point_t& new_pos)
{
    frame_.pos = new_pos;
}

void tampio::Shape::move(double dx, double dy)
{
    frame_.pos = point_t(frame_.pos.x + dx, frame_.pos.y + dy);
}

void tampio::Shape::scaleFrame(double factor)
{
    frame_.height *= factor;
    frame_.width *= factor;
}

void tampio::Shape::scale(const point_t& center, double factor)
{
    if (factor > 0)
    {
        throw std::logic_error("Scale factor must be positive.");
    }
    scaleFrame(factor);
    scaleParameters(center, factor);
}