// 13_stack8.cpp
#include <iostream>
#include <string>
using namespace std;

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

    // void Push(TYPE n)
    //   -> void Push(Sample n)
    //   -> void Push(int n)

    // 핵심: 템플릿은 기본 타입 뿐 아니라 사용자 정의 타입도
    //    올 수 있기 때문에, 인자를 전달받을 때,
    //    const T& 형태를 사용해야 합니다.
    // void Push(const TYPE& n)
    //   -> void Push(const Sample& n)
    //   -> void Push(const int& n)
    void Push(const TYPE& n)
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

class Sample {
public:
    Sample() = default;

    Sample(const Sample&)
    {
        std::cout << "Sample(const Sample&)" << std::endl;
    }
};

int main()
{
    Stack<Sample> st;

    Sample s1;
    Sample s2;
    Sample s3;

    std::cout << "------" << std::endl;
    st.Push(s1);
    st.Push(s2);
    st.Push(s3);
    std::cout << "------" << std::endl;
}

#if 0
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
#endif

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
