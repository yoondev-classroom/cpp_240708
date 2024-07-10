// 16_소멸자.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 1. 클래스 내부에서 자원(메모리, 파일)을 할당한 경우,
//    소멸자를 통해 객체가 파괴되기 전에 자원을 해지해주어야 합니다.

// 2. 컴파일러는 사용자가 소멸자를 제공하지 않는 경우,
//    자동으로 아무일도 하지 않는 소멸자를 제공합니다.

class Person {
    char* name;

public:
    // 소멸자는 1개만 제공할 수 있습니다.
    ~Person()
    {
        delete[] name;
    }

    // 생성자로 전달된 문자열을 복사해서 사용합니다.
    Person(const char* s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void Print()
    {
        std::cout << name << std::endl;
    }
};

int main()
{
    Person p1 { "Tom" };
    p1.Print();
}
