// 15_생성자2.cpp
#include <iostream>
using namespace std;

#include <cstdlib>
// malloc, free

// 1. malloc을 이용해서 객체의 메모리를 할당한 경우,
//    생성자가 호출되지 않습니다.
//    free를 통해서 객체의 메모리를 해지한 경우,
//    소멸자가 호출되지 않습니다.
#if 0
int main()
{
    Object* p = static_cast<Object*>(malloc(sizeof(Object)));

    free(p);
}
#endif

// 2. new를 통해 객체를 생성한 경우, 생성자가 호출됩니다.
//   delete를 통해 객체를 해지한 경우, 소멸자가 호출됩니다.

#if 0
class Object {
public:
    Object() { std::cout << "Object()" << std::endl; }
    ~Object() { std::cout << "~Object()" << std::endl; }
};

int main()
{
    Object* p = new Object;
    delete p;
}
#endif

class Point {
public:
    Point() { std::cout << "Point()" << std::endl; }
    Point(int a, int b)
    {
        std::cout << "Point(int, int)" << std::endl;
    }

    ~Point() { std::cout << "~Point()" << std::endl; }
};

#if 0
int main()
{
    Point* pt1 = new Point; // Point()
    Point* pt2 = new Point(10, 20); // Point(int, int)
    Point* pt3 = new Point { 10, 20 }; // Point(int, int)

    delete pt1;
    delete pt2;
    delete pt3;
}
#endif

int main()
{
    Point* pt = new Point[3] {
        Point {}, Point { 10, 20 }, Point { 10, 20 }
    };

    delete[] pt;
}
