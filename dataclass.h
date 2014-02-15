#ifndef DATACLASS_H_GUARD
#define DATACLASS_H_GUARD

class Data
{
    vector<double> x, f;
    public:
        bool empty();
        void GetData(string);
        void SortData();
        void ShowData();
        friend class CubicSpline;
};

#endif
