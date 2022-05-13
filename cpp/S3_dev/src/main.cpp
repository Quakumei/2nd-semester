#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include "BidirectionalList.hpp"
#include "Dictionary.hpp"
#include "utility.hpp"

using namespace tampio;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "No input file specified";
    return 1;
  }
  std::ifstream in(argv[1]);

  using Dict = Dictionary< std::string, tampio::BidirectionalList< long > >;
  ForwardList< std::string > lexemes;
  Dict lists;
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
          lexemes.pushBack(temp);
          temp = "";
        }
        else
        {
          temp += line[i];
        }
      }
      std::string listName = lexemes.front();
      lexemes.deleteFront();
      BidirectionalList< long > list;
      while (!lexemes.empty())
      {
        std::string value = lexemes.front();
        lexemes.deleteFront();
        list.pushBack(std::stol(value));
      }
      lists.push(listName, list);
    }
  }
  while (!std::cin.eof())
  {
    try
    {

      std::string command = "";
      std::cin >> command;
      if (command == "print")
      {
        std::string name;
        std::cin >> name;
        BidirectionalList< long > example = lists.get(name);
        print(example, name, std::cout);
      }
      else if (command == "replace")
      {
        std::string name, left, right;
        std::cin >> name >> left >> right;
        if (std::isalpha(right[0]))
        {
          replace(lists.getRef(name), std::stoll(left), lists.get(right));
        }
        else
        {
          replace(lists.getRef(name), std::stoll(left), std::stoll(right));
        }
      }
      // else if (command == "intersect")
      // {
      //   std::string name, left, right;
      //   std::cin >> name >> left >> right;
      //   datasets.push(name, intersect(datasets.get(left), datasets.get(right)));
      // }
      // else if (command == "union")
      // {
      //   std::string name, left, right;
      //   std::cin >> name >> left >> right;
      //   datasets.push(name, unionDict(datasets.get(left), datasets.get(right)));
      // }
      else if (!std::cin.eof())
      {
        throw std::logic_error("unknown command");
      }
    }
    catch (const std::exception &)
    {
      std::cout << "<INVALID COMMAND>\n";
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
}
