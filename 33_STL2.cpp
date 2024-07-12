// 33_STL2.cpp
#include <iostream>
using namespace std;

// 2) 반복자(Iterator)
#if 0
int main()
{
    //          p1                 p2
    //           |                  |
    int x[5] = { 10, 20, 30, 40, 50 };

    int* p1 = x;
    int* p2 = x + 5;
    // 컨테이너의 마지막 요소 다음 위치를
    // 가르키는 것은 유효합니다.
    //  => Past the end

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }

    // * C++은 반개구간을 사용합니다.
    // [begin, end)
}
#endif

#include <vector>
// 반복자
// => 컨테이너의 요소를 참조하는 객체

int main()
{
    //          p1                 p2
    //           |                  |
    // int x[5] = { 10, 20, 30, 40, 50 };
    vector<int> x = { 10, 20, 30, 40, 50 };

    auto p1 = std::begin(x);
    auto p2 = std::end(x); // Past the end

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
