// 19_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample(int) { std::cout << "Sample(int)" << std::endl; }
    Sample() { std::cout << "Sample()" << std::endl; }
    ~Sample()
    {
        std::cout << "~Sample()" << std::endl;
    }

    Sample(const Sample&)
    {
        std::cout << "Sample(const Sample&)" << std::endl;
    }
};

#if 0
int main()
{
    // C++에서는 임시 객체를 생성할 수 있는 문법이 있습니다.
    std::cout << "-----" << std::endl;
    // Sample { 42 }; // 임시 객체 생성

    std::cout << "-----" << std::endl;
}
#endif

// 지역 객체는 반드시 값으로 반환해야 합니다.
// 지역 객체를 값으로 반환할 때, 반환용 임시 객체의 복사/생성 비용을
// 최적화할 수 있습니다.
// - RVO(Return Value Optimization)

// 최신 컴파일러는 NRVO(Named RVO)를 지원합니다.

#if 1
Sample foo()
{
    Sample s;
    return s;

    // return Sample {};
    // 임시 객체를 생성해서 반환합니다.
}

int main()
{
    std::cout << "--------" << std::endl;
    foo();
    std::cout << "--------" << std::endl;
}
#endif
