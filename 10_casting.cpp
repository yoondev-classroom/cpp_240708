// 10_casting.cpp
#include <iostream>
using namespace std;

// 옛날에 만들어진 라이브러리 함수
void print(char* str)
{
    printf("%s\n", str);
}

// C/C++에서는 명시적인 캐스팅이 필요한 경우가 있습니다.
// 1) Uniform Initialization
// 2) void*를 구체적인 포인터 타입으로의 변환
// 3) 메모리를 재해석
// 4) const T* -> T*
//    const T& -> T&
#if 0
int main()
{
    double d { 3.14 };
    int n { (int)d };

    void* pv = NULL;
    int a = 10;
    char c = 'A';

    // void*는 모든 타입의 주소를 저장할 수 있습니다.
    pv = &a;
    std::cout << *(int*)pv << std::endl;

    pv = &c;
    std::cout << *(char*)pv << std::endl;

    // void* -> T* 타입으로의 암묵적인 변환이 허용되지 않기 때문에
    // 명시적인 캐스팅이 필요합니다.
    char* pc = (char*)pv;

    // 메모리를 재해석
    int x = 0x12345678;
    char* px = (char*)&x;

    printf("%X\n", *(px + 0));
    printf("%X\n", *(px + 1));
    printf("%X\n", *(px + 2));
    printf("%X\n", *(px + 3));

    const char* str = "hello";
    // 문자열을 참조할 때, 반드시 읽기 전용 포인터를 사용해야 합니다.

    // 문제: const로 인한 타입의 불일치 문제
    // char* p = str;
    // print(str);

    // const T* -> T*

    char* p = (char*)str;
    print((char*)str);
}
#endif

// 핵심: C의 캐스팅은 용도와 목적에 따라 구분되지 않습니다.
//   C++은 용도와 목적에 따라 4가지 종류의 캐스팅 연산자를 제공합니다.

// 1) static_cast
//   : 가장 기본적인 C++의 캐스팅 연산자 입니다.
//   => 연관성 있는 타입간의 캐스팅에서 사용됩니다.
//     - 실수 <-> 정수
//     - 표현 범위 가 다른 정수간의 변환
//     - void* -> T*

// 2) reinterpret_cast
//    : 메모리를 재해석하는 목적으로 사용하는 연산자입니다.

// 3) const_cast
//     : 메모리의 상수성을 제거해서, 타입의 불일치 문제를 해결하기 위해
//       사용하는 연산자 입니다.
//    - const T* -> T*
//      const T& -> T&

// 4) dynamic_cast

int main()
{
    double d { 3.14 };
    // int n { (int)d };
    int n { static_cast<int>(d) };

    void* pv = &n;
    int* pn = static_cast<int*>(pv);

    int x = 0x12345678;
    // char* pc = static_cast<char*>(&x);
    char* pc = reinterpret_cast<char*>(&x);

    // long long* pl = reinterpret_cast<long long*>(&x);
    // std::cout << *pl << std::endl; /* 미정의 동작 */

    // const T* -> T*
    const char* str = "hello";

    // char* c = static_cast<char*>(str);
    // char* c = reinterpret_cast<char*>(str);
    char* c = const_cast<char*>(str);
}
