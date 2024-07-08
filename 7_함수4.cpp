// 7_함수4.cpp
#include <iostream>
using namespace std;

// 인라인 함수
// => 함수를 호출하지 않고, 함수의 구현으로 호출부를 기계어 치환합니다.
#if 0
int square(int x)
{
    return x * x;
}
/*
  mov     DWORD PTR [rsp+8], ecx
  mov     eax, DWORD PTR x$[rsp]
  imul    eax, DWORD PTR x$[rsp]
  ret     0
*/

int main()
{
    int x = 10;

    int result = square(x);
    /*
    mov     ecx, DWORD PTR x$[rsp]
    call    int square(int)               ; square
    mov     DWORD PTR result$[rsp], eax
    */

    std::cout << result << std::endl;
}
#endif

#if 0
int main()
{
    int x = 10;

    int result = x * x;

    std::cout << result << std::endl;
}
#endif

#if 0
#define SQUARE(x) ((x) * (x))

int main()
{
    int x = 10;

    // int result = SQUARE(x + x);
    //           x + x * x + x
    int result = SQUARE(++x);
    //            ++x * ++x

    std::cout << result << std::endl;
}
#endif

// 1. 인라인 최적화는 컴파일러 최적화 명령입니다.
//    MSVC: /Ob1

// 2. 인라인 최적화를 통해 더 이상 호출되지 않는 함수의 기계어코드는
//    존재하지 않습니다.

// 3. 인라인 함수를 잘못사용할 경우,
//    전체적인 코드 메모리 사용량이 증가할 수 있습니다.

// 4. 인라인 함수라고 하더라도, 컴파일러가 인라인 여부를 결정합니다.
//  => C99 표준에 인라인 함수가 도입되었습니다.
//    C: static inline void foo(void) {}
//  C++: inline void foo() {}

// 5. 인라인 함수는 internal linkage를 갖습니다.

inline int square(int x)
{
    return x * x;
}

int main()
{
    int x = 10;

    int result = square(x);
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR $T1[rsp], eax
        mov     eax, DWORD PTR $T1[rsp]
        mov     DWORD PTR result$[rsp], eax
    */

    std::cout << result << std::endl;
}
