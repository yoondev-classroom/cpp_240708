// 4_변수4.cpp
#include <iostream>
using namespace std;

// GNU Extension
// => __typeof / typeof
// 위의 기능과 동일한 기능이 표준으로 도입되었습니다.

int main()
{
    int x = 100;
    // x와 동일한 타입의 변수를 만들고 싶습니다.
    // C++11, decltype
    //  : 주어진 표현식과 동일한 타입을 구하는 연산자 입니다.

    decltype(x) x2;
    // 우항이 반드시 필요하지 않습니다.
}
