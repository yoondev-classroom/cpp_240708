// 13_stack4.cpp
#include <iostream>
using namespace std;

// 3. 객체를 생성하였을 때, 바로 사용할 수 있는 상태가 되어야 합니다.
//  => 객체가 메모리에 생성되는 시점에, 자동으로 호출되는 약속된
//     멤버 함수가 있습니다.
//  => 생성자(Constructor) 함수
//     "초기화"

// - 생성자 함수
//  1) 함수의 이름은 클래스의 이름과 동일합니다.
//  2) 반환값도 없고, 반환 타입도 명시하지 않습니다.

class Stack {
private:
    int buff[10];
    int top;

public:
    Stack()
    {
        std::cout << "Stack()" << std::endl;
        top = 0;
    }

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

    // void Init()
    // {
    //     top = 0;
    // }
};

int main()
{
    Stack s1;
    Stack s2;

    // s1.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
}
