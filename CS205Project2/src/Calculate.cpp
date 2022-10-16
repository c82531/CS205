#include <iostream>
#include <string>
#include "Calculator.h"
#include "WTNumber.h"
using namespace std;

CWTNumber calculate(string str)
{
    dealMathFunctions(str);
    if (str.find_last_of('(') != -1)
    {
        int posL = str.find_last_of('(');
        int posR = str.find(')', posL + 1);
        string bracketsExp = str.substr(posL + 1, posR - posL - 1);
        string removeBrackets = str.substr(0, posL) + calculate(bracketsExp).ToString() + str.substr(posR + 1);
        return calculate(removeBrackets);
    }
    else if (str.find('+') != -1)
    {
        int pos = str.find('+');
        string num1 = str.substr(0, pos);
        string num2 = str.substr(pos + 1);
        return calculate(num1) + calculate(num2);
    }
    else if (str.find('-') != -1)
    {
        int pos = str.find('-');
        string num1 = str.substr(0, pos);
        string num2 = str.substr(pos + 1);
        return calculate(num1) - calculate(num2);
    }
    else if (str.find('/') != -1)
    {
        int pos = str.find('/');
        string num1 = str.substr(0, pos);
        string num2 = str.substr(pos + 1);
        return calculate(num1) / calculate(num2);
    }
    else if (str.find('*') != -1)
    {
        int pos = str.find('*');
        string num1 = str.substr(0, pos);
        string num2 = str.substr(pos + 1);
        return calculate(num1) * calculate(num2);
    }
    else
    {
        return CWTNumber(str.c_str());
    }
}
