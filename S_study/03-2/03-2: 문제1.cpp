#include <iostream>

using namespace std;

class Calculator
{
    private:
        int addCnt;
        int divCnt;
        int minCnt;
        int mulCnt;
    public:
        void Init(void);
        double Add(double a, double b);
        double Div(double a, double b);
        double Min(double a, double b);
        double Mul(double a, double b);
        void ShowOpCount(void);
};

void Calculator::Init(void)
{
    addCnt = 0;
    divCnt = 0;
    minCnt = 0;
    mulCnt = 0;
}

double Calculator::Add(double a, double b)
{
    addCnt++;
    return (a + b);
}

double Calculator::Div(double a, double b)
{
    divCnt++;
    return (a / b);
}

double Calculator::Min(double a, double b)
{
    minCnt++;
    return (a - b);
}

double Calculator::Mul(double a, double b)
{
    mulCnt++;
    return (a * b);
}

void Calculator::ShowOpCount(void)
{
    cout<<"덧셈: "<<addCnt<<" ";
    cout<<"뺄셈: "<<minCnt<<" ";
    cout<<"곱셈: "<<mulCnt<<" ";
    cout<<"나눗셈: "<<divCnt<<" ";
    cout<<endl;
}

int main(void)
{
    Calculator cal;

    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cout<<"1.2 x 1.2 = "<<cal.Mul(1.2, 1.2)<<endl;
    cal.ShowOpCount();
    return 0;
}