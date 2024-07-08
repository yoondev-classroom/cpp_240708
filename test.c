// test.c
#if 0
int global = 10; // 전역 변수

int main(void)
{
  auto int local = 42; // 자동 변수


  return 0;
}
#endif


#include <stdio.h>

int main(void)
{
  const int x = 10;
  printf("%d\n", x);

  int arr[x]; // 에러!


}
