#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
    private:
        char *name;
        int age;

    public:
        MyFriendInfo(const char *friName, int friAge) : age(friAge)
        {
            name = new char[strlen(friName) + 1];
            strcpy(name, friName);
        }
        ~MyFriendInfo()
        {
            delete []name;
        }
        void ShowMyFriendInfo() const
        {
            cout<<"이름: "<<name<<endl;
            cout<<"나이: "<<age<<endl;
        }
};

class MyFriendDetailInfo : public MyFriendInfo
{
    private:
        char *addr;
        char *phone;
    
    public:
        MyFriendDetailInfo(const char *friName, int friAge, const char *friAddr, const char *friPhone)
            : MyFriendInfo(friName, friAge)
        {
            addr = new char[strlen(friAddr) + 1];
            strcpy(addr, friAddr);
            phone = new char[strlen(friPhone) + 1];
            strcpy(phone, friPhone);
        }
        ~MyFriendDetailInfo()
        {
            delete []addr;
            delete []phone;
        }
        void ShowMyFriendDetailInfo() const
        {
            ShowMyFriendInfo();
            cout<<"주소: "<<addr<<endl;
            cout<<"전화: "<<phone<<endl<<endl;
        }
};

int main(void)
{
    MyFriendInfo friend1("신짱구", 5);
    friend1.ShowMyFriendInfo();

    cout<<endl;

    MyFriendDetailInfo friend2("김철수", 5, "서울 특별시", "010-1234-5678");
    friend2.ShowMyFriendDetailInfo();
    return 0;
}