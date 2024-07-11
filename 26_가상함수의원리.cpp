// 26_가상함수의원리.cpp
#include <iostream>
using namespace std;

// * 가상함수의 비용
// 1) 가상함수를 가지는 모든 객체의 크기는 가상 함수 테이블을 참조하는 포인터 크기만큼
//    증가합니다.
// 2) 가상함수의 개수만큼의 가상함수 테이블의 메모리 비용이 소모됩니다.
// 3) 가상함수를 호출할 때, 가상 함수의 테이블의 주소를 참조해서 호출하므로,
//    정적 바인딩의 호출보다 약간 느립니다.
// 4) 가상함수는 인라인 최적화가 불가능합니다.

class Shape {
    int x;
    int y;

public:
    virtual void Draw() const { cout << "Shape::Draw" << endl; }
    virtual void Go() { }
};

class Rect : public Shape {
    int color;

public:
    // void Draw() const override { }
};

int main()
{
    Shape s;
    Rect r;

    Shape* p = &s;
    p->Draw();

    p = &r;
    p->Draw();
}

#if 0
int main()
{
  

    std::cout << sizeof(s) << std::endl;
    std::cout << sizeof(r) << std::endl;
}
#endif
