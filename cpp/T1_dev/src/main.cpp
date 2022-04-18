#include <iostream>
#include <limits>
#include <memory>

#include "circle.hpp"
#include "ellipse.hpp"
#include "rectangle.hpp"
#include "shapecollection.hpp"

using namespace tampio;

Shape::ShapeType stringToShapeType(const std::string &s)
{
  Shape::ShapeType st;
  if (s == "RECTANGLE")
  {
    st = Shape::ShapeType::RECTANGLE;
  } else if (s == "CIRCLE")
  {
    st = Shape::ShapeType::CIRCLE;
  } else if (s == "ELLIPSE")
  {
    st = Shape::ShapeType::ELLIPSE;
  } else
  {
    st = Shape::ShapeType::UNKNOWN;
  }
  return st;
}

int main()
{
  ShapeCollection< std::shared_ptr< Shape > > sc;
  bool unknownFigure = false;
  bool badKnownFigure = false;

  std::string cmd = "";
  while (std::cin >> cmd && !std::cin.eof() && cmd != "SCALE")
  {
    Shape::ShapeType st = stringToShapeType(cmd);
    std::shared_ptr< Shape > fig = nullptr;
    try
    {
      switch (st)
      {
      case Shape::ShapeType::UNKNOWN:
        break;
      case Shape::ShapeType::ELLIPSE:
      {
        double rady, radx, x, y;
        std::cin >> x >> y >> rady >> radx;
        point_t center = point_t{x, y};
        fig = std::make_shared< Ellipse >(rady, radx, center);
        break;
      }
      case Shape::ShapeType::CIRCLE:
      {
        double rad, x, y;
        std::cin >> x >> y >> rad;
        point_t center = point_t{x, y};
        fig = std::make_shared< Circle >(rad, center);
        break;
      }
      case Shape::ShapeType::RECTANGLE:
      {
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        point_t a = point_t{x1, y1};
        point_t b = point_t{x2, y2};
        fig = std::make_shared< Rectangle >(a, b);
        break;
      }
      }
    } catch (const std::logic_error &e)
    {
      badKnownFigure = true;
      continue;
    }
    if (!fig)
    {
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      unknownFigure = true;
      continue;
    }
    sc.appendElement(fig);
  }

  if (sc.isEmpty())
  {
    std::cerr << "Error: nothing to scale.";
    return 1;
  }

  std::cout.setf(std::ios::fixed);
  std::cout.precision(1);
  std::cout << sc << "\n";

  try
  {
    if (std::cin.eof() || std::cin.bad() || cmd != "SCALE")
    {
      throw std::logic_error("No scale.");
    }
    double x, y, factor;
    std::cin >> x >> y >> factor;
    sc.scale(point_t{x, y}, factor);
    std::cout << sc << "\n";
  } catch (const std::logic_error &e)
  {
    std::cerr << "Scaling error: " << e.what() << std::endl;
    return 1;
  }

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
