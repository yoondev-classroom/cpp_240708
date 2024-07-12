// 33_STL.cpp
#include <iostream>
using namespace std;

// Standard Template Library(STL)
// - 1998년 1차 표준안

// * STL
// 1) 컨테이너: 자료구조
// 2) 알고리즘: 컨테이너를 대상으로 연산을 수행하는
//           일반함수
// 3)  반복자: 컨테이너의 요소를 참조하는 객체

// * 컨테이너
//  - vector, list, deque
//  - stack, queue
//  - map, set
//  - unordered_map, unordered_set

//  * 컨테이너 특징
//  1) 템플릿 기반입니다.
//  => 타입에 상관없이 다양한 자료구조를 활용할 수 있습니다.
//  2) 멤버 함수의 이름이 유사합니다.
//  => 자료 구조의 전환을 쉽게 할 수 있습니다.

//     |------------------------|
//  push_front      |         push_back : 추가
//   pop_front      |          pop_back : 제거
//     front        |            back   : 참조
//             insert/remove

//   3) 컨테이너의 데이터를 참조하는 연산과 제거하는 연산이 분리되어 있습니다.
//    => 값으로 반환하는 것이 아니라, 참조를 반환하기 위해서
#include <vector>
#include <list>
#include <deque>
#if 0
int main()
{
    // vector<int> v = { 10, 20, 30, 40, 50 };
    // list<int> v = { 10, 20, 30, 40, 50 };
    deque<int> v = { 10, 20, 30, 40, 50 };

    v.push_back(100);
    v.push_back(200);

    cout << v.back() << endl;
    v.pop_back();

    for (auto e : v) {
        cout << e << endl;
    }
}
#endif

//  4) 자료 구조의 형태에 따라서 지원되지 않는 연산이 있습니다.
// => vector는 연속된 메모리 구조를 가지고 있기 때문에,
//    데이터를 앞에 삽입하는 연산은 느립니다.
//  : push_front 연산을 지원하지 않습니다.
// => list는 연속된 메모리를 사용하지 않기 때문에,
//    임의 접근 연산이 불가능합니다.
//    list<int> v;
//    v[2] <- 지원되지 않습니다.
