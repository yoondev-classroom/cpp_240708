// 27_접근변경자.cpp
#include <iostream>
using namespace std;

// * 접근 변경자(protected/private)를 통해 상속을 수행하면
//   부모의 속성의 접근 제한을 변경해서 상속합니다.
//  => is-a 관계가 성립되지 않습니다.
//  => Upcasting을 사용할 수 없습니다.
//     "다형성 기반 설계가 불가능합니다."

class Base {
private:
    int a;

protected:
    int b;

public:
    int c;
};

class Derived : private Base {
    //              ------
    //             접근 변경자
};

//        public 상속
// <부모 클래스>   ->  <자식 클래스>
//  protected       protected
//  public          public

//        protected 상속
// <부모 클래스>   ->  <자식 클래스>
//  protected       protected
//  public          protected

//        private 상속
// <부모 클래스>   ->  <자식 클래스>
//  protected       private
//  public          private

int main()
{
    Derived d;
    d.c = 10;
    d.b = 42;
}
