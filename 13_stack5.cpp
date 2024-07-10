// 13_stack5.cpp
#include <iostream>
using namespace std;

// 5. 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
//    객체를 생성할 때, 사용자로부터 정보를 전달받을 수 있습니다.
//    => 생성자 인자

#if 1
class Stack {
private:
    int* buff;
    int top;

public:
    Stack(size_t len)
    {
        std::cout << "Stack(size_t)" << std::endl;
        top = 0;
        buff = new int[len];
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
    // Stack s1(100);
    Stack s1 { 100 };
    // 객체의 생성자 인자를 전달할 때, 복사 초기화보다는
    // 직접 초기화의 형태가 좋습니다.

    // s1.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
}
#endif

#if 0
class Stack {
public:
    Stack(size_t size, char ch)
    {
        std::cout << "Stack()" << std::endl;
    }
};

int main()
{
    Stack s1 { 100, 'A' };
}
#endif
