/*
    함수 오버로딩

    이름만으로 함수를 구분하는 c언어와는 다르게, c++에서는 함수를 구분할 때 매개변수를 추가로 본다.

    int SimpleFunc(int a = 10)
    {
        return a + 1;
    }

    int SimpleFunc(void)
    {
        return 10;
    }

    다음 두 함수를 보자.

    첫 번째 함수는 int형 매개변수를 전달받고, 매개변수를 지정하지 않았을 때 디폴트 값 10으로 지정된다.
    두 번째 함수는 인자를 받지 않는다.

    그렇다면 매개변수를 전달하지 않았을 때 함수는 10을 나타낼 것인가 11을 나타낼 것인가를 컴파일러가 알 수가 없을 것이다. 나도 헷갈린다.
    실제로 컴파일러가 "ambiguous"에러를 출력한다.
*/
#include <iostream>

int SimpleFunc(int a = 10)
{
    return a + 1;
}

int SimpleFunc(void)
{
    return 10;
}

int main(void)
{
    std::cout<<SimpleFunc()<<std::endl;
    std::cout<<SimpleFunc(5)<<std::endl;
    return 0;
}