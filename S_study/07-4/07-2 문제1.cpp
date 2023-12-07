#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int width, height;
    
    public:
        Rectangle(int width, int height) : width(width), height(height) {}
        void ShowAreaInfo()
        {
            cout<<"면적: "<<width * height<<endl;
        }
};

class Square : public Rectangle
{
    private:
        int length;
    
    public:
        Square(int length) : Rectangle(length, length) {}
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}