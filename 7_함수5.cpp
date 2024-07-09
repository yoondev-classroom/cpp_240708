// 7_함수5.cpp
#include <iostream>
using namespace std;

#if 0
int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }
#endif
// 함수의 인자와 반환 타입만 다르고, 함수의 구현(알고리즘)은 동일합니다.

template <typename TYPE>
TYPE square(TYPE x) { return x * x; }
// 코드를 컴파일 시간에 생성할 수 있는 템플릿의 문법이 C++에서 제공됩니다.

// 함수 템플릿
// => 적은 코드로 다양한 타입에서 동작하는 함수를 정의할 수 있습니다.
// => 전달된 인자의 타입에 따라서 각각의 함수가 생성됩니다.

#if 0
int main()
{
    cout << square(10) << endl;
    // => int 버전 코드 생성

    cout << square(3.14) << endl;
    // => double 버전 코드 생성

    cout << square(100000000LL) << endl;
    // => long long 버전 코드 생성
}
#endif

template <typename TYPE>
TYPE square(TYPE x) { return x * x; }
// int square(int x) { return x * x; }

int main()
{
    short s = 100;
    auto r = square<int>(s);

    //   type parameter
    //      |
    square<int>(10); // 명시적인 타입 지정
    //         ----
    //           |
    //         value parameter
}
