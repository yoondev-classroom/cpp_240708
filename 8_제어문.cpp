// 8_제어문.cpp
#include <iostream>
using namespace std;

// Control Statement
// - if, if-else, if-else if-else
// - while, for, do-while

#if 0
int main()
{
    int x[5] = { 10, 20, 30 }; // 컨테이너

    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i) {
        std::cout << x[i] << std::endl;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        std::cout << e << std::endl;
    }
}
#endif

#if 1
// 0인 경우 성공, 0이 아니면 실패
int process1()
{
    return 0;
}

int process2()
{
    return 0;
}

// C++17, If Statement with Initializer

int main()
{
    // 함수가 실패 가능성이 있는 경우, 반드시 반환값을 통해
    // 실패 여부를 체크해야 합니다.

    if (int ret = process1(); ret != 0) {
        // ...
    }

    if (int ret = process2(); ret != 0) {
        // ...
    }
}
#endif
