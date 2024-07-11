// 20_객체복사5.cpp
#include <iostream>
using namespace std;

class User {
    char* name;
    int age;

public:
    // 복사 생성자
    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // 이동 생성자(소유권 이전)
    User(User&& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
        rhs.name = nullptr;
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        // if (name) {
        //     delete[] name;
        // }

        // delete[] / delete에
        // nullptr이 전달되면 아무일도 수행하지 않습니다.
        delete[] name;
    }

    void Print()
    {
        std::cout << name << ", " << age << std::endl;
    }
};

// C++ 에서 임시 객체는 rvalue 입니다.

int main()
{
    User user { "Tom", 42 };
    user.Print();

    User other1 { user };
    User other2 { User { "Bob", 100 } };
}
