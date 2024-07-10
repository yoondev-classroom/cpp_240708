// 19_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { std::cout << "Sample()" << std::endl; }
    ~Sample()
    {
        std::cout << "~Sample()" << std::endl;
    }

    // C++에서는 사용하지 않는 인자의 이름은 생략이 가능합니다.
    Sample(const Sample&)
    {
        std::cout << "Sample(const Sample&)" << std::endl;
    }
};

// * 복사 생성자가 호출되는 시점
// - Call by value => 읽기

#if 0
void foo(Sample s) // 2) Sample(const Sample&)
{
} // 3) ~Sample()
#endif

// 객체 타입을 인자로 전달할 때,
// call by value의 의도를 가진다면,
// const& 타입을 사용해야 합니다.
// => 불필요한 객체의 복사 생성 비용 / 소멸 비용을 제거하기 위해서
void foo(const Sample& s)
{
}

int main()
{
    Sample s; // 1) Sample()
    foo(s);

} // 4) ~Sample()
