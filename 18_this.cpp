// 18_this.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
// void Point::Set(Point* this, int a, int b)
#if 0
    void Set(int a, int b)
    {
        std::cout << this << std::endl;
        this->x = a;
        this->y = b;
    }
#endif

    // implicit object parameter
    // void Set(Point* this, int x, int y)
    void Set(int x, int y)
    {
        // 명시적으로 this를 사용해야 합니다.
        this->x = x;
        this->y = y;
    }

    // C++23부터는 멤버 함수를 만들 때,
    // 객체를 직접 전달 받을 수 있습니다.
    // - explicit object parameter
    void Set2(this Point& self, int x, int y)
    {
        self.x = x;
        self.y = y;
    }
};

void Set(int x, int y)
{
}

int main()
{
    Set(10, 20);
    /*
        mov     edx, 20
        mov     ecx, 10
        call    void Set(int,int)
    */

    Point pt1, pt2;

    pt1.Set(10, 20);
    // Point::Set(&pt1, 10, 20);
    /*
        mov     r8d, 20
        mov     edx, 10
        lea     rcx, QWORD PTR pt$[rsp] ; rcx = &pt
        call    void Point::Set(int,int)

    */

    pt2.Set2(100, 200);
    // Point::Set(&pt2, 100, 200);
}
