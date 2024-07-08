// 6_string.cpp
#include <iostream>
using namespace std;

// C 문자열
// : '\0' 문자로 종료되는 char 배열

#if 0
int main()
{
    char s[5];
    s[0] = 'h';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    // s[4] = 'o';
    s[4] = '\0';

    printf("%s\n", s);
    std::cout << s << std::endl;
}
#endif

// C 문자열 문제점
// 1) 문자열의 기본적인 연산을 라이브러리 함수를 통해서
//    수행해야 합니다.

// 2) 문자열 연산을 수행할 때, 메모리를 직접 관리해야 합니다.

#if 0
// #include <string.h>
#include <cstring>

int main()
{
    char s1[32] = "hello";
    char s2[32] = "hexlo";

    // strcmp
    if (strcmp(s1, s2) == 0) {
        std::cout << "문자열이 같다." << std::endl;
    } else {
        std::cout << "문자열이 다르다." << std::endl;
    }

    char s3[32];
    strcpy(s3, s1);
    std::cout << s3 << std::endl;

    strcat(s3, s2);
    std::cout << s3 << std::endl;
}
#endif

// C++ 문자열
// 1. 기본적인 문자열의 연산을 연산자를 통해 수행할 수 있습니다.
// 2. 메모리 관리가 자동적으로 수행됩니다.
//   SSO(Simple String Optimization)
//  => 짧은 문자열은 스택을 통해 관리하고,
//     긴 문자열은 동적 메모리 할당을 통해 관리합니다.

#include <string> // std::string

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hexlo";

    if (s1 == s2) {
        std::cout << "문자열이 같다." << std::endl;
    } else {
        std::cout << "문자열이 다르다." << std::endl;
    }

    std::string s3 = s1;
    std::cout << s3 << std::endl;

    // s3 = s3 + s2;
    s3 += s2;
    std::cout << s3 << std::endl;
}
