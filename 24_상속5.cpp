#include <iostream>
#include <string>
using namespace std;

#if 0
class Animal {
    int age;

public:
    Animal(int n)
        : age { n }
    {
    }
};

// 초기화리스트를 반드시 정의해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 멤버
// 4) 기본 생성자를 제공하지 않는 부모
// => 클래스의 기본 생성자를 제공하는 것이 편리할 때가 많습니다.

class Dog : public Animal {
public:
    // Dog() : Animal{} {}
    Dog()
        : Animal { 0 } // !!!
    {
    }
};

int main()
{
    Dog d;
}
#endif

class Sample {
public:
    Sample(const std::string& s)
    {
        std::cout << s << std::endl;
    }
};

// 초기화리스트의 초기화 순서
//  1. 부모 클래스 생성자 호출
//  2. 선언된 멤버의 순서대로 생성자 호출
class Animal : public Sample {
    Sample m1;
    Sample m2;

public:
    Animal()
        : Sample { "C" }
        , m1 { "A" }
        , m2 { "B" }

    {
    }
};

int main()
{
    Animal a;
}
