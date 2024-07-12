// 27_접근변경자2.cpp
#include <iostream>
#include <vector>
using namespace std;

// 스택을 만들고 싶습니다.
// 이미 잘 만들어진 vector가 있습니다.
// => 한쪽으로 데이터를 삽입하고, 제거하면
//    스택처럼 사용할 수 있습니다.

// => 기존 클래스의 인터페이스(함수의 이름)을 변경해서,
//    새로운 클래스처럼 보이게 하는 설계 방법
//   : Adapter Pattern
#if 0
template <typename TYPE>
class stack : private vector<TYPE> {
public:
    void push(const TYPE& e)
    {
        // 부모의 기능을 재사용합니다.
        vector<TYPE>::push_back(e);
    }

    TYPE& top()
    {
        return vector<TYPE>::back();
    }

    void pop()
    {
        return vector<TYPE>::pop_back();
    }
};

// public 상속
//  : 부모의 구현과 함수를 물려 받습니다.
//    부모의 접근 제어도 물려 받습니다.
//  protected -> protected
//  public    -> public

// => 부모의 기능은 클래스 내부적으로만 사용하고 싶다.
//    외부에서는 사용이 불가능하도록 하고 싶다.
//   : 접근 변경자
//  protected -> private
//  public    -> private

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
#endif

// 상속을 재사용의 목적으로 사용하는 것은
// 좋지 않습니다.
//  => 포함의 설계를 사용하는 것이 좋습니다.
template <typename TYPE>
class stack {
    vector<TYPE> v;
    // 명시적으로 사용하고자는 기능에 대해서만
    // 어댑터를 구현할 수 있습니다.

public:
    void push(const TYPE& e)
    {
        v.push_back(e);
    }

    TYPE& top()
    {
        return v.back();
    }

    void pop()
    {
        v.pop_back();
    }
};

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
