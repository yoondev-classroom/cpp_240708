// 8_제어문.cpp
#include <iostream>
using namespace std;

// Control Statement
// - if, if-else, if-else if-else
// - while, for, do-while
// - switch

#if 0
int main()
{
    int x[5] = { 10, 20, 30 }; // 컨테이너

    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i) {
        std::cout << x[i] << std::endl;
    }

    int n = 42;
    auto& e = n;

    // 요소를 순회하면서 연산을 수행하고 싶다.
    // => 레퍼런스 기반으로 사용하면 됩니다.
    for (auto& e : x) {
        e *= 2;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        std::cout << e << std::endl;
    }
}
#endif

#if 1
#include <string> // std::string

// 0인 경우 성공, 0이 아니면 실패
int process1()
{
    return 0;
}

int process2()
{
    return 0;
}

// C++17, If/Switch Statement with Initializer
enum State {
    TASK_RUNNING,
    TASK_STOPPED,
    TASK_WAIT
};

State GetTaskState() { return TASK_RUNNING; }

int main()
{

    switch (State state = GetTaskState(); state) {
    case State::TASK_RUNNING:
        // ...
        break;
    case State::TASK_STOPPED:
        break;
    case State::TASK_WAIT:
        break;
    default:
        break;
    }

    // 함수가 실패 가능성이 있는 경우, 반드시 반환값을 통해
    // 실패 여부를 체크해야 합니다.
    if (int ret = process1(); ret != 0) {
        // ...
    }

    if (int ret = process2(); ret != 0) {
        // ...
    }

    // C++20
    // - ranged-for with initializer
    for (int x[3] = { 10, 20, 30 }; auto e : x) {
        std::cout << e << std::endl;
    }

    std::string str = "hello";
    for (auto e : str) {
        std::cout << e << std::endl;
    }
}
#endif
