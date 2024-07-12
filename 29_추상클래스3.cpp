// 29_추상클래스3.cpp
#include <iostream>
using namespace std;

// 강한 결합
//  Car ---> Camera

// 약한 결합 / 느슨한 결합
//  Car ---> << BlackBox >>
//                  |
//               -------
//           Camera   FHDCamera
// => 약한 결합은 OCP를 만족합니다.
// => DIP(Dependency Inversion Principle, 의존관계역전원칙)
//   : 구체적인 타입에 의존하는 것이 아니라,
//     추상클래스 또는 인터페이스에 의존해야 한다.

// 1) 카메라의 제작자와 자동차의 제작자가 카메라의 사용 방법(함수)
//    을 약속합니다.
//   => 인터페이스 / 프로토콜
//   => C++에서는 인터페이스를 위한 별도의 문법이 존재하지 않습니다.
//      순수 가상 함수만으로 이루어진 추상 클래스를 인터페이스라고 합니다.
class BlackBox {
public:
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 인터페이스를 이용해서, 자동차의 코드를 구현합니다.
class Car {
    BlackBox* camera;

public:
    Car(BlackBox* p)
        : camera { p }
    {
    }

    void Go()
    {
        camera->StartRecording();

        cout << "Car Go" << endl;

        camera->StopRecording();
    }
};

// 3) 모든 카메라의 제작자는 BlackBox를 상속받아서, 오버라이딩(구현)합니다.
// => 카메라가 "BlackBox 인터페이스를 상속한다" 라고 하지 않고,
//    "BlackBox의 인터페이스를 구현한다" 라고 합니다.
//   : class Camera extends BlackBox
//     class Camera implements BlackBox

class Camera : public BlackBox {
public:
    void StartRecording() override { cout << "Start Recording" << endl; }
    void StopRecording() override { cout << "Stop Recording" << endl; }
};

class FHDCamera : public BlackBox {
public:
    void StartRecording() override { cout << "[FHD]Start Recording" << endl; }
    void StopRecording() override { cout << "[FHD]Stop Recording" << endl; }
};

int main()
{
    FHDCamera camera;
    Car car { &camera };

    car.Go();
}
