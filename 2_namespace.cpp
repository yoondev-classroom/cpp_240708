// 2_namespace.cpp
// https://github.com/yoondev-classroom/cpp_240708

//       컴파일         링킹
// audio.c => audio.o  => audio.o + video.o => a.exe
// video.c => video.o

// 1. C는 이름 충돌 해결을 위한 문법이 제공되지 않습니다.
// audio.c
// void AudioInit(void) {}

// video.c
// void VideoInit(void) {}

// 2. namespace => 이름 충돌을 해결하기 위해 도입된 문법입니다.
// 3. 표준 C++의 모든 기능은 std 이름 공간을 통해 제공됩니다.
// 4. namespace를 사용하면, 프로그램의 각 요소를 관련된 요소끼리
//    그룹화 할 수 있습니다.
// 5. namespace는 소문자로 사용해야 합니다.

#include <iostream>
namespace media {
namespace audio {
    void Init() { std::cout << "Audio Init" << std::endl; }
}

namespace video {
    void Init() { std::cout << "Video Init" << std::endl; }

    namespace mp4 {
        void Play() { }
    }

    namespace mov {
        void Play() { }
    }

}
}

// 전역 이름공간
void Init() { }

int main()
{
    Init();
    media::audio::Init();
    media::video::Init();

    media::video::mp4::Play();
    media::video::mov::Play();
}
