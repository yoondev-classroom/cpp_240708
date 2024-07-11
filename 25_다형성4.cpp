// 25_다형성4.cpp
#include <iostream>
using namespace std;

// 함수 오버라이딩(Overriding)
// 1. 정의: 부모 클래스가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있습니다.
class Animal {
public:
    virtual void Cry() const { std::cout << "Animal::Cry" << std::endl; }
};

class Dog : public Animal {
public:
    virtual void Cry() const { std::cout << "Dog::Cry" << std::endl; }
};

// 문제점
// - 부모의 포인터/레퍼런스를 통해 해당하는 함수를 호출하였을 경우,
//   자식의 멤버함수가 호출되지 않고, 부모의 멤버함수가 호출되고 있습니다.

// 원인
//  - 바인딩: 어떤 멤버 함수를 호출할지 결정하는 것
//     Animal* p = &d;
//     p->Cry();

//   1) 정적(static) 바인딩
//    : 어떤 함수를 호출할지 컴파일러가 컴파일 타임에 결정하는 것
//      컴파일러가 컴파일 시간에 p의 타입을 보고, 어떤 함수를 호출할지 결정합니다.
//    => 컴파일러가 컴파일 시간에 어떤 함수를 호출할지 미리 알기 때문에
//       인라인 최적화가 가능합니다.

//   2) 동적(dynamic) 바인딩
//    : 어떤 함수를 호출할지 실행 시간에 p가 참조하는 객체의 타입을 조사해서
//      함수를 호출합니다.
//    => 실행 시간에 어떤 함수가 호출될지 결정되기 때문에,
//       인라인 최적화가 불가능합니다.

// * C++에서 오버라이딩 하는 멤버 함수는 반드시 가상 함수로 만들어야 합니다.

int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Cry();

    p = &d;
    p->Cry();

    Animal& r = d;
    r.Cry();
}

#if 0
int main()
{
    Animal a;
    a.Cry();

    Dog d;
    d.Cry();
}
#endif
