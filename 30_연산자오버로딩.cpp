// 30_연산자오버로딩.cpp
#include <iostream>
using namespace std;

#if 0
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

    // pt1.Add(pt2);
    // Point::Add(&pt1, pt2);

    //       (Point* this, const Point& rhs)
    Point Add(const Point& rhs)
    {
        Point result { x + rhs.x, y + rhs.y };
        return result;
    }

    friend Point Add(const Point& lhs, const Point& rhs);
};

Point Add(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x + rhs.x, lhs.y + rhs.y };
    return result;
}

int main()
{
    Point pt1 { 10, 20 };
    Point pt2 { 100, 200 };

    // Point 객체 간의 덧셈 연산을 제공하고 싶습니다.
    //   : pt1 + pt2
    // 1) 일반 함수
    Point result1 = Add(pt1, pt2);
    result1.Print();

    // 2) 멤버 함수
    Point result2 = pt1.Add(pt2);
    result2.Print();
}
#endif

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

#if 0
    Point operator+(const Point& rhs)
    {
        Point result { x + rhs.x, y + rhs.y };
        return result;
    }
#endif

    friend Point operator+(const Point& lhs, const Point& rhs);
};

Point operator+(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x + rhs.x, lhs.y + rhs.y };
    return result;
}

int main()
{
    Point pt1 { 10, 20 };
    Point pt2 { 100, 200 };

    Point result = pt1 + pt2;
    result.Print();
    //  멤버함수: pt1.operator+(pt2);
    //  일반함수: operator+(pt1, pt2);

    // 객체를 대상으로 연산자를 사용할 경우,
    // 약속된 일반 함수 / 멤버 함수를 호출하는
    // 문법이 있습니다.
    //  => 연산자 오버로딩
}
