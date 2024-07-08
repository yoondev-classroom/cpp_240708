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

// _square
double square(double x) { return x * x;}

// _main
int main(void)
{
  
}
