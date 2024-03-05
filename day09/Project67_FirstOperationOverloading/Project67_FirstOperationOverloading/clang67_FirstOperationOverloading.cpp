#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2; // 정수형 멤버 변수 num1, num2 선언
public:
	// 생성자: 인자로 받은 값을 멤버 변수 num1, num2에 초기화
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{  }

	// 데이터 출력 함수
	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
	int num3, num4; // 정수형 멤버 변수 num3, num4 선언
public:
	// 생성자: 인자로 받은 값을 멤버 변수 num3, num4에 초기화
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{  }

	// 데이터 출력 함수
	void ShowData() { cout << num3 << ", " << num4 << endl; }

	// 대입 연산자 오버로딩
	Second& operator=(const Second& ref)
	{
		cout << "Second& operator=()" << endl; // 대입 연산자 호출을 확인하기 위한 출력문
		num3 = ref.num3; // 멤버 변수 num3에 ref의 num3 값 대입
		num4 = ref.num4; // 멤버 변수 num4에 ref의 num4 값 대입
		return *this; // 현재 객체(this)를 반환
	}
};

int main(void)
{
	First fsrc(111, 222); // First 클래스의 객체 fsrc를 생성하고 초기화
	First fcpy; // First 클래스의 객체 fcpy 생성
	Second ssrc(333, 444); // Second 클래스의 객체 ssrc를 생성하고 초기화
	Second scpy; // Second 클래스의 객체 scpy 생성

	fcpy = fsrc; // fsrc의 데이터를 fcpy에 대입
	scpy = ssrc; // ssrc의 데이터를 scpy에 대입

	fcpy.ShowData(); // fcpy의 데이터 출력
	scpy.ShowData(); // scpy의 데이터 출력

	First fob1, fob2; // First 클래스의 객체 fob1, fob2 생성
	Second sob1, sob2; // Second 클래스의 객체 sob1, sob2 생성

	// 객체 간 대입 연산 후 데이터 출력
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;

	fob1.ShowData(); // fob1의 데이터 출력
	fob2.ShowData(); // fob2의 데이터 출력
	sob1.ShowData(); // sob1의 데이터 출력
	sob2.ShowData(); // sob2의 데이터 출력

	return 0;
}

/*
1. First와 Second 클래스를 정의하고, 대입 연산자 오버로딩을 통해 객체 간의 대입이 발생할 때 수행되는 동작을 확인

2. 주석을 통해 각 클래스와 함수의 역할이 설명
*/