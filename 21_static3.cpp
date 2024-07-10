// 21_static3.cpp
#include <iostream>
using namespace std;

class Car {
    int age = 0;

public:
    // void Go1(Car* this)
    void Go1()
    {
        std::cout << "Go" << std::endl;
    }

    // void Go2(Car* this)
    void Go2()
    {
        if (this != nullptr) {
            std::cout << age << std::endl;
        }

        //         this->age // !!!
    }
};

Car* Alloc()
{
    // 메모리 할당에 실패해서, nullptr을 반환합니다.
    return nullptr;
}

int main()
{
    Car* p = Alloc(); // nullptr 객체입니다.

    p->Go1();
    // Car::Go1(p);

    p->Go2();
    // Car::Go2(p);
}
