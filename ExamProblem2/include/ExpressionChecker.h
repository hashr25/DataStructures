#ifndef EXPRESSIONCHECKER_H
#define EXPRESSIONCHECKER_H

#include <iostream> //std::cout, std::endl // Testing Purposes only
#include <string> //std::string

#include "Stack.h"

const char OPEN_PAREN = '(';
const char CLOSED_PAREN = ')';
const char OPEN_BRACE = '[';
const char CLOSED_BRACE = ']';
const char OPEN_BRACKET = '{';
const char CLOSED_BRACKET = '}';

class ExpressionChecker
{
    public:
        ExpressionChecker(std::string);

        bool ifValid();


    private:
        std::string expression;
        Stack stack;
};

#endif // EXPRESSIONCHECKER_H
