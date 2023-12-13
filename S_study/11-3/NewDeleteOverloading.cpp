#include <iostream>
using namespace std;
/*
	객체를 생성하지 않았는데 어떻게 new 연산자를 실행할 수 있는가?
	static으로 선언이 되었다면 먼저 메모리 공간에 올라갈 수 있다.
	그래서 new, delete는 static으로 간주된다.
*/

class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
		friend ostream &operator<<(ostream &os, const Point &pos);
	
	void *operator new (size_t size)
	{
		cout << "operator new : " << size << endl;
		void *adr = new char[size];
		return adr;
	}

	void operator delete (void *adr)
	{
		cout << "operator delete ()" << endl;
		delete []adr;
	}
};

ostream &operator<<(ostream &os, const Point &pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point *ptr = new Point(3, 4);
	cout << *ptr;
	delete ptr;
	return 0;
}