// 20_객체복사4.cpp
#include <iostream>
using namespace std;

// => 복사 정책
// 3) 복사 금지
//  => 소유권(Ownership)을 독점

class User {
    char* name;
    int age;

public:
    User(const User& rhs) = delete;
    // 복사 금지 - Delete function, C++11

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    // 이동 생성자(소유권 이전)
    User(User&& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
        rhs.name = nullptr;
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        if (name) {
            std::cout << name << ", " << age << std::endl;
        } else {
            std::cout << "null" << std::endl;
        }
    }
};

int main()
{
    User user { "Tom", 42 };
    user.Print();

    // User other = user; // lvalue 이기 때문에, 복사 금지로 인한 컴파일 오류!

    // lvalue를 rvalue로 변경하는 연산이 있습니다.
    User other = std::move(user);
    other.Print();

    user.Print();

    // User other { user };
    // other.Print();
}
