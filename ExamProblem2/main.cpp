#include <iostream>

#include "ExpressionChecker.h"

using namespace std;

int main()
{
    std::string testExpression1 = "(23+45-{32*43}*23)";
    std::string testExpression2 = "(23+45-{32*43}*23]";
    std::string testExpression3 = "{({([{9*3}])})";
    //std::string testExpression4 = "{({([{9*3}])})}}";
    std::string testExpression5 = "{({([{9*3}])})}";

    ExpressionChecker m1(testExpression1);
    ExpressionChecker m2(testExpression2);
    ExpressionChecker m3(testExpression3);
    //ExpressionChecker m4(testExpression4);
    ExpressionChecker m5(testExpression5);

    cout << "Test Expression #1 success: " << m1.ifValid() << endl;
    cout << "Test Expression #2 success: " << m2.ifValid() << endl;
    cout << "Test Expression #3 success: " << m3.ifValid() << endl;
    //cout << "Test Expression #4 success: " << m4.ifValid() << endl;
    cout << "Test Expression #5 success: " << m5.ifValid() << endl;

    return 0;
}
