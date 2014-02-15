#ifndef CUBICSPLINE_H_GUARD
#define CUBICSPLINE_H_GUARD

class CubicSpline
{
    vector<double> a, b, c, d, h;
    vector<double> GetSubDiagonal();
    vector<double> GetMainDiagonal();
    vector<double> GetSuperDiagonal();
    vector<double> GetRightSide(Data);
    double F(int, int, Data);
    void SolveA(Data);
    void SolveH(Data);
    void SolveC(Data);
    void SolveB(Data);
    void SolveD();
    
    public:
        void SolveCoefficients(Data);
        double S(double, Data);
        
        //for debugging only
        void ShowCoefficient(string, int);
};

#endif
