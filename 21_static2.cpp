// 21_static2.cpp
#include <iostream>
using namespace std;

#if 0
class Car {
    std::string name;

public:
    static int cnt;

    Car(const std::string& s)
        : name { s }
    {
        ++cnt;
    }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int Car::cnt = 0;

int main()
{
    Car c1 { "Avante" };
    Car c2 { "Sonata" };

    // 1) 객체를 통해서 접근할 수 있습니다.
    std::cout << c1.cnt << std::endl;
    std::cout << c2.cnt << std::endl;

    std::cout << &c1.cnt << std::endl;
    std::cout << &c2.cnt << std::endl;

    // 2) 클래스를 통해서 접근할 수 있습니다.
    std::cout << Car::cnt << std::endl;
    std::cout << &Car::cnt << std::endl;
}
#endif

#if 0
class Car {
    std::string name;
    static int cnt;

public:
    Car(const std::string& s)
        : name { s }
    {
        ++cnt;
    }
    ~Car() { --cnt; }

    // 정적 멤버 함수
    // : 객체를 생성하지 않아도, 멤버 함수를 호출할 수 있습니다.
    static int GetCount() { return cnt; }
};

int Car::cnt = 0;

int main()
{
    // 2) 클래스의 이름을 통해서도 멤버 함수를 호출할 수 있습니다.
    std::cout << Car::GetCount() << std::endl;

    Car c1 { "Avante" };
    Car c2 { "Sonata" };

    // 1) 객체를 통해서 정적 멤버 함수를 호출할 수 있습니다.
    std::cout << c1.GetCount() << std::endl;
    std::cout << c2.GetCount() << std::endl;
}
#endif

class Car {
    std::string name;

public:
    //       (Car* this, int a, int b)
    void foo(int a, int b)
    {
        std::cout << name << std::endl;
        //        this->name

        goo(a, b); // OK!
    }

    static void goo(int a, int b)
    {
        // std::cout << name << std::endl;
        // - this가 없으므로, 암묵적으로 멤버에 접근이
        //   불가능합니다.

        // foo(a, b);
        // this->foo(a, b)
        //  foo(this, a, b)
        // - this가 없으므로, 암묵적으로 멤버 함수를 호출이 불가능합니다.
    }

    static void goo(Car* self, int a, int b)
    {
        std::cout << self->name << std::endl;

        self->foo(a, b);
    }
};

int main()
{
    Car c;
    c.foo(10, 20);
    /*
        mov     r8d, 20
        mov     edx, 10
        lea     rcx, QWORD PTR c$[rsp]
        call    void Car::foo(int,int)
    */

    // 정적 멤버 함수는 객체의 주소가 전달되지 않습니다.
    c.goo(10, 20);
    /*
        mov     edx, 20
        mov     ecx, 10
        call    static void Car::goo(int,int)
    */

    Car::goo(&c, 10, 20);
    // 명시적으로 전달해서, 정적 멤버 함수를 통해, 멤버 데이터에 접근하거나 멤버 함수를 호출할 수 있습니다.
}
