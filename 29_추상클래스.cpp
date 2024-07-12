// 29_추상클래스.cpp
#include <iostream>
using namespace std;

// 1. Shape 제공하는 Draw()/ Clone() 함수는 절대 호출되지 않습니다.
//  => Shape 객체를 생성하지 않습니다.

// 2. Shape 제공하는 Draw() / Clone() 함수를 자식 클래스는
//    반드시 오버라이딩 해야 합니다.

// 순수 가상함수를 가지는 클래스의 객체는 생성이 불가능합니다.
//  => 추상 클래스(Abstract class)
class Shape {
public:
    // 부모의 입장에서는 구현을 제공할 필요가 없습니다.
    // 자식의 입장에서는 반드시 아래의 구현을 오버라이딩해야 한다면
    // => 순수 가상 함수(pure virtual function)
    virtual void Draw() const = 0;
    virtual Shape* Clone() const = 0;

    virtual ~Shape() { }
};

// 부모가 제공하는 순수 가상 함수를 오버라이딩 하지 않으면,
// Rect도 추상 클래스가 됩니다.
// => 객체를 생성할 수 없습니다.
// => 객체를 생성하기 위해서는 반드시 오버라이딩 해야 합니다.
class Rect : public Shape {
public:
    // void Draw() const override { }
    // Shape* Clone() const override { return nullptr; }
};

int main()
{
    // Shape s;
    Rect r;
}
