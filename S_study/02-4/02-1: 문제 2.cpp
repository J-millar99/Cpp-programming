#include <iostream>

using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(void)
{
    int val1 = 10;
    int val2 = 20;

    SwapByRef2(val1, val2);
//  SwapByRef2(23, 45);       다음과 같이 호출할 수 없는 이유 서술
    cout<<"val1: "<<val1<<endl;
    cout<<"val2: "<<val2<<endl;
    return 0;
}

/*
    참조자는 변수의 별칭을 붙이는 것이므로, 상수에는 적용할 수 없다.
*/