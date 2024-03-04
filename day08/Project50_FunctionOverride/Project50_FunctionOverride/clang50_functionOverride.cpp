#include <iostream>
using namespace std;

class First
{
public:
    // First 클래스의 MyFunc() 멤버 함수
    void MyFunc()
    {
        cout << "FirstFunc" << endl;
    }
};

class Second : public First
{
public:
    // Second 클래스의 MyFunc() 멤버 함수
    void MyFunc()
    {
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second
{
public:
    // Third 클래스의 MyFunc() 멤버 함수
    void MyFunc()
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    /*
    객체 포인터 타입을 기준으로 접근 범위가 결정
    오버라이딩된 경우는 부모것은 자식것으로 가려짐
    */
    // Third 클래스의 객체를 가리키는 포인터 tptr을 생성
    Third* tptr = new Third();
    // tptr을 Second 클래스의 포인터 sptr에 할당 (타입 변환)
    Second* sptr = tptr;
    // sptr을 First 클래스의 포인터 fptr에 할당 (타입 변환)
    First* fptr = sptr;

    // fptr이 가리키는 객체의 MyFunc() 함수 호출 (정적 바인딩)
    fptr->MyFunc(); // "FirstFunc" 출력
    // sptr이 가리키는 객체의 MyFunc() 함수 호출 (정적 바인딩)
    sptr->MyFunc(); // "SecondFunc" 출력
    // tptr이 가리키는 객체의 MyFunc() 함수 호출 (정적 바인딩)
    tptr->MyFunc(); // "ThirdFunc" 출력


    tptr->Second::MyFunc();
    // 동적으로 할당된 메모리 해제
    delete tptr;

    return 0;
}
