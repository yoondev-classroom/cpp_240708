// 12_nullptr.cpp
#include <iostream>
using namespace std;

// 1. 정수 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.

// #define NULL (void*)0

#if 0
int main()
{
    int* p = NULL;
    std::cout << p << std::endl;

    int* p2 = 0;
    std::cout << p2 << std::endl;

    // int* p3 = 100;
}
#endif

#if 0
void foo(int n) { std::cout << "int" << std::endl; }
void foo(int* n) { std::cout << "int*" << std::endl; }

int main()
{
    foo(0);
    foo(NULL);
    // 정수 타입인지, 포인터 타입인지 모호합니다.
    // => 타입 안정성이 없다.
}
#endif

// C++11, NULL을 대체하는 nullptr이 도입되었습니다.
void foo(int n) { std::cout << "int" << std::endl; }
void foo(int* n) { std::cout << "int*" << std::endl; }

// nullptr은 nullptr_t의 타입으로 설계되어 있습니다.

int main()
{
    foo(0);
    foo(nullptr);

    int* p1 = nullptr;
    char* p2 = nullptr;

    if (p1) { // 거짓으로 판단됩니다.
    }
}
