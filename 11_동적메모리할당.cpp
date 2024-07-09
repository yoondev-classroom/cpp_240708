// 11_동적메모리할당.cpp
// => 누수의 위험성이 존재합니다.
//    malloc/free는 오버헤드가 있습니다.

#include <iostream>
#include <cstdlib>

// C - 동적 메모리 할당
// void* malloc(size_t size)
// void free(void* p)

using namespace std;
#if 0

int global = 10; // 전역 변수

void foo()
{
    int local = 100; // 지역 변수
    static int slocal = 100; // 정적 지역 변수
}

int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    // malloc은 실패 가능성이 존재합니다.
    // 실패할 경우, NULL을 반환합니다.
    if (p) {
        *p = 100;
        std::cout << *p << std::endl;

        free(p);
        p = NULL;
    }
}
#endif

// 1. C++은 동적 메모리 할당을 연산자를 통해서 제공합니다.
//    new / delete

// 2. malloc은 void*를 반환하기 때문에,
//    명시적인 캐스팅(static_cast)이 필요하지만,
//    new는 전달받은 타입의 주소 타입이 반환되기 때문에
//    별도의 캐스팅이 필요하지 않습니다.
#if 0
int main()
{
    int* pn = new int;
    *pn = 10;
    std::cout << *pn << std::endl;

    delete pn;
    pn = NULL;
}
#endif

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int) * 10));
    p[0] = 10;
    p[9] = 100;

    std::cout << p[0] << std::endl;
    std::cout << p[9] << std::endl;

    free(p);
    p = NULL;
}
#endif

// 3. 연속된 메모리를 할당할 때는 new T[갯수], 해지할 때는 delete[] 를 사용해야
//    합니다.
#if 0
int main()
{
    int* p = new int[10];

    p[0] = 10;
    p[9] = 100;

    std::cout << p[0] << std::endl;
    std::cout << p[9] << std::endl;

    delete[] p;
    // 주의: 연속된 메모리를 해지할 때는,
    //      반드시 delete[]를 사용해야 합니다.

    p = NULL;
}
#endif

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    memset(p, 0, sizeof(int));
    std::cout << *p << std::endl; // 쓰레기값

    free(p);
}
#endif

#if 0
// 4. new를 통해서 메모리를 할당하면, 초기값을 지정할 수 있습니다.
int main()
{
    // int* p = new int(10);
    int* p = new int { 10 };
    std::cout << *p << std::endl;
    delete p;

    p = new int[3] { 10, 20, 30 };
    for (int i = 0; i < 3; ++i) {
        std::cout << p[i] << std::endl;
    }
    delete[] p; // !!
}
#endif

int global; // 전역 변수

void foo() { }

int main()
{
    static int slocal; // 정적 지역 변수
    int local; // 지역 변수

    int* p = new int; // 동적 메모리 할당(힙 변수)

    std::cout << (void*)&foo << std::endl;
    std::cout << &global << std::endl;
    std::cout << &slocal << std::endl;
    std::cout << p << std::endl;
    std::cout << &local << std::endl;
}
