// 7_함수2.cpp
#include <iostream>
using namespace std;

#if 0
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }
long long squarell(long long x) { return x * x; }

int main()
{
    cout << squarei(10) << endl;
    cout << squared(3.14) << endl;
    cout << squarell(100000000LL) << endl;
}
#endif

// 함수 오버로딩(Overloading, 중복 적재)
// => 함수의 이름이 동일하지만, 함수의 인자 정보(인자의 타입, 개수)가 다른 경우에 허용합니다.
// => 원리: 네임 맹글링
//     - 컴파일시 컴파일러가 함수의 이름을 함수의 인자 정보를
//       포함하는 형태로 생성합니다.

int square(int x) { return x * x; } // __Z6squarei
double square(double x) { return x * x; } // __Z6squared
long long square(long long x) { return x * x; } // __Z6squareL

extern "C" void square() { } // _square
// extern "C"를 통해 함수를 만들 경우,
// C의 형태로 함수를 만들 수 있습니다.
//  => C에서 C++의 함수를 호출하거나,
//     C++에서 C의 함수를 호출하는 것이 가능합니다.
//  => 네임 맹글링이 수행되지 않습니다.

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(100000000LL) << endl;
}
