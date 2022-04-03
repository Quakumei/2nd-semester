#include <iostream>
#include <fstream>

#include "Stack.hpp"
#include "ExpressionCalculator.h"

using namespace tampio;

int main(int argc, char *argv[])
{
    std::ifstream ifs;
    if (argc >= 2)
    {
        ifs.open(argv[1]);

        if (!ifs.is_open())
        {
            std::cerr << "File error.\n";
            return 1;
        }
    }
    std::istream &is = (argc < 2) ? std::cin : ifs;

    Stack<long long> results;
    try
    {
        std::string line = "";
        while (getline(is, line))
        {
            if (line.empty())
                continue;

            ExpressionCalculator ar(line);
            results.push(ar.solve());
        }
    }
    catch (std::overflow_error &e)
    {
        std::cerr << "Overflow error! " << e.what() << '\n';
        return 69;
    }
    catch (std::logic_error &e)
    {
        std::cerr << "Logic error! " << e.what() << '\n';
        return 420;
    }
    catch (const char *e)
    {
        std::cerr << "Error! " << e << '\n';
        return 322;
    }

    while (!results.isEmpty())
    {
        std::cout << results.drop();

        if (!results.isEmpty())
        {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}
