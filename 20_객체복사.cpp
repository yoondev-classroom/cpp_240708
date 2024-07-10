// 20_객체복사.cpp
#include <iostream>
using namespace std;

// 1) 포인터 멤버를 가지는 클래스는
//  컴파일러가 제공하는 복사 생성자를 사용할 경우,
//  "얕은 복사"의 문제가 발생합니다.

// 2) 포인터 멤버를 가지는 클래스는
//    사용자가 반드시 복사 생성자를 직접 정의해서
//    복사의 정책을 구현해야 합니다.

// => 복사 정책
// 1) 깊은 복사
// 2) 참조 계수
// 3) 복사 금지

class User {
    char* name;
    int age;

public:
    // 컴파일러가 제공하는 복사 생성자
    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        std::cout << name << ", " << age << std::endl;
    }
};

int main()
{
    User user { "Tom", 42 };
    user.Print();

    User other { user };
    other.Print();
}
