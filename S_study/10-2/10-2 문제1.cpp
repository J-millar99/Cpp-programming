#include <iostream>
using namespace std;

class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{ }

		void ShowPosition() const
		{
			cout << '[' << xpos << ", " << ypos << ']' <<endl;
		}
		Point operator-()
		{
			Point result;

			result.xpos = xpos * -1;
			result.ypos = ypos * -1;
			return result;
		}
};

int main()
{
	Point pos1(1, 2);

	Point pos2 = -pos1;
	pos2.ShowPosition();
	return 0;
}