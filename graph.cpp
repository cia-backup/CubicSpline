#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "dataclass.h"
#include "cubicspline.h"

void Graph(double lowerbound, double upperbound, int points, CubicSpline coefficient, Data myData, int precision)
{
    double step = (upperbound - lowerbound)/(points - 1);
    int currentPoints = 0;
    
    cout << "x\t\tf(x)" << endl;
    for(int i = 0; i <= 79; i++)
    {
        cout << "-";
    }
    
    cout.precision(precision);
    for(double x = lowerbound; x <= upperbound; x += step)
    {
        cout << fixed;
        cout << x << "\t" << coefficient.S(x, myData) << endl;
        currentPoints++;
    }
    
    if(currentPoints == points - 1)
    {
        cout << fixed;
        cout << upperbound << "\t" <<  coefficient.S(upperbound, myData) << endl;
    }
}

void GraphToFile(double lowerbound, double upperbound, int points, CubicSpline coefficient, Data myData, int precision, string textfile)
{
    double step = (upperbound - lowerbound)/(points - 1);
    int currentPoints = 0;
    
    ofstream newFile;
    newFile.open(textfile.c_str());
    
    cout.precision(precision);
    for(double x = lowerbound; x <= upperbound; x += step)
    {
        newFile << fixed;
        newFile << x << "\t" << coefficient.S(x, myData) << endl;
        currentPoints++;
    }
    
    if(currentPoints == points - 1)
    {
        newFile << fixed;
        newFile << upperbound << "\t" <<  coefficient.S(upperbound, myData) << endl;
    }
    
    newFile.close();
}
