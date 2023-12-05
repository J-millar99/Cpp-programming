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

class Coldpatient
{
    public:
        void TakeSinivelCap(const SinivelCap &cap) const {cap.Take();}
        void TakeSneezelCap(const SneezeCap &cap) const {cap.Take();}
        void TakeSnuffleCap(const SnuffleCap &cap) const {cap.Take();}
};

int main(void)
{
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    Coldpatient sufferer;

    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezelCap(zcap);
    sufferer.TakeSnuffleCap(ncap);
    return 0;
}