// 5_const.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
  const int n = 10;
  // n = 42; // 컴파일 오류!, 상수를 값을 변경할 수 없습니다.

  std::cout << n << std::endl;
}
#endif

// godbolt.org

// 1. C++에서는 반드시 상수는 초기화가 필요합니다.
// 2. 상수 표현식
//  : 컴파일러가 컴파일시 미리 계산을 수행할 수 있으면,
//    컴파일 시간에 계산을 수행해서 기계어를 생성합니다.

//  3. 상수
//   1) 컴파일 상수
//    => 상수 표현식으로 사용이 가능합니다.
//   2) 런타임 상수
//    => 상수 표현식으로 사용이 불가능합니다.
//       실행 시간에 값을 변경하지 않는 용도로만 사용이 가능합니다.

#if 0
int main()
{
   const int x = 10 + 5;
   std::cout << x << std::endl;

   int arr[x];
   // 상수 표현식으로 사용이 가능합니다. - C++

   
} 
#endif

// C++11 에서 새로운 키워드가 도입되었습니다.
// => constexpr


int main()
{
  constexpr const int x = 10; // 컴파일 상수

  int n;
  std::cin >> n;

  const int c = n; // 런타임 상수
  // constexpr const int c = n; // 오류!, 컴파일 타임 상수만 가능합니다.

  printf("%d\n", n);
  printf("%d\n", c);


}
