// 9_레퍼런스.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 100;

    int* pn = &n;

    *pn = 42;
    std::cout << *pn << std::endl;
}
#endif

// 1. C++에서는 레퍼런스 타입이 도입되었습니다.
// => 기존 메모리에 새로운 이름을 부여합니다.
#if 0
int main()
{
    int n = 100;

    int& rn = n;

    rn = 42;
    std::cout << n << std::endl;

    n = 200;
    std::cout << rn << std::endl;
}
#endif

// 2. 포인터와 레퍼런스의 차이를 이해해야 합니다.
// - 포인터: 주소를 가지는 변수입니다.
//  포인터에 변수의 주소를 담아, 접근해서 값을 읽거나 변경할 수 있습니다.
// - 레퍼런스: 기존 메모리에 새로운 이름을 부여합니다.
//  새로운 이름을 통해 값을 읽거나 변경할 수 있습니다.
#if 0
int main()
{
    int n = 100;

    int* pn = &n;

    int& rn = n;

    std::cout << &n << std::endl;
    std::cout << &pn << std::endl;

    std::cout << &n << std::endl;
    std::cout << &rn << std::endl;
}
#endif

#if 0
int main()
{
    // 유효하지 않은 포인터는 반드시 NULL로 초기화해야 합니다.
    int* p = NULL;
    std::cout << p << std::endl;

    // 포인터를 사용하기 전에, 반드시 NULL 체크를 수행해야 합니다.
    // if (p != NULL) {
    if (p) {
        *p = 42;
        std::cout << *p << std::endl;
    }
}
#endif

int main()
{
    int n;

    // int& r;
    // 컴파일 타임 오류가 발생합니다.
    // 레퍼런스는 반드시 초기화해야 합니다.

    int& r = n;
    // C++에서 null 레퍼런스의 개념은 존재하지 않습니다.

    r = 10;
    std::cout << r << std::endl;
    // 레퍼런스는 널이 될수없기 때문에, 널체크가 필요하지 않습니다.
}
