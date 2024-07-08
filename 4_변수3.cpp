// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int a;
    // a의 타입은? int
    std::cout << sizeof(a) << std::endl;

    int* p;
    // p의 타입은? int*
    std::cout << sizeof(p) << std::endl;

    int x[3];
    // x의 타입은?  int[3]
    std::cout << sizeof(x) << std::endl;
}
#endif

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    int* p = x;
    // 배열의 이름은 배열의 첫번째 원소의 주소로 해석됩니다.
    // => Decay
    //  예외
    // 1) sizeof
    // 2) &

    std::cout << sizeof(x) << std::endl; // 12
    std::cout << sizeof(int[3]) << std::endl;

    std::cout << sizeof(p) << std::endl; // 8

    // int* p = &x[0];
}
#endif

#if 0
int main()
{
    int x = 10;
    int* px = &x;

    int y[3] = { 10, 20, 30 }; // int[3]
    // py??

    int(*py)[3] = &y; // int (*py)[3]
    int* py2 = y;
}
#endif

// C++11, Type deduction
// 1) 컴파일 시간에 변수의 타입을 우항의 타입을 기반으로 결정합니다.
// 2) 의존성 있는 타입을 표현할 대,
//    변수의 타입이 변경되어도 코드를 수정할 필요가 없습니다.

int main()
{
    int x[3] = { 10, 20, 30 };

    // int* px1 = x;
    // int(*px2)[3] = &x;
    auto px1 = x;
    auto px2 = &x;
}
