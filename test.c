// test.c
#if 0
int global = 10; // 전역 변수

int main(void)
{
  auto int local = 42; // 자동 변수


  return 0;
}
#endif

#if 0
#include <stdio.h>

int main(void)
{
  const int x = 10;
  printf("%d\n", x);

  int arr[x]; // 에러!


}
#endif

#if 0
// _square
double square(double x) { return x * x;}

// _main
int main(void)
{
  
}
#endif

extern void goo(void) {}
// 외부 연결 => External linkage

static void foo(void) {}
// 해당 하는 함수 또는 전역 변수를 다른 파일에서 접근이 불가능합니다.
// => Internal linkage



int main(void)
{

}
