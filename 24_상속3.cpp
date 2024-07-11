// 24_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스의 private 영역을 자식 클래스를 통해서는
//    접근이 불가능합니다.

// 2. protected
//  : 외부에서 접근이 불가능하지만, 자식 클래스를 통해서는
//    접근이 가능합니다.

// 3. C++ 접근 지정자
//  1) private: 외부 접근이 불가능. 자식 클래스 접근 불가능, friend 함수/클래스는 가능
//  2) protected: 외부 접근 불가능. 자식 클래스 접근 가능
//  3) public: 외부 접근 가능

#if 0
class Animal {
protected:
    int age = 42;
};

class Dog : public Animal {
public:
    void Print() const
    {
        std::cout << age << std::endl;
    }
};

int main()
{
    std::cout << sizeof(Dog) << std::endl;

    Dog d;
    // d.age;

    d.Print();
}
#endif

// GoF's Design Pattern, 1995년 에릭감마 외 3명
//  => GoF(Gang of Four)

// 깨지기 쉬운 기반 클래스의 문제

class Animal {
private:
    int age2 = 42;

protected:
    int GetAge() const { return age2; }
};

class Dog : public Animal {
public:
    void Print() const
    {
        std::cout << GetAge() << std::endl;
    }
};

int main()
{
    std::cout << sizeof(Dog) << std::endl;

    Dog d;
    // d.age;

    d.Print();
}
