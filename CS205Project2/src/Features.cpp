#include <iostream>
#include <string>
#include <math.h>
#include "Calculator.h"

bool dealMathFunctions(string &str)
{
    int posL;
    int posR;
    int posComma;
    double num;
    if (str.find("sqrt(") != -1)
    {
        posL = str.find("sqrt(");
        posR = str.find(')', posL + 5);
        num = atof(str.substr(posL + 5, posR - posL - 5).c_str());
        str = str.substr(0, posL) + to_string(sqrt(num)) + str.substr(posR + 1);
    }
    if (str.find("pow(") != -1)
    {
        posL = str.find("pow(");
        posR = str.find(')', posL + 4);
        posComma = str.find(',');
        num = atof(str.substr(posL + 4, posComma - posL - 4).c_str());
        double exp = atof(str.substr(posComma + 1, posR - posComma - 1).c_str());
        str = str.substr(0, posL) + to_string(pow(num, exp)) + str.substr(posR + 1);
    }
    if (str.find("exp(") != -1)
    {
        posL = str.find("exp(");
        posR = str.find(')', posL + 4);
        num = atof(str.substr(posL + 4, posR - posL - 4).c_str());
        str = str.substr(0, posL) + to_string(exp(num)) + str.substr(posR + 1);
    }
    if (str.find("log(") != -1)
    {
        posL = str.find("log(");
        posR = str.find(')', posL + 4);
        num = atof(str.substr(posL + 4, posR - posL - 4).c_str());
        str = str.substr(0, posL) + to_string(log(num)) + str.substr(posR + 1);
    }
    if (str.find("sin(") != -1)
    {
        posL = str.find("sin(");
        posR = str.find(')', posL + 4);
        num = atof(str.substr(posL + 4, posR - posL - 4).c_str());
        str = str.substr(0, posL) + to_string(sin(num)) + str.substr(posR + 1);
    }
    if (str.find("cos(") != -1)
    {
        posL = str.find("cos(");
        posR = str.find(')', posL + 4);
        num = atof(str.substr(posL + 4, posR - posL - 4).c_str());
        str = str.substr(0, posL) + to_string(cos(num)) + str.substr(posR + 1);
    }
    if (str.find("mod(") != -1)
    {
        posL = str.find("mod(");
        posR = str.find(')', posL + 4);
        posComma = str.find(',');
        string num1 = str.substr(posL + 4, posComma - posL - 4);
        string num2 = str.substr(posComma + 1, posR - posComma - 1);
        if (isInteger(num1) && isInteger(num2))
        {
            str = str.substr(0, posL) + to_string(atoi(num1.c_str()) % atoi(num2.c_str())) + str.substr(posR + 1);
            // int num1 = atoi(str.substr(posL + 4, posComma - posL - 4).c_str());
            // int num2 = atoi(str.substr(posComma + 1, posR - posComma - 1).c_str());
        }
        else
        {
            cout << "The input is not integer" << endl;
            return false;
        }
    }
    return true;
}

bool isInteger(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

int checkInstructions(string str)
{
    if (str == "quit")
    {
        return -1;
    }
    if (str == "help")
    {
        cout << endl;
        cout << "1. This calculator supports mixed operation using + - * / and ()" << endl;
        cout << endl;
        cout << "2. You can define at most 100 variables to calculate like the follow example: " << endl;
        cout << "x=3" << endl;
        cout << "y=2" << endl;
        cout << "x*y" << endl;
        cout << endl;
        cout << "3. There are also some math fuctions supported:" << endl;
        cout << "sqrt(x) pow(x,y) exp(x) log(x) sin(x) cos(x) mod(x,y)" << endl;
        cout << endl;
        cout << "4. Some constants are supported like pi,e" << endl;
        cout << endl;
        cout << "5. Arbitrary precision is supported in the calculator" << endl;
        cout << endl;
        return 1;
    }
    return 0;
}