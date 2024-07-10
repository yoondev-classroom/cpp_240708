// 15_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 인자 없는
//    생성자를 제공합니다.

// 인자 없는 생성자 => 기본 생성자(Default Constructor)

#if 0
class Point {
    int x;
    int y;

    // public: Point() {}
};

int main()
{
    Point pt;
}
#endif

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 인자 없는 생성자를 제공하지 않습니다.

#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point pt { 10, 20 };
}
#endif

// 3. 생성자는 인자 정보가 다를 경우, 여러개 제공할 수 있습니다.
//   => 오버로딩이 가능합니다.
//   => 객체를 생성하는 다양한 방법을 제공할 수 있습니다.
class Point {
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point pt { 10, 20 };
    Point pt2;
}
