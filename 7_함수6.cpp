// 7_함수6.cpp
#include <iostream>
using namespace std;

// 실수 타입에 대해서 아래 함수를 금지하고 싶습니다.
int square(int x) { return x * x; }

// C++에서 함수를 금지하는 방법
// 1) 함수의 구현을 제공하지 않고 선언만 제공합니다.
// double square(double x);
// 링크 오류가 발생합니다.
/*
Undefined symbols for architecture arm64:
  "square(double)", referenced from:
      _main in 7_함수6-4ae63f.o
*/
// 문제점
// : 의도를 전달하기 어렵다.

// 2) C++11, Delete Function
double square(double x) = delete;
/*
7_함수6.cpp:26:13: error: call to deleted function 'square'
    cout << square(3.14) << endl;
            ^~~~~~
*/

int main()
{
    cout << square(10) << endl;
    // cout << square(3.14) << endl;
}
