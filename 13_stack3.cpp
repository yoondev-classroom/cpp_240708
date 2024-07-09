// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. C++에서는 사용자 정의 타입에서, 데이터 뿐 아니라
//    데이터를 조작하는 함수를 캡슐화할 수 있습니다.

// => 캡슐화(데이터 + 함수)
//   - 데이터: 상태
//   -  함수: 행위

struct Stack {
    // 멤버 변수(데이터) / 상태
    int buff[10];
    int top;

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

    void Init()
    {
        top = 0;
    }
};

int main()
{
    Stack s1;
    // 상태와 행위를 가지고 있는 변수
    //  => 객체

    s1.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
}
