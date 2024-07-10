// 17_초기화리스트3.cpp
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
};

// * 초기화리스트를 반드시 사용해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 멤버

class Rect {
    // Point leftTop { 10, 20 }; // 멤버 초기화, C++11
    Point leftTop;

public:
    Rect()
        : leftTop { 10, 20 } // 초기화리스트
    {
    }

    // 컴파일러가 생성하는 기본 생성자의 형태
    // public:
    //  Rect() : leftTop{} {}
};

int main()
{
    Rect r;
}
