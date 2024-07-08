// 7_함수.cpp
#include <iostream>
using namespace std;

// Default Parameter(파라미터 기본값)
// 정의: 전달되지 않은 함수의 인자를 파라미터 기본값으로 컴파일러가 자동으로 처리합니다.

// 주의사항
// 1) 파라미터 기본값은 반드시 마지막 파라미터부터 지정이 가능합니다.
// 2) 파라미터 기본값은 선언부에 정의합니다.

#if 0
int Add(int a, int b, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int main()
{
    std::cout << Add(10, 20, 30, 40) << std::endl;

    std::cout << Add(10, 20, 30) << std::endl;
    // std::cout << Add(10, 20, 30, 0) << std::endl;

    std::cout << Add(10, 20) << std::endl;
    // std::cout << Add(10, 20, 0, 0) << std::endl;
}
#endif

#if 0
int main()
{
    int ret = Add(10, 20, 30, 40);
    printf("%d\n", ret);
}
#endif

// add.h
int Add(int a, int b, int c = 0, int d = 0); // 선언

int main()
{
    Add(10, 20);
}

// add.cpp
int Add(int a, int b, int c /* =0 */, int d /* =0 */) // 정의
{
    return a + b + c + d;
}
