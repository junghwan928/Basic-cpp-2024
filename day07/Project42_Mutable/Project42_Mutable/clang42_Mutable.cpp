#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1;    // 상수 멤버 변수
    mutable int num2;  // 가변(mutable) 멤버 변수

public:
    // 생성자: 두 개의 정수를 받아 초기화
    SoSimple(int n1, int n2) : num1(n1), num2(n2)
    { }

    // 객체의 데이터를 출력하는 멤버 함수
    void ShowSimpleData() const
    {
        // const 멤버 함수이므로 num1, num2 모두 출력 가능
        cout << "num1: " << num1 << ", num2: " << num2 << endl;
    }

    // num1의 값을 num2에 복사하는 멤버 함수
    void CopyToNum2() const
    {
        // mutable 키워드로 선언된 num2는 const 함수 내에서도 수정 가능
        num2 = num1;
    }
};

int main(void)
{
    // SoSimple 객체 생성
    SoSimple sm(1, 2);

    // 초기 데이터 출력
    cout << "Initial Data:" << endl;
    sm.ShowSimpleData();

    // CopyToNum2 함수 호출하여 num1 값을 num2에 복사
    sm.CopyToNum2();

    // 변경된 데이터 출력
    cout << "After CopyToNum2:" << endl;
    sm.ShowSimpleData();

    return 0;
}

/* 추가 설명
1. SoSimple 클래스는 num1과 num2라는 두 개의 멤버 변수를 가짐.

2. num1은 상수 멤버 변수이므로 const 멤버 함수 내에서도 변경할 수 없음.

3. num2는 mutable 키워드로 선언되어 있어, const 멤버 함수 내에서도 변경이 가능.

4. ShowSimpleData 함수는 객체의 데이터를 출력하는 멤버 함수. 
    -> 이 함수는 const 멤버 함수로 선언되었으므로 num1과 num2를 모두 출력할 수 있음.

5. CopyToNum2 함수는 num1의 값을 num2에 복사하는 멤버 함수. 
    -> num2가 mutable로 선언되었기 때문에 const 멤버 함수 내에서도 num2의 값을 변경할 수 있음.

6. main 함수에서는 SoSimple 객체를 생성하고, 
    -> 초기 데이터 출력 후 CopyToNum2 함수를 호출하여 num1의 값을 num2에 복사한 뒤 변경된 데이터를 출력
*/