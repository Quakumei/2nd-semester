#include <iostream>
#include <memory>
#include <limits>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"

using namespace tampio;

Shape::ShapeType stringToShapeType(const std::string &s)
{
    Shape::ShapeType st;
    if (s == "RECTANGLE")
    {
        st = Shape::ShapeType::RECTANGLE;
    }
    else if (s == "CIRCLE")
    {
        st = Shape::ShapeType::CIRCLE;
    }
    else if (s == "ELLIPSIS")
    {
        st = Shape::ShapeType::ELLIPSE;
    }
    else
    {
        st = Shape::ShapeType::UNKNOWN;
    }
    return st;
}

int main()
{
    bool unknownFigure = false;
    bool badKnownFigure  = false;
    double totalArea = 0;

    std::string cmd = "";
    while (std::cin >> cmd && !std::cin.eof() && cmd != "SCALE")
    {
        Shape::ShapeType st = stringToShapeType(cmd);
        std::unique_ptr<Shape> fig = nullptr;
        try
        {
            switch (st)
            {
            case Shape::ShapeType::UNKNOWN:
            case Shape::ShapeType::ELLIPSE:
            {
                double radx, rady, x,y;
                std::cin >> x >> y >> rady >> radx;
                point_t center = point_t(x,y);
                fig = std::make_unique<Ellipse>(radx, rady, center);
                break;
            }
            case Shape::ShapeType::CIRCLE:
            {
                double rad, x,y;
                std::cin >> x >> y >> rad;
                point_t center = point_t(x,y);
                fig = std::make_unique<Circle>(rad, center);
                break;
            }
            case Shape::ShapeType::RECTANGLE:
            {
                double x1, y1, x2, y2;
                std::cin >> x1 >> y1 >> x2 >> y2;
                point_t a = point_t(x1, y1);
                point_t b = point_t(x2, y2);
                fig = std::make_unique<Rectangle>(a, b);
                break;
            }
            }
        } catch (const std::logic_error& e) {
            badKnownFigure = true;
            continue;
        }
        if (!fig)
        {
            std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
            unknownFigure = true;
            continue;
        }
        totalArea += Rectangle(fig->getFrameRect()).getArea();
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << totalArea << ' ' << '\n';

    try{
        if (std::cin.eof())
        {
            throw std::logic_error("No scale.");
        }
        if (cmd == "SCALE")
        {
            double x, y, factor;
            std::cin >> x >> y >> factor;
            if (factor < 0){
                throw std::logic_error("Scaling factor must be positive");
            }
            totalArea *= factor * factor;
            // std::cout << "DOING SCALE WITH:  " << x << ' ' << y << ' ' << factor << '\n';
            // point_t center = point_t(x,y);
        }
    } catch (const std::logic_error& e) {
        std::cerr << "Scaling error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << totalArea << ' ' << '\n';

    if (unknownFigure)
    {
        std::cerr << "BAD FIGURES OCCURED, SKIPPED.\n";
    }
    if (badKnownFigure)
    {
        std::cerr << "BAD SHAPE ARGUMENTS, SKIPPED.\n";
    }
    return 0;
}
