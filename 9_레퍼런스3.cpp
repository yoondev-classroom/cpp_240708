// 9_레퍼런스3.cpp
#include <iostream>
using namespace std;

#if 0
// void print_array(int x[3])
void print_array(int* x)
{
    // std::cout << sizeof(x) << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << x[i] << std::endl;
        //          *(x+i)
    }

    x[0] = 100;
}

int main()
{
    //                   px+2
    //          px   px+1|
    //           |   |   |
    int x[3] = { 10, 20, 30 };

    int* px = &x[0];
    //          x

    // &x[0]
    //  == &*(x+0)
    //  == &*x (&* 상쇄)
    //  == x

    // *(x + N) == x[N]
    std::cout << *(x + 0) << std::endl;
    std::cout << *(x + 1) << std::endl;
    std::cout << *(x + 2) << std::endl;
    std::cout << x[0] << std::endl;
    std::cout << x[1] << std::endl;
    std::cout << x[2] << std::endl;

    std::cout << *(px + 0) << std::endl;
    std::cout << *(px + 1) << std::endl;
    std::cout << *(px + 2) << std::endl;
    std::cout << px[0] << std::endl;
    std::cout << px[1] << std::endl;
    std::cout << px[2] << std::endl;

    // print_array(x);
    // print_array(&x[0])

    // std::cout << x[0] << std::endl; // ?
}
#endif

// 핵심
// - C 에서 배열을 인자로 전달받는 함수를 만들 때,
//   함수에서는 배열의 첫번째 원소의 주소가 전달되기 때문에,
//   전달된 배열의 길이를 알 수 없습니다.
//  => 추가적인 인자로 길이를 전달받습니다.
#if 0
void print_array(int* x, size_t n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << std::endl;
    }
}

int main()
{
    int x[5] = { 10, 20, 30 };
    print_array(x, sizeof(x) / sizeof(x[0]));
}
#endif

#if 0
void print_array(int (&r)[5])
{
    for (int i = 0; i < sizeof(r) / sizeof(r[0]); i++) {
        std::cout << r[i] << std::endl;
    }
}

void print_array(int (&r)[3])
{
    for (int i = 0; i < sizeof(r) / sizeof(r[0]); i++) {
        std::cout << r[i] << std::endl;
    }
}
#endif

template <typename TYPE>
inline void print_array(TYPE& r)
{
    for (int i = 0; i < sizeof(r) / sizeof(r[0]); i++) {
        std::cout << r[i] << std::endl;
    }
}

int main()
{
    int x[3] = { 10, 20, 30 };

    // int(&r)[5] = x;
    print_array(x);

    // std::cout << sizeof(r) << std::endl;
}
