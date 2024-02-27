#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num; // 정수형 멤버 변수 num 선언

public:
    // 생성자: 정수를 받아 멤버 변수를 초기화
    SelfRef(int n) : num(n)
    {
        cout << "객체 생성" << endl; // 객체가 생성될 때 메시지 출력
    }

    // 정수를 더하여 자기 자신을 반환하는 함수
    SelfRef& Adder(int n)
    {
        num += n; // 멤버 변수에 정수를 더함
        return *this; // 자기 자신을 참조하는 포인터 반환
    }

    // 객체의 정수를 출력하고 자기 자신을 반환하는 함수
    SelfRef& ShowTwoNumber()
    {
        cout << num << endl; // 멤버 변수의 값 출력
        return *this; // 자기 자신을 참조하는 포인터 반환
    }
};

int main(void)
{
    SelfRef obj(3); // SelfRef 객체 생성 및 초기화
    SelfRef& ref = obj.Adder(2); // obj 객체에 정수를 더하고, 반환된 객체의 참조를 ref에 저장

    obj.ShowTwoNumber(); // obj 객체의 정수 출력
    ref.ShowTwoNumber(); // ref가 참조하는 객체의 정수 출력

    // 메서드 체이닝을 통한 연속된 함수 호출
    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

    return 0;
}


/* 추가 설명

1. SelfRef 클래스는 num이라는 정수형 멤버 변수를 가지고 있음.

2. 생성자는 인자로 받은 정수를 사용하여 num을 초기화.

3. Adder 함수는 인자로 받은 정수를 num에 더한 후, 자기 자신을 반환.

4. ShowTwoNumber 함수는 객체의 num을 출력한 후, 자기 자신을 반환.

5. main 함수에서는 SelfRef 객체를 생성하고, Adder 함수와 ShowTwoNumber 함수를 메서드 체이닝하여 호출

*/