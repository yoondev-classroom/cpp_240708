// 25_다형성7.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};
// 부모의 소멸자가 가상이면, 자식의 소멸자도 가상입니다.

class Dog : public Animal {
public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }
    // => 부모의 소멸자가 가상이 아닌 경우, 컴파일 오류가 발생합니다.
};

// 문제
// => 부모의 포인터를 자식 객체를 delete 하였을 때,
//    자식의 소멸자가 호출되지 않습니다.
// 원인
// => 소멸자도 정적 바인딩을 하기 때문에, p의 타입을 통해
//    부모의 소멸자가 호출되었습니다.

// * 반드시 부모 클래스의 소멸자는 가상이어야 합니다.

int main()
{
    // Dog d;
    Animal* p = new Dog;

    delete p;
}
