// 7_함수7.cpp
#include <iostream>
using namespace std;

#if 0
int add(int a, int b)
{
    return a + b;
}

// int (*foo())[3]
//   : foo()
//   foo는 인자 없는 함수입니다. 함수의 반환 타입은?
//   : (*foo())
//   함수의 반환 타입은 포인터 타입입니다.
//   포인터가 참조하는 타입은?
//   : (*foo())[3]
//   포인터가 참조하는 타입은 3개의 크기를 가지는 배열입니다.
//   배열의 요소 타입은?
//   : int (*foo())[3]
//   배열의 요소 타입은 int 입니다.

int (*foo())[3]
{
    static int arr[3] = { 10, 20, 30 };
    return &arr; // int (*)[3]
}

int main()
{
}
#endif

// C++11 에서는 함수를 정의하는 새로운 문법이 도입되었습니다.
// - Trailing Return Type

// int add(int a, int b)

auto add(int a, int b) -> int { return a + b; }

// int (*foo())[3]
// auto foo() -> int (*)[3]
auto foo()
{
    static int arr[3] = { 10, 20, 30 };
    return &arr; // int (*)[3]
}

template <typename T1, typename T2>
auto goo(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

// 1) 가독성
// 2) 반환 타입 추론이 가능합니다.
// 3) 템플릿에서 유용하게 사용할 수 있습니다.
