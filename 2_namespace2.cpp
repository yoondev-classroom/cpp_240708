// 2_namespace2.cpp
// namespace를 사용하는 방법 3가지
#include <iostream>

// 1) 전체 이름을 명시하는 방법
#if 0
namespace audio {
void Play() { std::cout << "Audio Play" << std::endl; }
}

int main()
{
    audio::Play();
}
#endif

// 2) using 선언
#if 0
using std::cout;
using std::endl;

namespace audio {
void Play() { cout << "Audio Play" << endl; }
}
using audio::Play;

int main()
{
    Play();
}
#endif

// 3) using 지시어
// => 주의해서 사용해야 합니다.
//    이름충돌의 문제가 발생할 수 있습니다.

#include <algorithm>
// std::count 함수가 존재합니다.
using namespace std;

namespace audio {
void Play() { cout << "Audio Play" << endl; }

void Init() { }

}

using namespace audio;

int count = 0;

int main()
{
    // count = 42;

    Init();
    Play();
}
