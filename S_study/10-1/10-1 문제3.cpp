#include <iostream>
using namespace std;

class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{}

		void ShowPosition() const
		{
			cout << '[' << xpos << ", " << ypos << ']' << endl;
		}
		friend bool operator==(const Point &pos1, const Point &pos2);
		friend bool operator!=(const Point &pos1, const Point &pos2);
};

bool operator==(const Point &pos1, const Point &pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
	if (operator==(pos1, pos2) == true)
		return false;
	else
		return true;
}

void TrueOrFalse(bool value)
{
	if (value == true)
		cout << "True!" << endl;
	else
		cout << "False!" << endl;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);

	TrueOrFalse(operator==(pos1, pos2));
	TrueOrFalse(operator!=(pos1, pos2));
	return 0;
}