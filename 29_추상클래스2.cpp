// 29_추상클래스2.cpp
#include <iostream>
using namespace std;

class Camera {
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Stop Recording" << endl; }
};

class FHDCamera {
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Stop Recording" << endl; }
};

class Car {
    FHDCamera* camera;

public:
    Car(FHDCamera* p)
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

// Car  ---> Camera
//  => 강한 결합
//    : 참조하는 클래스의 구체적인 타입에 의존하는 것

int main()
{
    FHDCamera camera;
    Car car { &camera };

    car.Go();
}
