// 25_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

// 추상화
// => 클래스를 설계할 때,
//    필요한 상태와 행위를 정의하는 것

// 1. 각 도형의 클래스를 설계
// 2. 부모 클래스를 도입
//  => 부모의 포인터를 통해 자식 객체를 참조할 수 있습니다.
//  => 동종을 보관하는 컨테이너

// 3. 자식의 공통의 기능을 부모의 포인터/레퍼런스를 통해 이용하기 위해서는
//    반드시 해당 특징이 부모로부터 비롯되어야 합니다.
//   : LSP(Liskov Substitution Principle, 리스코프 치환 원칙)
//   => "자식의 공통의 기능은 부모로부터 비롯되어야 한다"
//      자식 클래스는 부모 클래스도 대체할 수 있어야 한다.

// 4. 자식이 재정의하는 부모의 멤버 함수는 반드시 가상함수이어야 합니다.

// 5. 다형성은 OCP(Open Close Principle)를 만족합니다.
//   => 개방 폐쇄 원칙
//     확장에는 열려 있고, 수정에는 닫혀 있어야 한다.
//   "새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다."

class Shape {
public:
    virtual void Draw() const { cout << "Shape Rect" << endl; }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
};

class Triangle : public Shape {
public:
    void Draw() const override { cout << "Draw Triangle" << endl; }
};

int main()
{
    vector<Shape*> shapes;

    while (true) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        } else if (cmd == 3) {
            shapes.push_back(new Triangle); // !!!
        }

        else if (cmd == 9) {
            for (Shape* e : shapes) {
                e->Draw();
                // e    -> Rect  -> Rect::Draw
                //        Circle -> Circle::Draw
                //       Triangle -> Triangle::Draw
                // "다형성" - Polymorphism
            }
        }
    }
}

#if 0
int main()
{
    vector<Rect*> r;
    vector<Circle*> c;
}
#endif

// Linux(Unix)
// => 모든 것은 파일입니다.
//         일반 파일 => read => 파일의 내용을 읽습니다.
// 네트워크(소켓) 파일          => 데이터를 수신합니다.
// 장치 파일                  => 장치의 상태를 읽습니다.
//    => VFS(Virtual File System)
