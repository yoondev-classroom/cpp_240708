// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. C++에서는 사용자 정의 타입에서, 데이터 뿐 아니라
//    데이터를 조작하는 함수를 캡슐화할 수 있습니다.

// => 캡슐화(데이터 + 함수)
//   - 데이터: 상태
//   -  함수: 행위

// 4. public: 외부에서 접근이 가능합니다.
//    private: 외부에서 접근이 불가능하고, 멤버 함수를 통해서만 접근이 가능합니다.

// 5. struct의 기본 접근 지정자는 public 입니다.
//    class의 기본 접근 지정자는 private 입니다.

// 6. class는 객체를 설계할 때 사용되는 키워드입니다.

class Stack {
private:
    // 멤버 변수(데이터) / 상태
    int buff[10];
    int top;

public:
    // 멤버 함수 / 행위(메소드)
    void Push(int n)
    {
        buff[top] = n;
        ++top;
    }

    int Pop()
    {
        --top;
        return buff[top];
    }

    // void Init(Stack* this)
    void Init()
    {
        top = 0;
        // this->top = 0;
    }
};

// 객체의 상태는 외부에서 직접 접근이 불가능해야 합니다.
// 객체의 상태는 제공되는 메소드를 통해 접근되어야 합니다.
// => 정보 은닉(Information Hiding)
//  : public, private 접근 지정자

int main()
{
    Stack s1;
    // 상태와 행위를 가지고 있는 변수
    //  => 객체(object)

    s1.Init();
    // Stack::Init(&s1)

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    // s1.top = 100; // 에러!

    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
}
