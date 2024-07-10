// 19_복사생성자3.cpp
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
//  => 함수가 객체를 값으로 반환할 때
Sample s;

#if 0
Sample foo()
{
    return s;
    // - 반환용 임시객체를 s를 복사해서 생성합니다.
    //   Sample(const Sample&)
}
/*
Sample() ; 전역 객체의 생성자
--------
Sample(const Sample&)
~Sample()
--------
~Sample() ; 전역 객체의 소멸자
*/
#endif

Sample& foo()
{
    return s;
}
/*
Sample()
--------
--------
~Sample()
*/

int main()
{
    std::cout << "--------" << std::endl;
    foo();
    // - 반환용 임시 객체가 파괴됩니다.
    std::cout << "--------" << std::endl;
}
