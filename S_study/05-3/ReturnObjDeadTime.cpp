#include <iostream>
using namespace std;

class SoSimple
{
    private:
        int num;
    
    public:
        SoSimple(int n) : num(n)
        {
            cout<<"New Object: "<<this<<endl;
        }
        SoSimple(const SoSimple &copy) : num(copy.num)
        {
            cout<<"New Copy obj: "<<this<<endl;
        }
        ~SoSimple()
        {
            cout<<"Destroy obj: "<<this<<endl;
        }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout<<"Parm ADR: "<<&ob<<endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj);

    cout<<endl;
    SoSimple tempRef = SimpleFuncObj(obj); // 임시객체와의 대입 연산은 변수 이름을 할당해 줄 뿐이다. 그래서 복사자가 생성되지 않았다.
    cout<<"Return Obj "<<&tempRef<<endl;
    return 0;
}