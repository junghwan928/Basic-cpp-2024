#include <iostream>
#include <cstring>
using namespace std;

class TwoNumber
{
private:
    int num1; // 첫 번째 정수를 저장하는 멤버 변수
    int num2; // 두 번째 정수를 저장하는 멤버 변수

public:
    // 생성자: 두 개의 정수를 받아 멤버 변수를 초기화
    TwoNumber(int num1, int num2)
    {
        this->num1 = num1; // 첫 번째 정수를 멤버 변수에 할당
        this->num2 = num2; // 두 번째 정수를 멤버 변수에 할당
    }
    /*
    TwoNumber(int num1, int num2) : num1(num1), num2(num2)
       {
        // empty
       }
    */
    // 두 정수를 출력하는 함수
    void ShowTwoNumber()
    {
        cout << "First number: " << this->num1 << endl; // 첫 번째 정수 출력
        cout << "Second number: " << this->num2 << endl; // 두 번째 정수 출력
    }
};

int main(void) {
    TwoNumber two(2, 4); // TwoNumber 클래스의 객체 생성 및 초기화
    two.ShowTwoNumber(); // 객체의 두 정수 출력
    return 0;
}

/* 추가 설명 존
1. TwoNumber 클래스
=> num1과 num2라는 두 개의 멤버 변수를 가지고 있음.

2. 생성자 TwoNumber(int num1, int num2) 
=> 두 개의 인자를 받아서 num1과 num2 멤버 변수에 값을 할당.

3. ShowTwoNumber() 함수 
=> 객체의 num1과 num2 멤버 변수를 출력.
*/