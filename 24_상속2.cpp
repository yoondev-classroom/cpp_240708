// 24_상속2.cpp
#include <iostream>
using namespace std;

// => 상속: C++ 에서는 public 상속을 의미합니다.

// 부모 클래스 / Base / Super
class Animal {
    int age;
};

// 상속
// 자식 클래스 / Derived / Sub
class Dog : public Animal {
    int speed;
};

int main()
{
    Dog d;

    std::cout << sizeof(Dog) << std::endl;
    std::cout << sizeof(d) << std::endl;
}
