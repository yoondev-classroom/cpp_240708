// 33_STL3.cpp
#include <iostream>
#include <vector>
using namespace std;

#if 0
void Print(int* first, int* last)
{
    auto p = first;
    while (p != last) {
        cout << *p << endl;
        ++p;
    }
}

void Print(vector<int>::iterator first,
    vector<int>::iterator last)
{
    auto p = first;
    while (p != last) {
        cout << *p << endl;
        ++p;
    }
}
#endif

// vector
//   - print
// list
//   - print

// <container>                   <algorithm>
// vector           반복자             find
// list             --->             sort
//                              ...

// 알고리즘
// => 컨테이너를 대상으로 연산을 수행할 수 있는 "일반 함수"
template <typename Iter>
void Print(Iter first, Iter last)
{
    auto p = first;
    while (p != last) {
        cout << *p << endl;
        ++p;
    }
}

#include <list>

int main()
{
    int x[3] = { 10, 20, 30 };
    // Print(x, x + 3);
    Print(std::begin(x), std::end(x));

    vector<int> v = { 10, 20, 30 };
    Print(std::begin(v), std::end(v));

    list<int> v2 = { 10, 20, 30 };
    Print(std::begin(v2), std::end(v2));
}
