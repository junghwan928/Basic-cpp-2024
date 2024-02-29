#include <iostream>
using namespace std;

int simObjcnt = 0; // SoSimple 객체의 개수를 저장하기 위한 전역 변수
int cmxObjcnt = 0; // SoComplex 객체의 개수를 저장하기 위한 전역 변수

class SoSimple
{
public:
    // 생성자: 객체가 생성될 때마다 전역 변수를 증가시키고 번호와 함께 객체 생성 메시지를 출력함
    SoSimple()
    {
        simObjcnt++; // SoSimple 객체의 개수 증가
        cout << simObjcnt << " 번째  So Simple 객체" << endl;
    }
};

class SoComplex
{
public:
    // 생성자: 객체가 생성될 때마다 전역 변수를 증가시키고 번호와 함께 객체 생성 메시지를 출력함
    SoComplex()
    {
        cmxObjcnt++; // SoComplex 객체의 개수 증가
        cout << cmxObjcnt << " 번째  So Complex 객체" << endl;
    }

    // 복사 생성자: 객체가 복사될 때마다 전역 변수를 증가시키고 번호와 함께 객체 생성 메시지를 출력함
    SoComplex(SoComplex& copy)
    {
        cmxObjcnt++; // SoComplex 객체의 개수 증가
        cout << cmxObjcnt << " 번째  So Complex 객체" << endl;
    }
};

int main(void)
{
    SoSimple sim1; // SoSimple 객체 생성
    SoSimple sim2; // SoSimple 객체 생성

    SoComplex com1;     // SoComplex 객체 생성
    SoComplex com2 = com1; // SoComplex 객체 복사 생성
    SoComplex();        // SoComplex 객체 생성 (임시 객체)

    return 0;
}

/* 추가 설명

1. SoSimple 클래스 
    => 단순히 객체 생성 메시지를 출력하는 생성자만 가지고 있음.
2. SoComplex 클래스
    => 객체 생성 및 복사 생성 시에 객체의 개수를 추적하고 객체 생성 메시지를 출력하는 생성자와 복사 생성자를 가지고 있음.

3. main 함수에서
    => 각 클래스의 객체를 생성하고, 객체가 생성될 때마다 해당 클래스의 생성자가 호출되며, 생성된 객체의 번호와 함께 생성 메시지가 출력됨.

4. SoComplex 클래스의 복사 생성자는 객체가 복사될 때 호출되며, 복사된 객체의 번호와 함께 생성 메시지가 출력됨.

SoComplex();는 임시 객체를 생성
*/