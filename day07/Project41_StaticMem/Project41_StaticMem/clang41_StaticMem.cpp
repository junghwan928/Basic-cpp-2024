#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjcnt; // 정적 멤버 변수로 객체의 개수를 저장하기 위한 변수

public:
    // 생성자: 객체가 생성될 때마다 정적 멤버 변수를 증가시키고 번호와 함께 객체 생성 메시지를 출력함
    SoSimple()
    {
        simObjcnt++; // SoSimple 객체의 개수 증가
        cout << simObjcnt << " 번째 SoSimple 객체" << endl;
    }
};

// 정적 멤버 변수의 초기화
int SoSimple::simObjcnt = 0;

class SoComplex
{
private:
    static int cmxObjCnt; // 정적 멤버 변수로 객체의 개수를 저장하기 위한 변수

public:
    // 생성자: 객체가 생성될 때마다 정적 멤버 변수를 증가시키고 번호와 함께 객체 생성 메시지를 출력함
    SoComplex()
    {
        cmxObjCnt++; // SoComplex 객체의 개수 증가
        cout << cmxObjCnt << " 번째 SoComplex 객체" << endl;
    }
};

// 정적 멤버 변수의 초기화
int SoComplex::cmxObjCnt = 0;

int main(void)
{
    SoSimple sim1;       // SoSimple 객체 생성
    SoSimple sim2;       // SoSimple 객체 생성

    SoComplex cmx1;      // SoComplex 객체 생성
    SoComplex cmx2 = cmx1; // SoComplex 객체 복사 생성
    SoComplex();         // SoComplex 객체 생성 (임시 객체)

    return 0;
}

/* 추가 설명

1. SoSimple과 SoComplex 클래스에서는 
    ->정적 멤버 변수 simObjcnt와 cmxObjCnt를 사용하여 각 클래스의 객체 개수를 추적함.

2. main 함수에서는 각 클래스의 객체를 생성하고, 
    ->생성된 객체의 번호와 함께 생성 메시지가 출력함.

3. 정적 멤버 변수는 클래스 단위로 하나만 생성되며, 
    -> 모든 객체가 이 변수를 공유합니다. 따라서 객체가 생성될 때마다 정적 멤버 변수가 증가하여 객체의 개수를 추적할 수 있음.

4. 복사 생성자는 
    -> SoComplex 클래스에 정의되어 있지 않으므로 디폴트 복사 생성자가 사용됨.

5. SoComplex();에서 
    -> 생성된 객체는 이름이 없는 임시 객체이므로 생성된 객체의 번호는 출력되지 않음
*/