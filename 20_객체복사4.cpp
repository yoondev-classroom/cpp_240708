// 20_객체복사4.cpp
#include <iostream>
using namespace std;

// => 복사 정책
// 3) 복사 금지

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

    // User other { user };
    // other.Print();
}
