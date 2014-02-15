#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#include "dataclass.h"
#include "cubicspline.h"

void CubicSpline::SolveA(Data myData)
{
    a = myData.f;
}

void CubicSpline::SolveH(Data myData)
{
    for(int i = 0; i <= myData.x.size() - 2; i++)
    {
        h.push_back(myData.x.at(i + 1) - myData.x.at(i));
    }
}

vector<double> CubicSpline::GetSubDiagonal()
{
    vector<double> holder;
    
    holder.push_back(0);
    
    for(int i = 0; i <= h.size() - 2; i++)
    {
        holder.push_back(h.at(i));
    }
    
    holder.push_back(0);
    
    return holder;
}

vector<double> CubicSpline::GetMainDiagonal()
{
    vector<double> holder;
    
    holder.push_back(1);
    
    for(int i = 0; i <= h.size() - 2; i++)
    {
        holder.push_back(2*(h.at(i) + h.at(i + 1)) );
    }
    
    holder.push_back(1);
    
    return holder;
}

vector<double> CubicSpline::GetSuperDiagonal()
{
    vector<double> holder;
    
    holder.push_back(0);
    
    for(int i = 0; i <= h.size() - 2; i++)
    {
        holder.push_back(h.at(i + 1));
    }
    
    return holder;
}

double CubicSpline::F(int i, int j, Data myData)
{
    return (myData.f.at(i) - myData.f.at(j))/(myData.x.at(i) - myData.x.at(j));
}

vector<double> CubicSpline::GetRightSide(Data myData)
{
    vector<double> holder;
    
    holder.push_back(0);
    
    for(int i = 2; i <= myData.x.size() - 1; i++)
    {
        holder.push_back( 3*(F(i, i - 1, myData) - F(i - 1, i - 2, myData)) );
    }
    
    holder.push_back(0);
    
    return holder;
}

void CubicSpline::SolveC(Data myData)
{
    vector<double> A = GetSubDiagonal();
    vector<double> B = GetMainDiagonal();
    vector<double> C = GetSuperDiagonal();
    vector<double> D = GetRightSide(myData);
    double m;
    
    //Tridiagonal Matrix Algorithm or Thomas Algorithm
    C.at(0) = C.at(0)/B.at(0);
    for(int i = 1; i <= C.size() - 1; i++)
    {
        m = B.at(i) - C.at(i - 1)*A.at(i);
        C.at(i) = C.at(i)/m;
    }
    
    D.at(0) = D.at(0)/B.at(0);
    for(int i = 1; i <= D.size() - 1; i++)
    {
        m = B.at(i) - C.at(i - 1)*A.at(i);
        D.at(i) = (D.at(i) - D.at(i - 1)*A.at(i))/m;
    }
    
    c.push_back(D.at(D.size() - 1));
    
    for(int i = D.size() - 2; i >= 0; i--)
    {
        m = D.at(i) - (C.at(i)*c.at(0));
        c.insert(c.begin(), m);
    }
}

void CubicSpline::SolveB(Data myData)
{
    for(int i = 0; i <= h.size() - 1; i++)
    {
        b.push_back(((myData.f.at(i + 1) - myData.f.at(i))/h.at(i)) - (h.at(i)/3)*(2*c.at(i) + c.at(i + 1)));
    }
}

void CubicSpline::SolveD()
{
    for(int i = 0; i <= h.size() - 1; i++)
    {
        d.push_back((c.at(i + 1) - c.at(i))/(3*h.at(i)));
    }
}

void CubicSpline::SolveCoefficients(Data myData)
{
    SolveA(myData);
    SolveH(myData);
    SolveC(myData);
    SolveB(myData);
    SolveD();
}

double CubicSpline::S(double X, Data myData)
{
    double H;
    
    for(int i = 0; i <= myData.x.size() - 2; i++)
    {
        if( (X >= myData.x.at(i)) && (X <= myData.x.at(i + 1)) )
        {
            H = X - myData.x.at(i);
            return a.at(i) + b.at(i)*H + c.at(i)*pow(H, 2) + d.at(i)*pow(H, 3);
        }
    }
}

//debugging only
void CubicSpline::ShowCoefficient(string str, int precision)
{
    cout.precision(precision);
    cout << fixed;
    if(str[0] == 'a')
    {
        for(int i = 0; i <= 79; i++)
        {
            cout << "-";
        }
        
        for(int i = 0; i <= a.size() - 1; i++)
        {
            cout << str << "[" << i << "] = " << a.at(i) << endl;
        }
    }
    else if(str[0] == 'h')
    {
        for(int i = 0; i <= 79; i++)
        {
            cout << "-";
        }
        
        for(int i = 0; i <= h.size() - 1; i++)
        {
            cout << str << "[" << i << "] = " << h.at(i) << endl;
        }
    }
    else if(str[0] == 'c')
    {
        for(int i = 0; i <= 79; i++)
        {
            cout << "-";
        }
        
        for(int i = 0; i <= c.size() - 1; i++)
        {
            cout << str << "[" << i << "] = " << c.at(i) << endl;
        }
    }
    else if(str[0] == 'b')
    {
        for(int i = 0; i <= 79; i++)
        {
            cout << "-";
        }
        
        for(int i = 0; i <= b.size() - 1; i++)
        {
            cout << str << "[" << i << "] = " << b.at(i) << endl;
        }
    }
    else if(str[0] == 'd')
    {
        for(int i = 0; i <= 79; i++)
        {
            cout << "-";
        }
        
        for(int i = 0; i <= d.size() - 1; i++)
        {
            cout << str << "[" << i << "] = " << d.at(i) << endl;
        }
    }
}
