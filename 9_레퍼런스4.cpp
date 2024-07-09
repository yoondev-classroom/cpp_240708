// 9_레퍼런스4.cpp
#include <iostream>
using namespace std;

// const
#if 0
void print_array(const int* px, int n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << px[i] << std::endl;
    }

    // px[0] = 100;
    // px[1] = 200;
    // px[2] = 300;
}

int main()
{
    int x[3] = { 10, 20, 30 };
    print_array(x, 3);
    print_array(x, 3);
}
#endif

#if 0
int main()
{
    int n = 10;

    int* pn1 = &n;
    *pn1 = 100; /* OK */
    std::cout << *pn1 << std::endl; /* OK */

    // 읽기 전용 포인터
    // pn2 ---> [n]
    const int* pn2 = &n;
    // *pn2 = 100; /* ERROR */
    std::cout << *pn2 << std::endl; /* OK */

    // pn3 ---> [n]
    int const* pn3 = &n;
    // *pn3 = 100;
    std::cout << *pn3 << std::endl; /* OK */

    int x = 100;
    // [pn4] ---> n
    int* const pn4 = &n;
    // pn4 = &x; /* 오류 */
    *pn4 = 1000; /* OK */

    const int* const pn5 = &n;
    int const const* pn6 = &n;
}
#endif

int main()
{
    int n = 100;

    // 읽기 전용
    // - 레퍼런스를 통해서는 메모리의 값을 변경할 수 없습니다.
    // const int& r = n;
    int const& r = n;
    // r = 10; /* 에러! */
}
