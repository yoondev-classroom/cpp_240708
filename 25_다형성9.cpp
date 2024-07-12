// 25_다형성9.cpp
#include <iostream>
#include <vector>
using namespace std;

// 도형을 선택해서, 복제하는 기능을 구현하고 싶습니다.

class Shape {
public:
    virtual void Draw() const { cout << "Shape Rect" << endl; }

    virtual Shape* Clone() const
    {
        return new Shape { *this };
        // 복사 생성자를 통해 자신을 복제하는 함수입니다.
    }

    virtual ~Shape() { }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }

    virtual Shape* Clone() const
    {
        return new Rect { *this };
    }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }

    virtual Shape* Clone() const
    {
        return new Circle { *this };
    }
};

class Triangle : public Shape {
public:
    void Draw() const override { cout << "Draw Triangle" << endl; }

    virtual Shape* Clone() const
    {
        return new Triangle { *this };
    }
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

        else if (cmd == 8) {
            int index;
            cout << "몇번째 도형입니까? ";
            cin >> index;

            Shape* copy = shapes[index]->Clone();
            shapes.push_back(copy);
            // Prototype Pattern

            // shapes[index] : Shape*
            //  Rect? Circle? Triangle?
            /*
            if (shapes[index]가 Rect) {
              shapes.push_back(new Rect(*static_cast<Rect*>(shapes[index])))
            } else if (shapes[index]가 Circle) {
              shapes.push_back(new Circle(*static_cast<Rect*>(shapes[index])))
            }
            // ...

            */

        }

        else if (cmd == 9) {
            for (Shape* e : shapes) {
                e->Draw();
            }
        } else if (cmd == 0) {
            break;
        }
    }

    for (auto e : shapes) {
        delete e;
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
