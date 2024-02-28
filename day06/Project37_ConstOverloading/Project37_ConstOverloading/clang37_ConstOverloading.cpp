#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // 객체 내부의 정수형 멤버 변수

public:
    // 생성자: 객체가 생성될 때 호출되며, 멤버 변수 num을 인자로 초기화함.
    SoSimple(int n) : num(n)
    { }

    // 멤버 함수 AddNum: 정수를 매개변수로 받아 멤버 변수 num에 더한 뒤 자신의 객체를 반환함.
    SoSimple AddNum(int n) {
        num += n; // 멤버 변수 num에 매개변수 n을 더함.
        return *this; // 자신의 객체를 반환함.
    }

    // 일반 멤버 함수 SimpleFunc: 객체의 멤버 변수 num을 출력함.
    void SimpleFunc()
    {
        cout << "SimpleFunc : " << num << endl;
    }

    // 상수 멤버 함수 SimpleFunc: 객체의 멤버 변수 num을 출력합니다. 이 함수는 객체의 내부 상태를 변경하지 않음.
    void SimpleFunc() const
    {
        cout << "const SimpleFunc : " << num << endl;
    }
};

// 외부 함수 YourFunc: 상수 참조로 객체를 전달받아 해당 객체의 SimpleFunc 함수를 호출함.
void YourFunc(const SoSimple& obj)
{
    obj.SimpleFunc(); // 상수 참조로 전달받은 객체의 SimpleFunc 함수를 호출함.
}

int main(void)
{
    SoSimple obj1(2);           // 일반 객체 obj1을 생성하고, 멤버 변수 num에 2를 저장함.
    const SoSimple obj2(7);     // 상수 객체 obj2를 생성하고, 멤버 변수 num에 7을 저장함.

    obj1.SimpleFunc();          // 일반 객체 obj1의 SimpleFunc 함수를 호출하여 멤버 변수 num을 출력함.
    obj2.SimpleFunc();          // 상수 객체 obj2의 SimpleFunc 함수를 호출하여 멤버 변수 num을 출력함.

    YourFunc(obj1);             // YourFunc 함수를 호출하여 상수 참조로 일반 객체 obj1을 전달함. 
    // YourFunc 함수 내부에서는 해당 객체의 SimpleFunc 함수를 호출하여 멤버 변수 num을 출력함.

    YourFunc(obj2);             // YourFunc 함수를 호출하여 상수 참조로 상수 객체 obj2를 전달함. 
    // YourFunc 함수 내부에서는 해당 객체의 SimpleFunc 함수를 호출하여 멤버 변수 num을 출력함.

    return 0;
}

/*
1. SoSimple 클래스는 하나의 정수형 멤버 변수 num을 가지고 있음.

2. 생성자 SoSimple(int n)은 객체가 생성될 때 호출되며, 
    -> 멤버 변수 num을 인자 n으로 초기화함.

3. 멤버 함수 AddNum(int n)은 매개변수로 받은 정수 n을 현재 객체의 num에 더한 후, 
    -> 자신의 객체를 반환함.

4. SimpleFunc() 함수는 객체의 멤버 변수 num을 출력합니다. 오버로딩된 버전으로, 
    -> 상수 객체에서 호출될 경우 const 함수가 호출됨.

5. YourFunc(const SoSimple &obj) 함수는 상수 참조로 객체를 전달받아 해당 객체의 SimpleFunc 함수를 호출함.
*/