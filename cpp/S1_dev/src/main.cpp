#include <iostream>
#include <fstream>
#include <string>
#include "Stack.hpp"
#include "ExpressionCalculator.h"

int main(int argc, char *argv[])
{
    std::ifstream ifs;
    if (argc != 1)
    {
        ifs.open(argv[1]);

        if (!ifs.is_open())
        {
            std::cerr << "File error.\n";
            return 1;
        }
    }
    std::istream &is = (argc == 1) ? std::cin : ifs;

    Stack<long long> result;
    try
    {
        std::string line = "";
        while (getline(is, line))
        {
            if (line.empty())
                continue;

            ExpressionCalculator ar(line);
            result.push(ar.solve());
        }
    }
    catch (std::overflow_error &e)
    {
        std::cerr << "Overflow error! " << e.what() << std::endl;
        return 1;
    }
    catch (std::logic_error &e)
    {
        std::cerr << "Logic error! " << e.what() << std::endl;
        return 2;
    }
    catch (const char *e)
    {
        std::cerr << "Error! " << e << std::endl;
        return 3;
    }

    while (!result.isEmpty())
    {
        std::cout << result.drop();

        if (!result.isEmpty())
        {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}
