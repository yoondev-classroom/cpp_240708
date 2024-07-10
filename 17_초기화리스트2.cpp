// 17_초기화리스트2.cpp
#include <iostream>
using namespace std;

// * 핵심
//  : 객체의 멤버를 초기화할 때, 초기화리스트를 사용하는 것이 좋습니다.
#if 0
class User {
    std::string name;
    std::string address;

public:
    User(std::string n, std::string a)
        : name { n } // 문자열을 인자로 갖는 생성자 호출
        , address { a } // 문자열을 인자로 갖는 생성자 호출
    {
    }

#if 0
    User(std::string n, std::string a)
    // name 객체의 기본 생성자 호출
    // address 객체의 기본 생성자 호출
    {
        name = n; // 값을 변경
        address = a; // 값을 변경
    }
#endif
};

int main()
{
    User user { "Tom", "Seoul" };
}
#endif

// 2. C++11, 멤버 초기화
#if 0
class User {
    std::string name = "Tom";
    std::string address = "Seoul";

public:
    User() { }

    User(std::string s)
        : name { s }
    {
    }

    void Print()
    {
        std::cout << name << ", " << address << std::endl;
    }
};

int main()
{
    User user;
    user.Print();

    User user2 { "Bob" };
    user2.Print();
}
#endif

// 주의사항
// - 멤버 데이터가 초기화되는 순서는, 초기화리스트의 순서가 아니라,
//   멤버 데이터가 선언된 순서대로 초기화됩니다.
// => 초기화 리스트를 작성할 때, 반드시 멤버 데이터가 선언된 순서대로
//   작성해야 합니다.
#if 0
class Point {
    int x;
    int y;

public:
    Point(int n)
        // : y { n }
        // , x { 10 + y }
        : x { n }
        , y { 10 + x }
    {
    }

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    Point pt { 10 };
    pt.Print();
}
#endif

// 일반적으로 멤버 데이터의 이름 규칙을 별도로 사용합니다.
// 1) m_
//   : m_x, m_y
// 2) m
//   : mX, mY
// 3) _
//   : _x, _y => 사용하지 않는 것이 좋습니다.
//     x_, y_ => C++ 권장 Style
class Point {
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_ { x }
        , y_ { y }
    {
    }
};

int main()
{
    Point pt { 10, 20 };
}
