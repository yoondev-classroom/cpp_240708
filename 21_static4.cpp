// 21_static4.cpp
#include <iostream>
using namespace std;

class Car {
    static int cnt;
    static constexpr int data = 100;
    // 외부 정의가 필요하지 않습니다.

    inline static int data2 { 100 };
    // C++17, inline static 문법을 이용하면,
    // 정적 멤버 데이터의 외부 정의를 생략할 수 있습니다.

    int color = 10; // C++11
};

// 정적 멤버 데이터는 외부 정의가 필요합니다.
int Car::cnt = 100;

int main()
{
}
