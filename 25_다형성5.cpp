// 25_다형성5.cpp
#include <iostream>
using namespace std;

// 1. 부모의 멤버함수가 가상함수이면, 자식이 재정의한 멤버 함수도 가상함수입니다.

// 2. 문제점
//   - 부모가 제공하는 멤버 함수가 가상함수 일때만, 오버라이딩 해야 합니다.
//   => 가상 함수가 아니면, 부모의 포인터/참조 타입을 통해 호출할 경우
//      무조건 부모의 함수만 호출됩니다.
//   - 오버라이딩을 의도했지만, 실수로 새로운 함수를 정의하는 경우도 있습니다.

#if 0
class Animal {
public:
    virtual void Hello() const
    {
        std::cout << "Animal::Hello" << std::endl;
    }
};

class Dog : public Animal {
public:
    virtual void Hel1o() const
    {
        std::cout << "Dog::Hello" << std::endl;
    }
};

int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Hello();

    p = &d;
    p->Hello();

    Animal& r = d;
    r.Hello();
}
#endif

// 3. C++11, override
// 1) 부모가 제공하는 멤버 함수가 가상함수가 아니면, 컴파일 오류가 발생합니다.
// 2) 부모가 제공하는 멤버 함수가 없을 경우, 컴파일 오류가 발생합니다.

class Animal {
public:
    virtual void Hello() const
    {
        std::cout << "Animal::Hello" << std::endl;
    }
};

class Dog : public Animal {
public:
    void Hello() const override
    // virtual void Hello() const override
    {
        std::cout << "Dog::Hello" << std::endl;
    }
};

int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Hello();

    p = &d;
    p->Hello();

    Animal& r = d;
    r.Hello();
}
