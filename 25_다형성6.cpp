// 25_다형성6.cpp
#include <iostream>
using namespace std;

class Car {
public:
    virtual void Start() { cout << "Car::Start" << endl; }
};

class Sedan : public Car {
public:
    // Sedan의 자식 클래스는 반드시 아래 구현을 이용해야 합니다.
    //  - C++11, 오버라이딩 금지
    //  => final
    void Start() override final
    {
        cout << "Sedan::Start" << endl;
    }
};

// 상속 금지 - C++11
//  => final
class Avante final : public Sedan {
public:
#if 0 
    void Start() override
    {
        cout << "Avante::Start" << endl;
    }
#endif
};

#if 0
class Avante2 : public Avante {
};
#endif

// => 상속을 목적으로 설계된 클래스가 아니라면,
//    상속을 금지해야 합니다.

int main()
{
    // Car* p = new Sedan;
    // p->Start();

    Car* p = new Avante;
    p->Start();
}
