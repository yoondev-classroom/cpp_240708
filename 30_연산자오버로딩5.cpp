// 30_연산자오버로딩5.cpp
#include <iostream>
using namespace std;

// 정수의 역활을 수행하는 클래스 타입입니다.
#if 0
class Integer {
    int value;

public:
    Integer(int n = 0)
        : value { n }
    {
    }

    Integer& operator++()
    {
        ++value;
        return *this;
    }

    void Print() const
    {
        cout << value << endl;
    }

    friend ostream& operator<<(ostream& os, const Integer& v);
};

ostream& operator<<(ostream& os, const Integer& v)
{
    os << v.value;
    return os;
}

int main()
{
    // int n1 { 10 };
    // int n1;
    int n2 = 10;
    ++ ++n2;
    cout << n2 << endl;
    // cout.operator<<(int);

    // n2를 1 증가시키고, n2의 참조가 반환됩니다.

    // Integer n1;
    Integer n1 { 10 };
    ++ ++n1;
    // n1.operator++()
    // n1.Print();
    cout << n1 << endl;
    // operator<<(cout, n1)
}
#endif

#if 0
class Integer {
    int value;

public:
    Integer(int n = 0)
        : value { n }
    {
    }

    Integer& operator++()
    {
        ++value;
        return *this;
    }

    void Print() const
    {
        cout << value << endl;
    }

    friend ostream& operator<<(ostream& os, const Integer& v);
};

ostream& operator<<(ostream& os, const Integer& v)
{
    os << v.value;
    return os;
}

int main()
{
    int n2 = 10;
    /*
        mov     DWORD PTR n2$[rsp], 10
    */
    ++n2;
    /*
        mov     eax, DWORD PTR n2$[rsp]
        inc     eax
        mov     DWORD PTR n2$[rsp], eax
    */

    Integer n1 { 10 };
    // mov     DWORD PTR n1$[rsp], 10

    ++n1;
    /*   
        mov     eax, DWORD PTR n1$[rsp]
        inc     eax
        mov     DWORD PTR n1$[rsp], eax
    */
}
#endif

class Integer {
    int value;

public:
    Integer(int n = 0)
        : value { n }
    {
    }

    // 전위 연산
    Integer& operator++()
    {
        ++value;
        return *this;
    }

    // 후위 연산
    Integer operator++(int)
    {
        Integer temp { *this }; // 증가되기 이전의 복사본
        ++value;

        return temp;
    }

    void Print() const
    {
        cout << value << endl;
    }

    friend ostream& operator<<(ostream& os, const Integer& v);
};

ostream& operator<<(ostream& os, const Integer& v)
{
    os << v.value;
    return os;
}

// for (int i = 0 ; i < 10; i++) {} => C Style
// for (int i = 0 ; i < 10; ++i) {} => C++ Style

int main()
{
    int n2 = 10;
    // cout << ++n2; << endl;  // 11
    // cout << n2++ << endl; // 11
    // 후위 증감 연산은 값을 변경하고, 변경되기 이전의 값으로 평가됩니다.

    Integer n1 { 10 };
    // ++n1;
    n1.operator++()

    // n1++;
    // n1.operator++(int)
    // => 오버로딩이 불가능하기 때문에, int 더미 인자로
    //    약속되었습니다.
}
