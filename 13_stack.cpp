// 13_stack.cpp
#include <iostream>
using namespace std;

// 스택을 만들어봅시다.
// : 가장 마지막에 삽입된 데이터가 가장 먼저 나옵니다.
//   - Last In First Out (LIFO)

// 1. 전역 변수
//  문제점: 하나의 프로그램에서 여러 개의 스택을 제공하기 어렵습니다.

int buff[10];
int top = 0;

void Push(int n)
{
    buff[top++] = n;
}

int Pop()
{
    return buff[--top];
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    std::cout << Pop() << std::endl;
    std::cout << Pop() << std::endl;
    std::cout << Pop() << std::endl;
}
