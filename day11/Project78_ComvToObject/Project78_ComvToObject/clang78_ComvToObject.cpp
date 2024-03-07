#include <iostream>
using namespace std;

// 'Number' 클래스 정의
class Number
{
private:
    int num; // -> private 접근 지정자 아래에 정수형 멤버 변수 'num' 선언

public:
    // -> 생성자 정의: 매개변수 기본값을 0으로 설정
    Number(int n = 0) : num(n) // -> 초기화 목록을 사용하여 'num'을 매개변수 'n'의 값으로 초기화
    {
        cout << "Number(int n=0)" << endl; // -> 생성자가 호출될 때 메시지 출력
    }

    // 대입 연산자 오버로딩
    Number& operator=(const Number& ref) // -> 'ref'는 대입될 'Number' 객체의 참조
    {
        cout << "operator=()" << endl; // -> 대입 연산자 호출 시 메시지 출력
        num = ref.num; // -> 대입될 객체의 'num' 값을 현재 객체의 'num'에 복사
        return *this; // -> 현재 객체의 참조를 반환
    }

    // -> 멤버 함수 'ShowNumber' 정의: 'num' 값을 출력
    void ShowNumber() { cout << num << endl; }
};

int main(void)
{
    Number num; // -> 'Number' 클래스의 객체 'num'을 기본 생성자로 생성
                // -> 기본값 0으로 초기화되며, 생성자에서 설정한 메시지 출력

    num = 30; // -> 정수 30을 'Number' 객체 'num'에 대입
              // -> 이는 컴파일러에 의해 'Number(30)' 형태로 임시 객체를 생성하고
              // -> 대입 연산자를 호출하여 현재 객체 'num'에 복사하는 과정을 거침
              // -> 여기서 대입 연산자 오버로딩 함수 호출 메시지 출력

    num.ShowNumber(); // -> 'num' 객체의 'ShowNumber' 멤버 함수 호출하여 'num' 값 출력
    return 0;
}
/*
int a = 10;
int b = a;
double d = 3.14;
a = d;
d = a;
*/