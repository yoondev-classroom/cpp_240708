// 30_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// Image* 역활을 수행하는 클래스를 설계해봅시다.
//  => 스마트 포인터
#if 0
class Ptr {
    Image* obj;

public:
    Ptr(Image* p = nullptr)
        : obj { p }
    {
    }

    ~Ptr()
    {
        delete obj;
    }

    Image& operator*()
    {
        return *obj;
    }

    Image* operator->()
    {
        return obj;
    }
};

int main()
{
    // Image* p2 = new Image;
    // (*p2).Draw();
    // p2->Draw();

    // Ptr p;
    // Ptr p = { new Image };
    Ptr p { new Image };
    (*p).Draw();
    //  (p.operator*()).Draw();

    p->Draw();
    // (p.operator->())Draw();
    // (p.operator->())->Draw();
}

#if 0
int main()
{
    Image* p = new Image;
    p->Draw();

    delete p; // !!!
}
#endif
#endif

template <typename T>
class Ptr {
    T* obj;

public:
    Ptr(T* p = nullptr)
        : obj { p }
    {
    }

    ~Ptr()
    {
        delete obj;
    }

    T& operator*()
    {
        return *obj;
    }

    T* operator->()
    {
        return obj;
    }
};

class Point { };

#if 0
int main()
{
    // Ptr<Image> p1 { new Image };
    Ptr p1 { new Image };
    // 생성자의 인자를 통해 컴파일러가 T를 추론할 수 있습니다.
    // => C++17
    // => C++17 이전에는 클래스 템플릿은 반드시 명시적으로
    //    타입을 지정해야 한다.

    Ptr<Point> p2 { new Point };
}
#endif

#include <memory>
// C++11 이후
// - shared_ptr
// - unique_ptr

int main()
{
    shared_ptr<Image> p1 { new Image };
    p1->Draw();
    shared_ptr<Image> p2 = p1;
    // 참조 계수 증가

    unique_ptr<Image> p3 { new Image };
    // unique_ptr<Image> p4 = p3;
    // 복사 금지

    cout << p3 << endl;

    unique_ptr<Image> p4 = std::move(p3);
    cout << p3 << endl;
    cout << p4 << endl;
}
