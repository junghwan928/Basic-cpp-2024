#include <iostream>
using namespace std;

// First 클래스 정의
class First
{
public:
    // 가상 함수 MyFunc() 선언
    virtual void MyFunc()
    {
        cout << "FirstFunc" << endl;
    }
};

// Second 클래스 정의, First 클래스를 상속받음
class Second : public First
{
public:
    // 가상 함수 MyFunc() 재정의
    virtual void MyFunc()
    {
        cout << "SecondFunc" << endl;
    }
};

// Third 클래스 정의, Second 클래스를 상속받음
class Third : public Second
{
public:
    // 가상 함수 MyFunc() 재정의
    virtual void MyFunc()
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    // Third 클래스의 객체를 가리키는 포인터 tptr을 생성
    Third* tptr = new Third();
    // tptr을 Second 클래스의 포인터 sptr에 할당 (타입 변환)
    Second* sptr = tptr;
    // sptr을 First 클래스의 포인터 fptr에 할당 (타입 변환)
    First* fptr = sptr;

    // fptr이 가리키는 객체의 MyFunc() 함수 호출 (동적 바인딩)
    fptr->MyFunc(); // "ThirdFunc" 출력
    // sptr이 가리키는 객체의 MyFunc() 함수 호출 (동적 바인딩)
    sptr->MyFunc(); // "ThirdFunc" 출력
    // tptr이 가리키는 객체의 MyFunc() 함수 호출 (동적 바인딩)
    tptr->MyFunc(); // "ThirdFunc" 출력

    // 동적으로 할당된 메모리 해제
    delete tptr;

    return 0;
}

/* 추가 설명
1. First, Second, Third 클래스들이 정의됩니다. 각 클래스는 가상 함수 MyFunc()를 선언하고 재정의.

2. main() 함수에서 Third 클래스의 객체를 가리키는 포인터 tptr을 생성.

3. tptr을 Second 클래스의 포인터 sptr에 할당한 후, sptr을 First 클래스의 포인터 fptr에 할당함. 
    -> 이것은 업캐스팅.

4. fptr, sptr, tptr이 각각 가리키는 객체의 MyFunc() 함수를 호출. 
    -> 이때, 가상 함수의 동적 바인딩이 이루어짐.

5. delete 연산자를 사용하여 동적으로 할당된 메모리를 해제

*/