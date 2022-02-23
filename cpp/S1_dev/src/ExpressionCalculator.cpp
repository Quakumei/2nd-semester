#include "ExpressionCalculator.h"
#include <string>
#include <cctype>
#include "Stack.hpp"

ExpressionCalculator::ExpressionCalculator(const std::string &expr)
{
    exprToLexemes(expr);
}

int ExpressionCalculator::solve() const
{
    Queue<std::string> postfixExpr = postfixForm(lexemes_);

    //std::clog << "\n POSTFIXFORM: " << postfixExpr.print();

    Stack<int> values;
    for(std::string lexeme = postfixExpr.drop(); ; lexeme = postfixExpr.drop()){
        if (isdigit(lexeme[0])){
            
            values.push(std::stoi(lexeme));
        } else {
            int right = values.drop();
            int left = values.drop();
            switch(lexeme[0]){
                case '+':
                    values.push(left+right);
                    break;
                case '-':
                    values.push(left-right);
                    break;
                case '/':
                    values.push(left/right);
                    break;
                case '*':
                    values.push(left*right);
                    break;
                case '%':
                    values.push(left % right);
                    break;
                default:
                    throw std::logic_error("Unknown operator! (solve)");
            }
        }
        if (postfixExpr.isEmpty()){
            break;
        }
    }
    //std::clog << "\n values:" << values.print();
    int res = values.drop();
    if (!values.isEmpty()){
        throw std::logic_error("Bad expression! (solve)");
    }

    return res;
}

void ExpressionCalculator::exprToLexemes(const std::string &expr)
{
    std::string res = "";
    for (int i = 0; i < expr.length(); i++)
    {
        std::string lexeme = "";
        if (expr[i] != ' ')
        {
            if (isdigit(expr[i]))
            {
                for (; (expr[i] != ' ') && (i < expr.length()) && isdigit(expr[i]); i++)
                {
                    //std::cout << "\nNumber: " << std::string(1,expr[i]);
                    lexeme.append(std::string(1,expr[i]));
                }
                i--;
                lexemes_.push(lexeme);
            }
            else
            {
                lexeme.append(std::string(1,expr[i]));
                lexemes_.push(lexeme);
            }
        }
    }
}

Queue<std::string> ExpressionCalculator::postfixForm(Queue<std::string> lexemes) const
{
    if (lexemes.isEmpty())
    {
        throw std::logic_error("Bad expression! (postfixForm)");
    }
    Stack<char> operationStack;
    //std::clog << "\n LEXEMFORM: " << lexemes.print();


    Queue<std::string> res;

    for (int i = 0; !lexemes.isEmpty(); i++)
    {
        std::string lexeme = lexemes.drop();
        if (
            lexeme == "(" ||
            lexeme == "+" ||
            lexeme == "-" ||
            lexeme == "*" ||
            lexeme == "/" ||
            lexeme == "%")
        {
            operationStack.push(lexeme[0]);
        }
        else if (isdigit(lexeme[0]))
        {
            std::string lex = "" + lexeme;
            res.push(lex);
        }
        else if (lexeme == ")")
        {
            try
            {
                for (char operation = operationStack.drop(); operation != '(';
                     operation = operationStack.drop())
                {
                    res.push(std::string(1,operation));
                }
            }
            catch (std::logic_error e)
            {
                throw std::logic_error("Unmatched parenthesis! (postfixForm)");
            }
        }
        else
        {
            throw std::logic_error("Unknown lexeme! (postfixForm)");
        } 
    }

    for(; !operationStack.isEmpty();){
        res.push(std::string(1,operationStack.drop()));
    }
    //std::clog << "\n res: " << res.print() << ' ' << operationStack.isEmpty();
    return res;
}
