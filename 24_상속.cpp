// 24_상속.cpp
#include <iostream>
#include <string>
using namespace std;

// 상속(Inheritance)
// => 연관된 클래스의 공통의 기능(속성,함수)을 캡슐화할 수 있습니다.

#if 0
class Dog {
    string name;
    int age;

public:
    int GetAge() const { return age; }
    std::string GetName() const { return name; }
};

class Cat {
    int age;
    int speed;

public:
    int GetAge() const { return age; }
    int GetSpeed() const { return speed; }
};

int main()
{
    Dog d;
    d.GetAge();
    d.GetName();

    Cat c;
    c.GetAge();
    c.GetSpeed();
}
#endif

// 공통의 기능을 캡슐화
class Animal {
    int age;

public:
    int GetAge() const
    {
        std::cout << "Animal::GetAge()" << std::endl;
        return age;
    }
};

class Dog : public Animal {
    string name;

public:
    std::string GetName() const { return name; }
};

class Cat : public Animal {
    int speed;

public:
    int GetSpeed() const { return speed; }
};

int main()
{
    Dog d;
    d.GetAge();
    d.GetName();

    Cat c;
    c.GetAge();
    c.GetSpeed();
}
