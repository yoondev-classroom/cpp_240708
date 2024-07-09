// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

void increment(int x)
{
    ++x;
}

// 포인터는 반드시 사용하기 전에 유효성 체크를 수행해야 합니다.
// 레퍼런스는 사용하기 전에 널 체크를 수행할 필요가 없습니다.
// 기존 함수를 레퍼런스 기반으로 변경하는 것이 더 쉽습니다.
// * 포인터와 레퍼런스를 이용해서 모두 작성할 수 있다면,
//   레퍼런스를 이용해서 작성하는 것이 좋을때가 많습니다.
void increment_pointer(int* p)
{
    if (p) {
        ++(*p);
    }
}

void increment_reference(int& r)
{
    ++r;
}

int main()
{
    int n = 10;
    increment_reference(n);

    // increment(n); // Call by value
    // increment_pointer(&n); // Call by pointer(address)

    std::cout << n << std::endl;
}
