// 13_stack2.cpp
#include <iostream>
using namespace std;

// 2. 스택의 상태를 사용자 정의 타입으로 설계합니다.

#if 1
// => 데이터 캡슐화
struct Stack {
    int buff[10];
    int top;
};

void Push(Stack* s, int n)
{
    s->buff[s->top] = n;
    ++(s->top);
}

int Pop(Stack* s)
{
    --(s->top);
    return s->buff[s->top];
}

void Init(Stack* s)
{
    s->top = 0;
}

int main()
{
    Stack s1;
    Stack s2;

    Init(&s1);
    Init(&s2);

    Push(&s1, 10);
    Push(&s1, 20);
    Push(&s1, 30);

    std::cout << Pop(&s1) << std::endl;
    std::cout << Pop(&s1) << std::endl;
    std::cout << Pop(&s1) << std::endl;
}
#endif

#if 0
struct Point {
    int x;
    int y;

    long long xxx;
};

void print_point(const Point* pt)
{
    // std::cout << (*pt).x << ", " << (*pt).y << std::endl;
    std::cout << pt->x << ", " << pt->y << std::endl;
}

int main()
{
    Point pt1;
    pt1.x = 100;
    pt1.y = 200;

    print_point(&pt1);
}

#if 0
void print_point(Point pt)
{
    std::cout << pt.x << ", " << pt.y << std::endl;

    pt.x = 10000;
}

int main()
{
    Point pt1;
    pt1.x = 100;
    pt1.y = 200;

    std::cout << sizeof(pt1) << std::endl;

    print_point(pt1);
    std::cout << pt1.x << std::endl;
}
#endif
#endif
