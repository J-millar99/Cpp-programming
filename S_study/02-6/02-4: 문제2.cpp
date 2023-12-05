#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void)
{
    int rNum;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        rNum = rand() % 100;
        cout<<rNum<<" ";
    }
    cout<<endl;
    return 0;
}