#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
    private:
        Point upLeft;
        Point lowRight;
    public:
        bool InitMembers(const Point &ul, const Point &lr);
        void ShowRecInfo() const;
};

#endif