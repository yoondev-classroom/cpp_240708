// 20_객체복사3.cpp
#include <iostream>
using namespace std;

// => 복사 정책
// 2) 참조 계수(Reference Counting)

class User {
    char* name;
    int age;

public:
    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
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
