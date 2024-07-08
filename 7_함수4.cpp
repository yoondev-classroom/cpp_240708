// 7_함수4.cpp
#include <iostream>
using namespace std;

// 인라인 함수
// => 함수를 호출하지 않고, 함수의 구현으로 호출부를 기계어 치환합니다.

inline int square(int x)
{
    return x * x;
}
/*
  mov     DWORD PTR [rsp+8], ecx
  mov     eax, DWORD PTR x$[rsp]
  imul    eax, DWORD PTR x$[rsp]
  ret     0
*/

#if 1
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
