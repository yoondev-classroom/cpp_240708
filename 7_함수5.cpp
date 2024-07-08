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

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(100000000LL) << endl;
}
