// 24_상속4.cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    Derived()
    // : Base{} - 컴파일러는 부모의 기본 생성자를 호출하는 코드를 생성
    //   Base::Base()
    {
        cout << "Derived()" << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;

        // 자식의 소멸자의 마지막에, 부모의 소멸자를 호출하는 코드를
        // 삽입합니다.
        // Base::~Base()
    }
};

/*
Base()
Derived()
~Derived()
~Base()
*/

int main()
{
    Derived d;
    // Derived::Derived()

} // Derived::~Derived()
