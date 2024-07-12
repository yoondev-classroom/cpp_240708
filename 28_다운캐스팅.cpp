// 28_다운캐스팅.cpp
#include <iostream>
using namespace std;

class Animal {
    int age;

public:
    virtual ~Animal() { } // !!

    int GetAge() const { return age; }
};

class Dog : public Animal {
    int color;

public:
    int GetColor() const
    {
        std::cout << "Dog::GetColor()" << std::endl;
        return color;
    }
};

// C++ 다운 캐스팅
// 1. static_cast
// => 컴파일 타임에 타입을 변환하기 때문에,
//    성능에 영향이 없습니다.
// => 잘못된 자식 타입이 온 경우를 확인할 수 없습니다.

// 2. dynamic_cast
// => 실행 시간에 가상 함수 테이블의 타입 정보를 통해
//    잘못된 자식 타입의 경우, nullptr을 반환합니다.

int main()
{
    // Dog d;
    Animal d;

    Animal* p = &d;

    // Dog* pDog = static_cast<Dog*>(p);
    Dog* pDog = dynamic_cast<Dog*>(p);
    // : dynamic_cast를 이용하기 위해서는
    //   타입의 정보(RTTI - RunType Type Information)가 필요합니다.
    //  => 가상 함수 테이블에 저장되어 있습니다.

    // 실행 시간에 가상 함수 테이블의 타입 정보를 조사해서,
    // 잘못된 타입인 경우, nullptr을 반환합니다.
    if (pDog) {
        pDog->GetColor();
    }
}

#if 0
int main()
{
    Animal d;

    Animal* p = &d;

    // 잘못된 타입에 대한 캐스팅인 경우, 미정의 동작이 발생할 수 있습니다.
    // => 다운 캐스팅을 수행할 때, 잘못된 캐스팅을 확인할 수 없습니다.
    Dog* pDog = static_cast<Dog*>(p);
    pDog->GetColor();
}
#endif

#if 0
int main()
{
    Dog d;

    Animal* p = &d;
    // 부모의 포인터 또는 참조를 통해,
    // 자식 객체를 이용할 경우,
    // 부모를 통해서 제공되는 기능에 대해서만 사용할 수 있습니다.

    // 자식 객체의 고유의 기능을 이용하고 싶습니다.
    // p를 자식 객체의 포인터/참조 타입으로 캐스팅해야 합니다.
    // => 다운 캐스팅은 암묵적인 캐스팅이 허용되지 않습니다.

    Dog* pDog = static_cast<Dog*>(p);
    pDog->GetColor();
}
#endif
