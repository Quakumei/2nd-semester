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
      else if (command == "remove")
      {
        std::string name, left;
        std::cin >> name >> left;
        if (std::isalpha(left[0]))
        {
          removeElems(lists.getRef(name), lists.get(left));
        }
        else
        {
          removeElems(lists.getRef(name), std::stoll(left));
        }
      }
      else if (command == "concat")
      {

        std::string name;
        std::cin >> name;
        lists.push(name, BidirectionalList< long >());

        std::string listName;
        std::getline(std::cin, listName);
        ForwardList< std::string > lexemes_s;
        if (listName != "\0")
        {
          listName += ' ';
          std::string temp = "";
          for (size_t i = 0; i < listName.size(); i++)
          {
            if (listName[i] == ' ')
            {
              lexemes_s.pushBack(temp);
              temp = "";
            }
            else
            {
              temp += listName[i];
            }
          }
        }

        while (!lexemes_s.empty())
        {
          if (lexemes_s.front() == "")
          {
            lexemes_s.deleteFront();
            continue;
          }
          // std::cout << "get:" << lexemes_s.front();
          concat(lists.getRef(name), lists.get(lexemes_s.front()));
          lexemes_s.deleteFront();
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
    catch (const std::exception &e)
    {
      std::cout << "<INVALID COMMAND>\n";
      std::cout << e.what();

      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
}
