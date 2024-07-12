// 33_STL4.cpp
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    // sort(begin(v), end(v)); // C++98

    // C++20부터는 알고리즘의 인자로
    // 반복자가 아니라, 컨테이너를 전달할 수 있습니다.
    std::ranges::sort(v); // C++20

    for (auto e : v) {
        cout << e << endl;
    }
}
