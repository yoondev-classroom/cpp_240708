// 22_상수멤버함수.cpp
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

    // C++에서 멤버 함수가 내부의 값을 변경하지 않기 위해서는
    // '상수 멤버 함수'를 이용해야 합니다.

    // => 상수 멤버 함수는 모든 멤버를 상수 취급합니다.
    //    int x -> const int x
    //    int y -> const int y

    // => 상수 멤버 함수에서는 객체 내부의 상태가 변경되지 않습니다.
    // => 멤버 함수가 객체 내부의 상태를 변경하지 않는 경우,
    //    반드시 상수 멤버 함수로 만들어야 합니다.
    void Print() const
    {
        // x = 10;
        std::cout << x << ", " << y << std::endl;
    }

    void SetX(int a)
    {
        x = a;
    }

    void SetY(int b)
    {
        y = b;
    }
};

void foo(const Point& pt)
{
    // const&로 참조하는 되는 객체의
    // 상수 멤버 함수만 호출이 가능합니다.
    pt.Print();
}

void foo(const Point* pt)
{
    // const*를 통해 참조되는 객체의 상수 멤버 함수만 호출이 가능합니다.
    pt->Print();
}

#if 0
int main()
{
    Point pt { 10, 20 };
    foo(pt);
}
#endif

#if 0
int main()
{
    const Point pt { 10, 20 };
    // 상수 객체
    // => 값을 초기화 이후에 변경할 수 없습니다.
    //  : 불변 객체(Immutable Object)

    // pt.SetX(100); /* 컴파일 오류! */
    // pt.SetY(200);

    // 상수 객체는 상수 멤버 함수만 호출이 가능합니다.
    pt.Print();
}
#endif

// * 정리
// 1) 상수 객체는 상수 멤버 함수만 호출이 가능합니다.
//    const Point pt;

// 2) const&를 통해서 참조되는 객체의 상수 멤버 함수만
//    호출이 가능합니다.
//    const*를 통해서 참조되는 객체의 상수 멤버 함수만
//    호출이 가능합니다.
//    const Point& r = pt;
//    r.Print();
//    const Point* p = &pt;
//    p->Print();
