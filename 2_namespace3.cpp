
// 2_namespace3.cpp

#include <iostream>

// #include <stdio.h>
// stdio.h -> cstdio
// stdlib.h -> cstdlib
// string.h -> cstring
// ctype.h  -> cctype

#include <cstdio>

void foo() { std::cout << "foo" << std::endl; }

namespace video {
using ::foo;
}

int main()
{
    ::foo();
    video::foo();
    // 전역 공간의 foo를 호출하는 방법

    printf("Hello, C\n");
    std::printf("Hello, C\n");
}
