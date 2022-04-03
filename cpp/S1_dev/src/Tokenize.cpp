#include "Tokenize.h"
namespace tampio
{
    Queue<std::string> convertToLexemes(const std::string &expr)
    {
        Queue<std::string> result;
        std::string res = "";
        for (std::size_t i = 0; i < expr.length(); i++)
        {
            std::string lexeme = "";
            if (expr[i] != ' ')
            {
                if (isdigit(expr[i]))
                {
                    for (; (expr[i] != ' ') && (i < expr.length()) && isdigit(expr[i]); i++)
                    {
                        lexeme.append(std::string(1, expr[i]));
                    }
                    i--;
                    result.push(lexeme);
                }
                else
                {
                    lexeme.append(std::string(1, expr[i]));
                    result.push(lexeme);
                }
            }
        }
        return result;
    }
}

