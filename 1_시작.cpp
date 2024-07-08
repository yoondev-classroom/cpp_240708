// 1_시작.cpp

// 1. 확장자
//   C: .c
// C++: .cpp .cc .cxx ...

// 2. 컴파일러
// - MSVC: Microsoft Visual C/C++ Compiler
// - GCC: GNU C Compiler
// - LLVM - Clang

// 3. C++ 표준
// 1983: C++ 탄생
//-------------
// 1998: 1차 표준안, C++98 => STL(Standard Template Library)
// 2003: C++03
//--------------
// 2011: C++11  => Modern C++
// 2014: C++14
// 2017: C++17
// 2020: C++20
// 2023: C++23

// 4. C++은 C의 문법을 지원합니다.
// C의 표준과 C++안에서의 C의 표준은 다릅니다.

// Compile: Ctrl + F7
// Compile + Run: Ctrl + F5

#if 0
#include <stdio.h>

void foo(void) {}
void goo() {}


int main()
{
	// goo(10, 20);

	printf("Hello, C\n");
	
	// return 0;
	// C++에서는 main함수의 반환값을 생략할 경우,
	// 컴파일러가 자동으로 return 0로 처리합니다.
}
#endif

// C++ 표준 입출력
// - C++의 표준 헤더파일은 확장자가 없습니다.
#include <iostream>

int main()
{
    std::cout << "Hello, C++" << std::endl;
}
