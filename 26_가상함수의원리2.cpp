// 26_가상함수의원리2.cpp
#include <iostream>
using namespace std;

#if 0
// 개념을 위해 만든 예제입니다.
class AAA {
public:
    void foo() { cout << "AAA foo" << endl; } // 1
};

class BBB {
public:
    void goo() { cout << "BBB goo" << endl; } // 2
};

int main()
{
    BBB bbb;

    AAA* p = reinterpret_cast<AAA*>(&bbb); // !!
    p->foo();
}
#endif

class AAA {
public:
    virtual void foo() { cout << "AAA foo" << endl; } // 1
};

class BBB {
public:
    virtual void goo() { cout << "BBB goo" << endl; } // 2
};

int main()
{
    BBB bbb;

    AAA* p = reinterpret_cast<AAA*>(&bbb); // !!
    p->foo();
}
