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
  }
  while (!std::cin.eof())
  {
    std::string command = "";
    std::cin >> command;
    if (command == "print")
    {
      std::string name;
      std::cin >> name;
      Dict example = datasets.get(name);
      print(example, name, std::cout);
    }
    else if (command == "complement")
    {
      std::string name, left, right;
      std::cin >> name >> left >> right;
      datasets.push(name, complement(datasets.get(left), datasets.get(right)));
    }
    else if (command == "intersect")
    {
      std::string name, left, right;
      std::cin >> name >> left >> right;
      datasets.push(name, intersect(datasets.get(left), datasets.get(right)));
    }
    else if (command == "union")
    {
      std::string name, left, right;
      std::cin >> name >> left >> right;
      datasets.push(name, unionDict(datasets.get(left), datasets.get(right)));
    }
  }
}