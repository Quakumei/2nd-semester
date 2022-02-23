#include <iostream>
#include <fstream>
#include <string>

#include "Stack.hpp"
#include "ExpressionCalculator.h"

int main(int argc, char* argv[])
{
    //Вся мощь наследования и полиморфизма в действии!
    std::istream * is;
    switch (argc){
        case 2:
        {
            std::string filename = argv[1];
            is = new std::ifstream(filename);
            break;
        }
        case 1:
            is = &std::cin; 
            break;
        default: 
            throw std::logic_error("Filename should be specified as an only argument");
    }
    
    std::string line;
    Stack<int> results;
    
    while (std::getline(*is, line, '\n')){
        ExpressionCalculator ec(line);
        results.push(ec.solve());
    }
    if (!results.isEmpty()){
        int res = results.drop();
        std::cout << res << ' ';
        for ( ;!results.isEmpty();){
            res = results.drop();
            std::cout << res << ' ';
        }
    }
    return 0;
}