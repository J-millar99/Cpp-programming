#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK = 1,
        SENIOR,
        ASSIST,
        MANAGER = 4
    };


    void ShowPositionInfo(int position)
    {
        switch (position)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "매니저" << endl;
        }
    }
}

class NameCard
{
    private:
        char *name;
        char *companyName;
        char *phoneNumber;
        int position;
    
    public:
        NameCard(const char *inputName, const char *inputCompanyName, const char *inputPhoneNumber, int inputPosition)
        {
            HandleString(name, (char *)inputName);
            HandleString(companyName, (char *)inputCompanyName);
            HandleString(phoneNumber, (char *)inputPhoneNumber);
            position = inputPosition;
        }
        NameCard(NameCard &copy) : position(copy.position)
        {
            HandleString(name, copy.name);
            HandleString(companyName, copy.companyName);
            HandleString(phoneNumber, copy.phoneNumber);
        }
        void ShowNameCardInfo() const
        {
            cout<<"이름: "<<name<<endl;
            cout<<"회사: "<<companyName<<endl;
            cout<<"전화번호: "<<phoneNumber<<endl;
            cout<<"직급: ";
            COMP_POS::ShowPositionInfo(position);
        }
        void HandleString(char *(&s1), char *s2)
        {
            s1 = new char[strlen(s2) + 1];
            strcpy(s1, s2);
        }
        ~NameCard()
        {
            delete []name;
            delete []companyName;
            delete []phoneNumber;
        }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}