#include <iostream>

int main(void)
{
    int salePrice;
    
    while (1)
    {
        std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin>>salePrice;
        if (salePrice == -1)
            break ;
        std::cout<<"이번 달 급여: "<<50 + (salePrice * 0.12)<<"만원\n";
    }
    std::cout<<"프로그램을 종료합니다."<<std::endl;
    return 0;
}