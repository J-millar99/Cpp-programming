#include <iostream>

using namespace std;

class SinivelCap
{
    public:
        void Take() const {cout<<"콧물이 싹~ 납니다."<<endl;}
};

class SneezeCap
{
    public:
        void Take() const {cout<<"재채기가 멎습니다."<<endl;}
};

class SnuffleCap
{
    public:
        void Take() const {cout<<"코가 뻥 뚫립니다."<<endl;}
};

class CONTAC600
{
    private:
        SinivelCap sin;
        SneezeCap sne;
        SnuffleCap snu;

    public:
        void Take() const
        {
            sin.Take();
            sne.Take();
            snu.Take();
        }
};

class Coldpatient
{
    public:
        void TakeCONTAC600(const CONTAC600 &cap) const {cap.Take();}
};

int main(void)
{
    CONTAC600 pill;

    Coldpatient sufferer;

    sufferer.TakeCONTAC600(pill);
    return 0;
}