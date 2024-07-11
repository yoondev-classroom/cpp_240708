// 13_stack5.cpp
#include <iostream>
using namespace std;

// 6. 객체 내부에서 new를 통해 메모리가 할당되었다면,
//    반드시 객체가 메모리에서 파괴되기 전에, 해당 메모리를 해지해주어야 합니다.
//   : 객체가 메모리에서 파괴되기 직전에 호출되는 약속된 멤버함수가 있습니다.
//    - 소멸자(Destructor)

// - 소멸자 함수
//  1) 소멸자 함수의 이름은 ~클래스이름 입니다.
//  2) 소멸자는 인자가 없습니다.
//  3) 소멸자는 반환값도 없고, 반환 타입도 명시하지 않습니다.

#if 1
class Stack {
private:
    int* buff;
    int top;

public:
    //---
    ~Stack()
    {
        std::cout << "~Stack()" << std::endl;
        delete[] buff;
    }

//---
#if 0
    Stack()
    {
        top = 0;
        buff = new int[10];
    }
#endif

    // 파라미터 기본값을 통해 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(size_t len = 10)
    {
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
    Stack s2;

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

    std::cout << "main end" << std::endl;
}
#endif
