#include <iostream>
using namespace std;

// 부모 클래스인 First 정의
class First
{
public:
    // FirstFunc() 멤버 함수 정의
    void FirstFunc()
    {
        cout << "FirstFunc()" << endl;
    }

    // 가상 함수 SimpleFunc() 정의
    virtual void SimpleFunc()
    {
        cout << "First's SimpleFunc()" << endl;
    }
};

// First 클래스를 상속받는 Second 클래스 정의
class Second : public First
{
public:
    // SecondFunc() 멤버 함수 정의
    void SecondFunc()
    {
        cout << "SecondFunc()" << endl;
    }

    // 부모 클래스의 가상 함수를 재정의한 SimpleFunc() 정의
    virtual void SimpleFunc()
    {
        cout << "Second's SimpleFunc()" << endl;
    }
};

// Second 클래스를 상속받는 Third 클래스 정의
class Third : public Second
{
public:
    // ThirdFunc() 멤버 함수 정의
    void ThirdFunc()
    {
        cout << "ThirdFunc()" << endl;
    }

    // Second 클래스의 가상 함수를 재정의한 SimpleFunc() 정의
    virtual void SimpleFunc()
    {
        cout << "Third's SimpleFunc()" << endl;
    }
};

int main(void)
{
    // Third 클래스의 객체 obj 생성
    Third obj;
    obj.FirstFunc();    // First 클래스의 멤버 함수 호출
    obj.SecondFunc();   // Second 클래스의 멤버 함수 호출
    obj.ThirdFunc();    // Third 클래스의 멤버 함수 호출
    obj.SimpleFunc();   // Third 클래스의 SimpleFunc() 호출
    cout << endl;

    // Second 클래스의 참조형 변수 sref를 이용하여 obj의 멤버 함수 호출
    Second& sref = obj;
    sref.FirstFunc();   // First 클래스의 멤버 함수 호출
    sref.SecondFunc();  // Second 클래스의 멤버 함수 호출
    sref.SimpleFunc();  // Third 클래스의 SimpleFunc() 호출
    cout << endl;

    // First 클래스의 참조형 변수 fref를 이용하여 obj의 멤버 함수 호출
    First& fref = obj;
    fref.FirstFunc();   // First 클래스의 멤버 함수 호출
    fref.SimpleFunc();  // Third 클래스의 SimpleFunc() 호출 (다형성)

    return 0;
}
