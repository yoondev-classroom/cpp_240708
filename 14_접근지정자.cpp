// 14_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. struct의 기본 접근 지정자는 public 입니다.
//    class의 기본 접근 지정자는 private 입니다.

// 2. public은 외부에서 접근이 가능하고, private은 외부에서
//    접근이 불가능하고, 오직 멤버 함수를 통해서만 접근이 가능합니다.

// 3. friend
//  : friend로 선언된 함수 또는 클래스는 해당하는 클래스의 private 영역에
//    접근이 가능합니다.
//  => friend는 클래스의 캡슐화의 정책을 깨뜨리는 것이 아니라,
//     확장할 수 있습니다.

class User {
    std::string name;
    int age;

public:
    User(std::string s, int n)
    {
        name = s;
        age = n;
    }

    // Getter - 접근자 메소드(멤버 함수)
    int GetAge() { return age; }
    std::string GetName() { return name; }

    void PrintUser()
    {
        std::cout << name << "," << age << std::endl;
    }

    // friend void PrintUser(User user); // friend 선언
    friend class UserPrinter;
};

class UserPrinter {
public:
    void Print(User user)
    {
        std::cout << user.name << "," << user.age << std::endl;
    }
};

void PrintUser(User user)
{
    // std::cout << user.name << "," << user.age << std::endl;
    std::cout << user.GetName() << ", " << user.GetAge() << std::endl;
}

int main()
{
    User user { "Tom", 42 };
    user.PrintUser();

    PrintUser(user);
}
