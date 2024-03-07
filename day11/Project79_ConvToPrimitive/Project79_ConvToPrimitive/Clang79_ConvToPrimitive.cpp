#include <iostream>
using namespace std;

// 'Number' 클래스 정의
class Number
{
private:
    int num; // -> private 접근 지정자 아래에 정수형 멤버 변수 'num' 선언

public:
    // 생성자 정의: 매개변수 기본값을 0으로 설정
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

    // 형 변환 연산자의 오버로딩
    operator int() // -> 'int' 타입으로의 형 변환 연산자 오버로딩
    {
        return num; // -> 'num' 값을 반환하여 형 변환 수행
    }

    // 멤버 함수 'ShowNumber' 정의: 'num' 값을 출력
    void ShowNumber() { cout << num << endl; }
};

int main(void)
{
    Number num1; // 'Number' 클래스의 객체 'num1'을 기본 생성자로 생성
                 // 기본값 0으로 초기화되며, 생성자에서 설정한 메시지 출력

    num1 = 30; // 정수 30을 'Number' 객체 'num1'에 대입
               // 이는 컴파일러에 의해 'Number(30)' 형태로 임시 객체를 생성하고
               // 대입 연산자를 호출하여 현재 객체 'num1'에 복사하는 과정을 거침
               // 여기서 대입 연산자 오버로딩 함수 호출 메시지 출력

    // 연산자 오버로딩을 이용하여 Number 객체와 정수를 더함
    Number num2 = num1 + 20;
                            // 이때, 'num1' 객체가 정수형으로 형 변환되어 덧셈 연산이 수행됨
                            // 형 변환 연산자 오버로딩 함수 호출 메시지는 출력되지 않음

    num2.ShowNumber(); // -> 'num2' 객체의 'ShowNumber' 멤버 함수 호출하여 'num2' 값 출력
    return 0;
}