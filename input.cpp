#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool Input(int& number, string str)
{
    char character;
    stringstream ss;
    ss << str;
    
    if(ss >> number)
    {
        if(ss >> character)
        {
            cout << "Invalid input. Input integers only.\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cout << "Invalid input. Input integers only.\n\n";
        return false;
    }
}

bool Input(double& number, string str)
{
    char character;
    stringstream ss;
    ss << str;
    
    if(ss >> number)
    {
        if(ss >> character)
        {
            cout << "Invalid input. Input real numbers only.\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cout << "Invalid input. Input real numbers only.\n\n";
        return false;
    }
}
