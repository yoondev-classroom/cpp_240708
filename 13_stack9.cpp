// 13_stack8.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
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

    // 컨테이너에서 데이터를 제거하는 연산과,
    // 데이터를 참조하는 연산을 분리합니다.
    void Pop()
    {
        --top;
    }

    TYPE& Top()
    {
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

    st.Push(s1);
    st.Push(s2);
    st.Push(s3);

    std::cout << "------" << std::endl;
    st.Top();
    st.Pop();

    st.Top();
    st.Pop();

    st.Top();
    st.Pop();
    std::cout << "------" << std::endl;
}
#endif

// C++에는 이미 잘만들어진 stack이 존재합니다.

#include <stack> // std::stack
// 컨테이너
//  => STL(Standard Template Library)

int main()
{
    stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    std::cout << s1.top() << std::endl;
    s1.pop();

    std::cout << s1.top() << std::endl;
    s1.pop();

    std::cout << s1.top() << std::endl;
    s1.pop();
}
