// 13_stack7.cpp
#include <iostream>
#include <string>
using namespace std;

// 클래스도 템플릿으로 만들 수 있습니다.
template <typename TYPE>
class Stack {
private:
    TYPE* buff; // !
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    Stack(size_t len = 10)
    {
        top = 0;
        buff = new TYPE[len];
    }

    void Push(TYPE n)
    {
        buff[top] = n;
        ++top;
    }

    TYPE Pop()
    {
        --top;
        return buff[top];
    }
};

// 생성자의 인자를 통해 타입을 추론할 수 없는 경우,
// 명시적으로 타입을 지정해주어야 합니다.

int main()
{
    Stack<int> s1 { 100 };

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
}

#if 0
int main()
{
    Stack<std::string> s1 { 100 };

    s1.Push("hello");
    s1.Push("world");
    s1.Push("money");

    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
    std::cout << s1.Pop() << std::endl;
}
#endif
