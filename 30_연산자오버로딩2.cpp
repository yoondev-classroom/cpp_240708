// 30_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 42;
    std::cout << n;

    double d = 3.14;
    std::cout << d;
}
#endif

#if 0
namespace xstd {
// 실제 cout의 타입입니다.
class ostream {
public:
    void operator<<(int n)
    {
        printf("%d", n);
    }

    void operator<<(double d)
    {
        printf("%lf", d);
    }
};

ostream cout;
}
#endif

namespace xstd {
// 실제 cout의 타입입니다.
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }
};

ostream cout;
// C++ 표준 출력 객체
}

int main()
{
    // std::cout << 42;
    // - std::cout.operator<<(42);

    // std::cout << 3.14;
    // - std::cout.operator<<(3.14);

    xstd::cout << 42 << 3.14;
    // std::cout.operator<<(42)
    //          .operator<<(3.14);
}

#if 0
int main()
{
    xstd::cout << 3.14;

    xstd::cout << 42;
    xstd::cout.operator<<(42);
    // xstd::cout.operator<<(42)
}
#endif
