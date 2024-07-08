// 3_iostream.cpp
#include <iostream>
#include <iomanip>
using namespace std;

#if 0
int main()
{
    // int n = 0xFAFA;
    //      1111 1010 1111 1010

    // C++11, 2진수 상수를 표현하는 기능이 추가되었습니다.
    //   상수에 단일따옴표를 통해 가독성을 높일 수 있습니다.
    int n = 0b1111'1010'1111'1010;
    int x = 1'000'000'000;

    printf("%x\n", n);
    printf("%X\n", n);

    std::cout << n << std::endl;
    // IO 조정자(Manipulator)
    std::cout << std::hex << n << std::endl;
    std::cout << std::hex << std::uppercase << n << std::endl;

    printf("%10d\n", n);
    std::cout << setw(10) << std::dec << n << std::endl;
}
#endif

// 타입에 따라 원하는 형태로 자동으로 출력이 되기 때문에
// printf 같이 서식을 지정할 필요가 없습니다.
int main()
{
    float n = 10;
    long l = 100000L;
    double f = 3.14;

    printf("%f\n", n);
    printf("%ld\n", l);
    printf("%lf\n", f);

    std::cout << n << std::endl;
    std::cout << l << std::endl;
    std::cout << f << std::endl;
}
