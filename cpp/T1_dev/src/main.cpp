#include <iostream>
#include <sstream>
#include <memory>
#include <limits>

#include "shape.hpp"
#include "rectangle.hpp"



using namespace tampio;

int main()
{
    bool badInput = false;

    double totalArea = 0;
    std::stringstream ss;

    std::string cmd = "";
    while (std::cin >> cmd && cmd != "SCALE")
    {
        Shape::ShapeType st;
        if (cmd == "RECTANGLE")
        {
            st = Shape::ShapeType::RECTANGLE;
        }
        else if (cmd == "CIRCLE")
        {
            st = Shape::ShapeType::CIRCLE;
        }
        else if (cmd == "ELLIPSIS")
        {
            st = Shape::ShapeType::ELLIPSIS;
        }
        else
        {
            st = Shape::ShapeType::UNKNOWN;
        }


        std::unique_ptr<Shape> fig = nullptr;
        switch (st)
        {
        case Shape::ShapeType::UNKNOWN:
            badInput = true;
            break;
        case Shape::ShapeType::RECTANGLE:
        {
            double x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            point_t a = point_t(x1, y1);
            point_t b = point_t(x2, y2);
            fig = std::make_unique<Rectangle>(a, b);
            break;
        }
        case Shape::ShapeType::CIRCLE:
        case Shape::ShapeType::ELLIPSIS:
            badInput = true;
            break;
        }
        if (!fig)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        totalArea += Rectangle(fig->getFrameRect()).getArea();
        ss << Rectangle(fig->getFrameRect())  << ' ';
    }
    std::cout << totalArea << ' ' << ss.str().c_str() << '\n';
    if (cmd == "SCALE") {
        double x,y, factor;
        std::cin  >> x >>  y  >> factor;
        std::cout << "DOING SCALE WITH:  " << x << ' ' << y << ' ' << factor << '\n';
        point_t center = point_t(x,y);
        totalArea *= factor * factor;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << totalArea << ' ' << ss.str().c_str() << '\n';
    if (badInput)
    {
        std::cerr << "BAD FIGURES OCCURED, SKIPPED.\n";
    }
    return 0;
}
