// 18_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이점을 이해해야 합니다.
// => 초기화: 변수를 메모리에 할당하면서, 초기값을 지정하는 행위
//     대입: 이미 할당된 메모리의 값을 변경하는 행위
#if 0
int main()
{
    int n;
    n = 10; // 대입

    int n2 = 10; // 초기화

    std::cout << n << std::endl;
    std::cout << n2 << std::endl;
}
#endif

#if 0
// 2. 반드시 초기화가 필요한 경우 2가지
// 1) const
// 2) reference
int main()
{
    const int n = 10;
    // n = 100; // 오류!

    int x = 100;
    int& rx = x;
}
#endif

// 3. 생성자에서 멤버 데이터를 초기화하기 위해서는
//   "초기화 리스트" 문법을 이용해야 합니다.
//  => 초기화 리스트는 생성자에서만 사용이 가능합니다.

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

#if 0
    Point(int a, int b)
    {
        x = a; /* 초기화가 아니라 대입입니다. */
        y = b;
    }
#endif

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    Point pt { 10, 20 };
    pt.Print();
}
#endif

// 4. 초기화 리스트를 반드시 사용해야 하는 경우
//   1) const 멤버
//   2) reference 멤버

class Sample {
    const int c;
    int& r;

public:
    Sample(const int a, int& b)
        : c { a }
        , r { b }
    {
        // c = a;
        // b = r;
    }
};

int main()
{
    int n = 100;
    const int c = 42;
    Sample s { c, n };
}
