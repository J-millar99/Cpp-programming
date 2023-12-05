#include <iostream>

int main(void)
{
    int num;

    std::cout<<"구구단 출력 프로그램입니다."<<std::endl;
    std::cout<<"단을 입력하세요: ";
    std::cin>>num;

    for (int i = 1; i < 10; i++)
        std::cout<<num<<" x "<<i<<" = "<<num * i<<std::endl;
    return 0;
}