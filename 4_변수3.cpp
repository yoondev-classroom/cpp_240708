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
    // p는 포인터 타입입니다. 포인터가 참조하는 타입은 int입니다.

    // p의 타입은? int*
    std::cout << sizeof(p) << std::endl;

    int x[3];
    // x는 3개의 크기를 가지는 배열입니다. 배열 요소의 타입은 int 입니다.

    // x의 타입은?  int[3]
    std::cout << sizeof(x) << std::endl;
}
#endif

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    int* p = x; // &x[0]
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

// int (*py)[3]
//  (*py)
//  -> py는 포인터 타입입니다. 포인터 타입이 참조하는 타입은?

//  (*py)[3]
//  -> 포인터가 참조하는 타입은 3개의 길이를 가지는 배열입니다.
//     배열 요소의 타입은?

//   int (*py)[3]
//  -> 배열의 요소의 타입은 int 입니다.

//  py
//   [ * ]  ------> [int][int][int]

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

// 포인터의 타입은 포인터를 통해 연산을 수행할 때의
// 단위(offset)를 결정합니다.
#if 0
int main()
{
    //          px
    //           |
    int x[3] = { 41010, 20, 30 }; // 12byte

    short* px = (short*)x; // &x[0]

    std::cout << px << std::endl;
    std::cout << *px << std::endl;
}
#endif

// C++11, Type deduction
// 1) 컴파일 시간에 변수의 타입을 우항의 타입을 기반으로 결정합니다.
// 2) 의존성 있는 타입을 표현할 대,
//    변수의 타입이 변경되어도 코드를 수정할 필요가 없습니다.
// 3) C의 auto 키워드를 다른 의미로 사용합니다.
#if 1
int main()
{
    int x[3] = { 10, 20, 30 };

    // int* px1 = x;
    // int(*px2)[3] = &x;
    auto px1 = x;
    auto px2 = &x;

    // auto p; // 컴파일 오류!
    // 반드시 우항이 필요합니다.
}
#endif
