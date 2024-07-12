// 3_iostream2.cpp
#include <iostream>
using namespace std;

#include <print>
// std::print, std::println

// C++23 에서 새로운 출력 방법이 추가되었습니다.

#if 1
int main()
{

    int age = 42;
    // 내 나이는 42살 입니다.
    printf("내 나이는 %d살 입니다.\n", age);

    std::cout << "내 나이는 " << age << "살 입니다." << std::endl;

    std::println("내 나이는 {}살 입니다.", age);
}
#endif

int main()
{
    int n;
    // scanf("%d", &n);
    // printf("%d\n", n);

    std::cin >> n;
    std::cout << n << std::endl;
}

// 정리
// 1. printf는 함수입니다.
//    std::cout의 정체는 무엇인가?
// 2. std::cout 에 타입을 지정하지 않아도,
//    각 타입에 따른 동작이 제대로 수행이 됩니다.

// => ostream 타입의 객체입니다.
//    연산자 오버로딩 / 함수 오버로딩을 통해 구현되어 있습니다.

// 3. std::cin을 사용할 때, 주소를 사용하지 않아도
//    변수의 값을 변경할 수 있습니다.
//  => istream 타입의 객체로서, 멤버 함수가
//     call by reference 형태로 구현되어 있습니다.

// 4. std::endl?
