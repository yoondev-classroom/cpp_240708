// 20_객체복사3.cpp
#include <iostream>
using namespace std;

// => 복사 정책
// 2) 참조 계수(Reference Counting)
//  - 참조 계수의 증감이 스레드 안전해야 합니다.
//   => atomic operations
//  - 참조 계수를 통해 공유되는 자원은
//    수정이 불가능한 형태로 만들어야 합니다.

//  - COW(Copy on Write) / Lazy Copy(지연된 복사)
//   => 데이터가 수정될 때, 복사본을 생성해서 분리합니다.

class User {
    char* name;
    int age;

    int* ref;

public:
    ~User()
    {
        // 참조 계수 감소
        --(*ref);

        // 참조 계수 0인 경우, 자원을 해지합니다.
        if (*ref == 0) {
            delete[] name;
            delete ref;
        }
    }

    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
        , ref { rhs.ref }
    {
        // 참조 계수 증가!
        ++(*ref);
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int { 1 };
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
