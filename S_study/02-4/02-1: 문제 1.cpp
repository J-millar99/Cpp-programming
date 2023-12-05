#include <iostream>

using namespace std;

void IncreaseOne(int &ref)
{
    ref = ref + 1;
}

void ChangeSing(int &ref)
{
    ref *= -1;
}

int main(void)
{
    int num;

    cout<<"Input num: ";
    cin>>num;
    IncreaseOne(num);
    cout<<"IncreaseOne: "<<num<<endl;
    ChangeSing(num);
    cout<<"ChangeSign: "<<num<<endl;
    return 0;
}