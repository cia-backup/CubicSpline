#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void Pause()
{
    cout << "Press the enter key to continue ...";
    cin.get();
}

void Interface()
{
    cout << "Hello dawg! What's poppin' homeboy?\n\n";
    cout << "\t[1] Specify text file to be used\n";
    cout << "\t[2] Show Data\n";
    cout << "\t[3] Graph\n";
    cout << "\t[4] Help\n";
    cout << "\t[5] Exit\n";
}

#include "input.h"
#include "dataclass.h"
#include "cubicspline.h"
#include "graph.h"

int main()
{
    string input;
    Data myData;
    CubicSpline coefficient;
    int precision = 11;
    int choice;
    bool valid = false;
    do
    {
        Interface();
        do
        {
            getline(cin, input);
            valid = Input(choice, input);
        }while(!valid);
        
        switch(choice)
        {
            case 1:
                {
                    myData.GetData("data.txt");
                    break;
                }
            case 2:
                {
                    if(!myData.empty())
                        myData.ShowData();
                    else
                        cout << "ERROR: No data obtained yet.\n\n";
                    break;
                }
            case 3:
                {
                    //graph
                    break;
                }
            case 4:
                {
                    cout<<"This program reads data from a text file and computes for its cubic splines. \n";
                    cout<<"Furthermore, it gives the user the ability to obtain data from a specified file name, that is, it allows the user to choose or create a text file where the data needed will be gathered.\n";
                    cout<<"This text file should contain x and y pairs which may be graphed by the user\n"; 
                    break;
                }
            case 5:
                {
                    Pause();
                    return EXIT_SUCCESS;
                }
            default:
                {
                    cout << "Invalid input, input 1-5 only.\n\n";
                    break;
                }
        }
    }while(choice != 5);
    
    /*
    myData.GetData("data.txt");
    
    if(!myData.empty())
    {
        myData.SortData();
        myData.ShowData();
        coefficient.SolveCoefficients(myData);
        
        //for debugging
        coefficient.ShowCoefficient("a", precision);
        coefficient.ShowCoefficient("h", precision);
        coefficient.ShowCoefficient("c", precision);
        coefficient.ShowCoefficient("b", precision);
        coefficient.ShowCoefficient("d", precision);
        
        cout << endl;
        Graph(3, 9, 13, coefficient, myData, precision);
    }
    */
    Pause();
    return EXIT_SUCCESS;
}

 
