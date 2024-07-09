// 9_레퍼런스3.cpp
#include <iostream>
using namespace std;

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
