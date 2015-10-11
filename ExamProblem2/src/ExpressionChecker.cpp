#include "ExpressionChecker.h"

ExpressionChecker::ExpressionChecker(std::string expression)
{
    this -> expression = expression;
}

bool ExpressionChecker::ifValid()
{
    bool success = true;

    for(unsigned int i = 0; i < expression.size(); i++)
    {std::cin.ignore();
        if(expression.at(i) == OPEN_PAREN ||
           expression.at(i) == OPEN_BRACE ||
           expression.at(i) == OPEN_BRACKET)
        {
            stack.push(expression.at(i));
        }

        if(expression.at(i) == CLOSED_PAREN ||
           expression.at(i) == CLOSED_BRACE ||
           expression.at(i) == CLOSED_BRACKET)
        {
            char compareTo = stack.pop();

            if(compareTo == OPEN_PAREN)
            {
                if(expression.at(i) != CLOSED_PAREN)
                {
                    success = false;
                }
            }
            else if(compareTo == OPEN_BRACE)
            {
                if(expression.at(i) != CLOSED_BRACE)
                {
                    success = false;
                }
            }
            else if(compareTo == OPEN_BRACKET)
            {
                if(expression.at(i) != CLOSED_BRACKET)
                {
                    success = false;
                }
            }
        }
    }

    ///Accounts for starting braces that have no close;
    if(!stack.ifEmpty())
    {
        success = false;
    }

    return success;
}
