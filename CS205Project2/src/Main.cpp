#include <iostream>
#include "Calculator.h"
#include "Variable.h"
#include "WTNumber.h"
using namespace std;

int main()
{
    string str;
    while (1)
    {
        cin >> str;
        int checkI = checkInstructions(str);
        if (checkI == -1)
        {
            break;
        }
        if (checkI == 1)
        {
            continue;
        }
        if (!checkVariable(str)) // check whether the input is defining variable
        {
            replaceVar(str);
            if (!dealMathFunctions(str)) // check the input of mod()
            {
                continue;
            }
            if (!checkValid(str)) // check whether the input contains undefined variable
            {
                continue;
            }
            cout << calculate(str).ToString() << endl;
            clearVar();
        }
    }
    return 0;
}

bool checkVariable(string str)
{
    if (str.find('=') != -1)
    {
        int pos = str.find('=');
        var[varnum] = {str.substr(0, pos), str.substr(pos + 1)};
        varnum++;
        return true;
    }
    else
    {
        return false;
    }
}

void clearVar()
{
    for (int i = 0; i < varnum; i++)
    {
        var[i].name = "";
        var[i].val = "";
    }
    varnum = 0;
}

void replaceVar(string &str)
{
    for (int i = 0; i < varnum; i++)
    {
        while (1)
        {
            int index = str.find(var[i].name);
            if (index != -1)
            {
                str.replace(index, var[i].name.length(), var[i].val);
            }
            else
            {
                break;
            }
        }
    }
    replaceConstant(str);
}

void replaceConstant(string &str)
{
    if (str.find("pi") != -1)
    {
        int pos = str.find("pi");
        str.replace(pos, 2, pi);
    }
    if (str.find("e") != -1)
    {
        int pos = str.find("e");
        str.replace(pos, 1, e);
    }
}

bool checkValid(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '.' || str[i] == 'e' || str[i] == '(' || str[i] == ')')
        {
            continue;
        }
        if (!isdigit(str[i]))
        {
            cout << "There are variables not defined" << endl;
            return false;
        }
    }
    return true;
}