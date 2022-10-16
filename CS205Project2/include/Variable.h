#pragma once
#include <string>
using namespace std;

#define pi "3.1415926"
#define e "2.7182881"
bool checkVariable(string str);
struct Variable
{
    string name;
    string val;
};
Variable var[100] = {};
int varnum = 0;
void clearVar();
void replaceVar(string &str);
void replaceConstant(string &str);
bool checkValid(string str);