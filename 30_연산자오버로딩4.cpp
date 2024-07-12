// 30_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

#if 0
// 1. 함수의 타입은 함수의 인자정보와 함수의 반환 타입에
//    의해서 결정됩니다.
// 2. 함수의 인자정보, 함수의 반환 타입(함수의 시그니처)가
//    동일하면, 같은 함수 타입입니다.
int add(int a, int b) // int(int, int)
{
    return a + b;
}

int sub(int a, int b) // int(int, int)
{
    return a - b;
}

// int           -> int*
// double        -> double*
// int[3]        -> int(*)[3]
// int(int, int) -> int(*)(int, int) // 함수 포인터

int main()
{
    int (*p1)(int, int) = &add;
    // 함수 포인터를 통해 참조하는 함수를 호출할 수 있습니다.

    p1 = &sub;

    cout << (*p1)(100, 200) << endl;
}
#endif

#if 0
// endl은 함수입니다.
std::ostream& xendl(std::ostream& os)
{
    os << '\n';
    return os;
}

namespace xstd {
// 실제 cout의 타입입니다.
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }

    ostream& operator<<(ostream& (*fp)(ostream&))
    {
        fp(*this);
        return *this;
    }
};
#endif

// std::endl - IO Manipulator
// => IO 조정자
std::ostream& menu(std::ostream& os)
{
    os << "1. 짜장면" << endl;
    os << "2. 짬뽕" << endl;
    return os;
}

int main()
{
    std::cout << menu;

    // std::cout << "hello" << std::endl;

    // xendl(cout);
    cout << endl;
    // cout.operator<<(endl);
}
