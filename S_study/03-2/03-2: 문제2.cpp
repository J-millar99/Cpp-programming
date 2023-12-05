#include <iostream>

using namespace std;

class Printer
{
    private:
        const char *stringData;
    public:
        void SetString(const char *inputString);
        void ShowString(void);
};

void Printer::SetString(const char *inputString)
{
    stringData = inputString;
}

void Printer::ShowString(void)
{
    cout<<stringData<<endl;
}

int main(void)
{
    Printer pnt;

    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}