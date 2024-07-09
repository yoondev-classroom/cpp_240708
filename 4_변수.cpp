// 4_변수.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입
struct Complex {
    int re;
    int im;
};

union Data {
    int a;
    char c;
};

enum State {
    RUNNING,
    STOPPED
};

int main()
{
    struct Complex c1;
    union Data d1;
    enum State s;

    // C++에서는 struct, union, enum을 명시하지
    // 않아도 됩니다.
    // => 태그가 타입으로 인식됩니다.
    Complex c2;
    Data d2;
    State s2;
}
