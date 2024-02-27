#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1; // 정수형 멤버 변수 num1 선언
    int num2; // 정수형 멤버 변수 num2 선언

public:
    // 생성자: 두 개의 정수를 받아 멤버 변수를 초기화
    SoSimple(int n1, int n2) : num1(n1), num2(n2)
    {
        // empty
        // 생성자에서는 멤버 이니셜라이저를 사용하여 멤버 변수를 초기화.
        // 생성 시 출력할 내용이 없으므로 비워둠.
    }

    // 복사 생성자: 다른 SoSimple 객체를 받아 멤버 변수를 복사 초기화
    SoSimple(SoSimple& copy) : num1(copy.num1), num2(copy.num2)
    {
        // 복사 생성자가 호출되었을 때 메시지 출력
        cout << "Called SoSimple(SoSimple &Copy)" << endl;
    }

    // 멤버 변수를 출력하는 함수
    void ShowSimpleData()
    {
        cout << num1 << endl; // num1 출력
        cout << num2 << endl; // num2 출력
    }
};

int main(void)
{
    SoSimple sim1(5, 10); // SoSimple 객체 생성 및 초기화
    cout << "생성 및 초기화 직전" << endl;
    SoSimple sim2 = sim1; // 복사 생성자 호출을 통한 객체 생성 및 초기화
    // 위의 코드는 SoSimple sim2(sim1)과 동일한 역할.
    cout << "생성 및 초기화 직후" << endl;
    sim2.ShowSimpleData(); // sim2 객체의 데이터 출력
    return 0;
}

/* 추가 설명
1. SoSimple 클래스
    => num1과 num2라는 두 개의 정수형 멤버 변수를 가지고 있음.

2. 생성자는 두 개의 정수를 받아서 멤버 변수를 초기화. 
    =>복사 생성자는 다른 SoSimple 객체를 받아서 그 객체의 멤버 변수를 복사하여 초기화.

3. main 함수에서는 먼저 sim1 객체를 생성하고 초기화한 후, 복사 생성자를 호출하여 sim1 객체의 내용을 복사하여 sim2 객체를 생성. 
    =>그리고 sim2 객체의 데이터를 출력
*/