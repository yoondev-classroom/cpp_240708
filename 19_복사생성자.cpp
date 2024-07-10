// 19_복사생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면
//  컴파일러는 아무일도 하지 않는 기본 생성자를 제공합니다.

// 2. 사용자가 생성자를 1개라도 제공하면,
//   컴파일러는 기본 생성자를 제공하지 않습니다.

// 3. 사용자가 자신과 동일한 타입의 객체를 인자로 전달받는
//   생성자(복사 생성자)를 제공하지 않는다면,
//   컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.

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

    Point(const Point& rhs) // 복사 생성자
        : x { rhs.x }
        , y { rhs.y }
    {
        std::cout << "Point(const Point&)" << std::endl;
    }

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    Point pt1 { 10, 20 };
    pt1.Print();

    Point o1 = pt1;
    Point o2(pt1);
    Point o3 = { pt1 };
    Point other { pt1 };
    other.Print();
}
#endif

#if 0
class Sample {
public:
};
#endif
// 1) 컴파일러가 제공하는 아무일도 하지 않는 기본 생성자
// 2) 컴파일러가 제공하는 멤버를 복사하는 복사 생성자

#if 0
class Sample {
public:
    Sample(const Sample& rhs) { }
};
// 복사 생성자도 생성자이기 때문에,
// 컴파일러는 기본 생성자를 제공하지 않습니다.
#endif

class Sample {
public:
    Sample() = default;
    Sample(const Sample& rhs) = default;
};

int main()
{
    Sample s1;
    Sample s2 = s1;
}
