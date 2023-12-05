#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
    char s1[100];
    char s2[100];
    char strSrc[100];

    cout<<"첫 번째 문자열 입력: ";
    cin>>s1;
    cout<<"두 번째 문자열 입력: ";
    cin>>s2;

    if (!strcmp(s1, s2))
        cout<<"두 문자열은 동일합니다."<<endl;
    else
        cout<<"두 문자열은 동일하지 않습니다."<<endl;

    cout<<"첫 번째 문자열의 길이: "<<strlen(s1)<<endl;
    cout<<"두 번째 문자열의 길이: "<<strlen(s2)<<endl;

    strcpy(strSrc, s1);
    cout<<"복사된 첫 번째 문자열: "<<strSrc<<endl;
    strcpy(strSrc, s2);
    cout<<"복사된 두 번째 문자열: "<<strSrc<<endl;

    strcat(s1, s2);
    cout<<"두 문자열의 합: "<<s1<<endl;
    return 0;
}