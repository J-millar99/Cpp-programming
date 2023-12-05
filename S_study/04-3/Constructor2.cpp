#include <iostream>

using namespace std;

class SimpleClass
{
    private:
        int num1, num2;
    
    public:
        SimpleClass(int n1 = 0, int n2 = 0)
        {
            num1 = n1;
            num2 = n2;
        }
        void ShowData() const
        {
            cout<<num1<<' '<<num2<<endl;
        }
};

int main(void)
{
    SimpleClass sc1();          //객체 생성인지 함수의 원형 선언인지 알 수 없으므로 함수의 원형 선언으로만 약속
                                //empty parentheses interpreted as a function declaration
    SimpleClass mysc = sc1();
    mysc.ShowData();

    return 0;
}

void test()
{
    cout<<"hello"<<endl;
}

SimpleClass sc1()
{
    SimpleClass sc(20, 30);
    return sc;
}