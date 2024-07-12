// 30_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

namespace xstd {
class istream {
public:
    istream& operator>>(int& n)
    {
        scanf("%d", &n);
        return *this;
    }

    istream& operator>>(double& n)
    {
        scanf("%lf", &n);
        return *this;
    }
};

istream cin;

}

int main()
{
    int a;
    int b;

    xstd::cin >> a >> b;
    std::cout << a << ", " << b << std::endl;

    // int n;
    // std::cin >> n;
    // => std::cin.operator(n)
    // => std::cin.operator(int&)
    // std::cout << n << std::endl;
}
