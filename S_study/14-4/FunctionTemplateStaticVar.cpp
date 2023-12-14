#include <iostream>
using namespace std;

template <typename T>
void ShowStaticValue(void)
{
    static T num = 0;
    num += 1;
    cout << num << " ";
};

int main()
{
    ShowStaticValue<int>();
    ShowStaticValue<int>();
    ShowStaticValue<int>();
    cout << endl;

    ShowStaticValue<double>();
    ShowStaticValue<double>();
    ShowStaticValue<double>();
    cout << endl;

    ShowStaticValue<long>();
    ShowStaticValue<long>();
    ShowStaticValue<long>();
    cout << endl;
    return 0;
}