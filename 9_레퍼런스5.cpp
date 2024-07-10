// 9_레퍼런스5.cpp
#include <iostream>
using namespace std;

#if 1
int main()
{
    int n;

    n = 10;
    //  n: lvalue
    //   - 왼쪽에 올수 있는 것
    // 10: rvalue
    //   - 왼쪽에 올수 없는 것

    int& r = n; /* OK */
    // lvalue reference
    //   : lvalue만 참조 가능합니다.

    // int& r2 = 10; /* 에러 */
    //   : 10은 rvalue이기 때문에, lvalue reference를 사용할 수
    //     없습니다.

    // const lvalue reference
    //   : const lvalue, lvalue, rvalue도 참조할 수 있습니다.
    const int& cr1 = n; /* OK */
    const int& cr2 = 10; /* OK */
}
#endif

void foo(const int& r)
{
    std::cout << "const lvalue reference" << std::endl;
}

void foo(int& r)
{
    std::cout << "lvalue reference" << std::endl;
}

// C++11, rvalue reference
// : rvalue를 참조할 수 있습니다.
void foo(int&& r)
{
    std::cout << "rvalue reference" << std::endl;
}

int main()
{
    int n;
    foo(n);

    const int c = 100;
    foo(c);

    foo(100);
}
