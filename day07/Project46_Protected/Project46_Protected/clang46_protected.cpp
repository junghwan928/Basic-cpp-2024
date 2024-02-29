#include <iostream>
using namespace std;

class Base
{
private:
    int num1;

protected:
    int num2;

public:
    int num3;

    Base() : num1(1), num2(2), num3(3)
    { }
};

class Derived : public Base { }; // Base 클래스를 public으로 상속받음

int main(void)
{
    Derived drv;
    cout << drv.num3 << endl; // 컴파일 오류 없이 정상적으로 실행됨
    return 0;
}

/* 추가 설명
1. Base 클래스에는 private, protected, public 세 가지 접근 제어자를 가진 세 개의 멤버 변수가 있음. 
    -> 각각 num1, num2, num3.

2. Derived 클래스는 Base 클래스를 protected로 상속 받음. 
   -> 따라서 Base 클래스의 public 및 protected 멤버는 Derived 클래스 내에서 protected로 상속됨.

3. main 함수에서는 Derived 클래스의 객체를 생성하고 있지만, 주석 처리된 부분에서 num3에 접근하려고 시도하고 있음. 
    -> 그러나 num3은 protected 멤버로 상속되었기 때문에 main 함수 내에서 직접 접근할 수 없음.
*/

/* cout << drv.num3 << endl; 이후
1. Derived 클래스 내부에서 num3에 접근하는 함수를 추가함.

2. Derived 클래스에서 num3의 접근 수준을 public으로 변경함.

*/