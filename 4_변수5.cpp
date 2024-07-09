// 4_변수5.cpp

#include <iostream>
using namespace std;

// typedef
// : 기존 타입의 별칭을 만들 수 있습니다.
//  => 변수를 만들듯이 타입의 별칭을 만들 수 있습니다.

#if 0
int main()
{
    typedef int ARR3[3];

    // int x[3] = { 10, 20, 30 };
    ARR3 x = { 10, 20, 30 };
    x[0] = 100;
    x[1] = 200;
    x[2] = 300;

    for (int i = 0; i < 3; i++) {
        printf("%d\n", x[i]);
    }

    typedef int(*PARR3)[3];
    PARR3 p = &x;
}
#endif

// Type aliasing의 새로운 문법이 도입되었습니다.
// => C++11

// using
// 1) namespace
//   - using 선언
//       using std::cout;
//       using std::endl;
//   - using 지시어
//       using namespace std;

// 2) C++11, Type 별칭
//  => 템플릿의 별칭으로 사용이 가능합니다.

int main()
{
    // typedef int ARR3[3];
    using ARR3 = int[3];

    // int x[3] = { 10, 20, 30 };
    ARR3 x = { 10, 20, 30 };
    x[0] = 100;
    x[1] = 200;
    x[2] = 300;

    for (int i = 0; i < 3; i++) {
        printf("%d\n", x[i]);
    }

    // typedef int(*PARR3)[3];
    using PARR3 = int(*)[3];

    PARR3 p = &x;
}
