#include <fstream>
#include <iostream>

#include "Dictionary.hpp"
#include "utility.hpp"
using namespace tampio;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Error input file";
    return 1;
  }
  using Dict = tampio::Dictionary< std::string, std::string >;
  using DictOfDict = Dictionary< std::string, Dict >;
  std::cout << "Reading: " << argv[1] << '\n';
  std::ifstream in(argv[1]);
  ForwardList< std::string > words;
  DictOfDict datasets;
  while (!in.eof())
  {
    std::string line = "";
    std::getline(in, line);
    if (line != "\0")
    {
      line += ' ';
      std::string temp = "";
      for (size_t i = 0; i < line.size(); i++)
      {
        if (line[i] == ' ')
        {
          words.pushBack(temp);
          temp = "";
        }
        else
        {
          temp += line[i];
        }
      }
      std::string nameOfDict = words.front();
      words.deleteFront();
      Dict dictionariesOfValues;
      while (!words.empty())
      {
        std::string key = words.front();
        words.deleteFront();
        std::string value = words.front();
        words.deleteFront();
        dictionariesOfValues.push(key, value);
      }
      datasets.push(nameOfDict, dictionariesOfValues);
    }
    std::string name = "first";
    Dict example = datasets.get(name);
    print(example, name, std::cout);
  }
}