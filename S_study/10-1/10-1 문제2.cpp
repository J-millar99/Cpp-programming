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
		Point &operator+=(const Point &pos)
		{
			xpos += pos.xpos;
			ypos += pos.ypos;
			return (*this);
		}
		Point &operator-=(const Point &pos)
		{
			xpos -= pos.xpos;
			ypos -= pos.ypos;
			return (*this);
		}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);

	pos1.ShowPosition();
	pos1.operator+=(pos2);
	pos1.ShowPosition();
	pos1.operator-=(pos2);
	pos1.ShowPosition();
	return 0;
}