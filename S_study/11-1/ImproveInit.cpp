#include <iostream>
using namespace std;

class AAA
{
	private:
		int num;
	public:
		AAA(int n = 0) : num(n)
		{
			cout << "AAA(int n = 0)" << endl;
		}
		AAA(const AAA &ref) : num(ref.num)
		{
			cout << "AAA(const AAA &ref)" << endl;
		}
		AAA &operator=(const AAA &ref)
		{
			num = ref.num;
			cout << "operator=(const AAA &ref)" << endl;
			return *this;
		}
};

class BBB
{
	private:
		AAA mem;
	public:
		BBB(const AAA &ref) : mem(ref) { } // 복사 생성자 호출
};

class CCC
{
	private:
		AAA mem;
	public:
		CCC(const AAA &ref) { mem = ref; } // 대입 연산자 호출
};

/*
	이니셜라이저를 이용하여 BBB, CCC를 생성한다.
	BBB의 객체생성은 선언과 동시에 초기화가 이루어지는 형태이고 (호출 1번으로 성능 향상)
	CCC의 객체생성은 생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하는 것이다. (호출 2번)
*/

int main(void)
{
	AAA obj1(12);
	cout << "*************************" << endl;
	BBB obj2(obj1);
	cout << "*************************" << endl;
	CCC obj3(obj1);
	return 0;
}