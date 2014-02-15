#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "dataclass.h"

bool Data::empty()
{
    if(x.size() == 0)
        return true;
    else
        return false;
}

void Data::GetData(string str)
{
    //erase all elements inside vector first if there is previous getdata
    x.clear();
    f.clear();
    int position = 1;
    double holder;
    fstream file;
    file.open(str.c_str());
    
    while(file >> holder)
    {
        if(position % 2 == 0)
        {
            f.push_back(holder);
        }
        else
        {
            x.push_back(holder);
        }
        
        position++;
    }
    
    if(x.size() != f.size())
    {
        x.pop_back();
    }
    
    file.close();
}

void Data::SortData()
{
    int positionOfSmallest;
    for(int i = 0; i <= x.size() - 1; i++)
    {
        positionOfSmallest = i;
        for(int j = i + 1; j <= x.size() - 1; j++)
        {
            if((x.at(i) > x.at(j)) && (x.at(positionOfSmallest) > x.at(j)))
            {
                positionOfSmallest = j;
            }
        }
        swap(x.at(i), x.at(positionOfSmallest));
        swap(f.at(i), f.at(positionOfSmallest));
    }
}

void Data::ShowData()
{
    cout << "x\t\tf(x)\n";
    cout << "--------------------\n";
    
    for(int i = 0; i <= x.size() - 1; i++)
    {
        cout << x.at(i) << "\t\t" << f.at(i) << endl;
    }
}
