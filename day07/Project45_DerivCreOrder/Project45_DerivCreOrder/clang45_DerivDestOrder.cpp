#include <iostream>
using namespace std;

// 기본 클래스 SoBase 정의
class SoBase
{
private:
    int baseNum; // 기본 클래스의 멤버 변수

public:
    // 생성자: baseNum을 인자로 받아 초기화
    SoBase(int n) : baseNum(n)
    {
        cout << "SoBase() " << baseNum << endl; // 생성자 메시지 출력
    }

    // 소멸자: 객체가 소멸될 때 호출되어 메시지 출력
    ~SoBase()
    {
        cout << "~SoBase() : " << baseNum << endl; // 소멸자 메시지 출력
    }
};

// 파생 클래스 SoDerived 정의
class SoDerived : public SoBase
{
private:
    int derivNum; // 파생 클래스의 멤버 변수

public:
    // 생성자: SoBase 클래스의 생성자와 derivNum을 초기화
    SoDerived(int n) : SoBase(n), derivNum(n)
    {
        cout << "SoDerived() " << derivNum << endl; // 생성자 메시지 출력
    }

    // 소멸자: 객체가 소멸될 때 호출되어 메시지 출력
    ~SoDerived()
    {
        cout << "~SoDerived() : " << derivNum << endl; // 소멸자 메시지 출력
    }
};

int main(void)
{
    SoDerived drv1(15); // 파생 클래스 객체 drv1 생성 및 초기화
    SoDerived drv2(27); // 파생 클래스 객체 drv2 생성 및 초기화
    return 0;
}

/* 상세 설명
1. SoBase 클래스는 정수형 멤버 변수 baseNum을 가지고 있음.

2. SoDerived 클래스는 SoBase를 상속받으며, 추가적으로 정수형 멤버 변수 derivNum을 가지고 있음.

3. SoBase 클래스와 SoDerived 클래스의 생성자에서는 초기화 메시지를 출력하고, 소멸자에서는 소멸 메시지를 출력.

4. main() 함수에서는 SoDerived 클래스의 객체인 drv1과 drv2를 생성하고 초기화합니다. 생성자와 소멸자의 호출 순서와 메시지가 출력

*/