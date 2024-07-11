// 25_다형성3.cpp
#include <iostream>
using namespace std;

// STL 컨테이너
#include <vector> // 동적(dynamic) 배열

#if 0
class Dog { };
class Cat { };

int main()
{
    vector<Dog*> dogs;
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);

    vector<Cat*> cats;
    cats.push_back(new Cat);
    cats.push_back(new Cat);
    cats.push_back(new Cat);
}
#endif

class Animal { };

class Dog : public Animal { };
class Cat : public Animal { };

// 활용 2 - 동종을 보관하는 컨테이너를 사용할 수 있습니다.
int main()
{
    vector<Animal*> animals;

    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Dog);
    animals.push_back(new Cat);
}

#if 0
int main()
{
    // int arr[3] = { 10, 20, 30 };
    vector<int> arr = { 10, 20, 30 };
    arr.push_back(100);
    arr.push_back(200);
    arr.push_back(300);

    std::cout << arr[0] << std::endl;

    for (auto e : arr) {
        std::cout << e << std::endl;
    }
}
#endif
