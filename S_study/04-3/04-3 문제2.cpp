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
            HandleString(name, inputName);
            HandleString(companyName, inputCompanyName);
            HandleString(phoneNumber, inputPhoneNumber);
            position = inputPosition;
        }
        void ShowNameCardInfo() const
        {
            cout<<"이름: "<<name<<endl;
            cout<<"회사: "<<companyName<<endl;
            cout<<"전화번호: "<<phoneNumber<<endl;
            cout<<"직급: ";
            COMP_POS::ShowPositionInfo(position);
        }
        void HandleString(char *(&s1), const char *(&s2))
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
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}