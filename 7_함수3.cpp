// 7_함수3.cpp
#include <iostream>
using namespace std;

// * 함수 오버로딩 주의사항
// 1. 함수의 인자 정보가 동일하고, 반환 타입만 다를 경우
//  오버로딩은 불가능합니다.
#if 0
int foo() { }
// void foo() { } - error!

int main()
{
}
#endif

// 2. 파라미터 기본값과 함께 사용할 경우,
//    컴파일러는 어떤 함수를 호출할지 결정할 수 없습니다.
//  => 파라미터 기본값과 함께 사용될 때 주의가 필요합니다.

// __Z3fooi
void foo(int a = 100) { }

// __Z3foov
void foo() { }

int main()
{
    // foo(); // error!
}
