// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

#if 0
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = 42;
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 100, 200 };

    // Direct Initialization(직접 초기화)
    int n2(42);
    int x2[3] { 10, 20, 30 };
    Point pt2 { 100, 200 };
}
#endif

// C++11, Uniform Initialization(일관된 초기화)
#if 0
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = { 42 };
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 100, 200 };

    // Direct Initialization(직접 초기화)
    int n2 { 42 };
    int x2[3] { 10, 20, 30 };
    Point pt2 { 100, 200 };
}
#endif

// C/C++ 문제점
// => 암묵적인 변환으로 인해 오류가 발생할 가능성이 있습니다.
#if 0
int main()
{
    double d1 = 3.14;
    int n = d1; // 암묵적인 변환

    long long l = 100000000000000;
    int n2 = l;

    printf("%d\n", n);
    printf("%d\n", n2);
}
#endif

// - Uniform Initialization
// => 다른 타입 간의 암묵적인 변환이 허용되지 않습니다.
//   : Preventing Narrow
int main()
{
    double d1 = { 3.14 };

    if (d1 > INT_MAX || d < INT_MIN) {
        std::cout << "error!" << std::endl;
    } else {
        int n = { (int)d1 };
        printf("n: %d\n", n);
    }

    long long l = 100000000;
    if (l > INT_MAX || l < INT_MIN) {
        // ...
    } else {
        int n2 = { (int)l };
    }
}
