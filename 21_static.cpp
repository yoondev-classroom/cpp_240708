// 21_static.cpp
#include <iostream>
using namespace std;

#if 0
class Car {
    int cnt = 0;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c1;
    Car c2;

    std::cout << c1.GetCount() << std::endl;
    std::cout << c2.GetCount() << std::endl;
}
#endif

#if 0
int cnt = 0;
// 클래스가 제공하는 접근 지정자를 이용할 수 없습니다.

class Car {
public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c[4];
    cnt = 0;

    Car c1;
    std::cout << c1.GetCount() << std::endl;

    Car c2;
    std::cout << c2.GetCount() << std::endl;
}
#endif

// 정적 멤버 데이터
#if 0
class Car {
    static int cnt;
    // 전역 변수와 동일한 수명을 가집니다.

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

// 정적 멤버 데이터는 반드시 외부 정의가 필요합니다.
int Car::cnt = 0;

int main()
{
    Car c[4];

    Car c1;
    std::cout << c1.GetCount() << std::endl;

    c1.cnt = 1000;

    Car c2;
    std::cout << c2.GetCount() << std::endl;
}
#endif

class Car {
    static int cnt;
    // 클래스의 상태 => 클래스 변수

    std::string name;
    // 객체의 상태

public:
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
}
