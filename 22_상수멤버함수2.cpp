// 22_상수멤버함수2.cpp
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
    void Move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

class Rect {
    Point leftTop;

public:
    Rect(int x, int y)
        : leftTop { x, y }
    {
    }

    // 비상수 멤버 함수와 상수 멤버 함수를 동시에 제공할 수 있습니다.
    Point& GetLeftTop() { return leftTop; }
    const Point& GetLeftTop() const { return leftTop; }

    // Point GetLeftTop() const { return leftTop; }
    // => 객체의 상태를 외부에서 변경할 수 없도록, 복사해서 반환합니다.

    void Print() const { leftTop.Print(); }
};

// * 상수 멤버 함수만 제공하는 경우
//       Rect r;  -> 상수 멤버 함수
// const Rect r;  -> 상수 멤버 함수
// const Rect* r; -> 상수 멤버 함수
// const Rect& r; -> 상수 멤버 함수

// * 비상수 멤버 함수만 제공하는 경우
//       Rect r;  -> 비상수 멤버 함수
// const Rect r;  -> X
// const Rect* r; -> X
// const Rect& r; -> X

// * 상수 멤버 함수 / 비상수 멤버 함수를 모두 제공할경우
//       Rect r;  -> 비상수 멤버 함수
// const Rect r;  -> 상수 멤버 함수
// const Rect* r; -> 상수 멤버 함수
// const Rect& r; -> 상수 멤버 함수

int main()
{
    Rect r { 10, 20 };
    Point& pt = r.GetLeftTop();
    pt.Move(100, 200);

    r.Print();
}
