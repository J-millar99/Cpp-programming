#include <iostream>

using namespace std;

int main(void)
{
    const int num = 12;
    const int *ptr = &num;
    const int *(&ref) = ptr;

    cout<<"포인터 변수로 출력: "<<*ptr<<endl;
    cout<<"참조자로 출력: "<<*ref<<endl;
    return 0;
}