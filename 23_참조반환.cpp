// 23_참조반환.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const { cout << x << ", " << y << endl; }

    Point& Move(int dx, int dy)
    {
        x += dx;
        y += dy;

        return *this;
    }
};

int main()
{
    Point pt { 10, 20 };

    // pt.Move(100, 100);
    // pt.Move(100, 100);
    // pt.Move(100, 100);

    // pt.Move(100, 100)->Move(100, 100)->Move(100, 100);

    // Chaining
    // => 자기 자신의 참조를 반환하는 멤버 함수
    pt.Move(100, 100)
        .Move(100, 100)
        .Move(100, 100);

    pt.Print();
}
