// 25_다형성.cpp
#include <iostream>
using namespace std;

class Animal {
};

// class Dog { };
class Dog : public Animal { };

// is-a 관계
// : <자식 클래스> is a <부모 클래스>

int main()
{
    Animal a;
    Dog d;

    Animal* pa = &a;
    Animal& ra = a;

    Dog* pd = &d;
    Dog& rd = d;

    // 1. 부모 타입의 포인터/참조 타입으로 자식 객체를 참조할 수 있습니다.
    // 2. 자식의 포인터/참조 타입은 부모 포인터/참조 타입으로의 암묵적인 변환을
    //    허용합니다.
    //  => Upcasting
    Animal* p = &d;
    Animal& r = d;

    // => Downcasting은 암묵적으로 허용되지 않습니다.
}
