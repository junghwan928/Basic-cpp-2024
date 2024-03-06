#include <iostream>
using namespace std;

// 기본 클래스 정의
class First
{
private:
	// 멤버 변수
	int num1, num2;

public:
	// 생성자: 멤버 변수 초기화
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{  }

	// 멤버 함수: 멤버 변수 출력
	void ShowData() { cout << num1 << ", " << num2 << endl; }

	// 대입 연산자 오버로딩
	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << endl; // 동작 확인을 위한 출력
		num1 = ref.num1; // 멤버 변수 값 복사
		num2 = ref.num2; // 멤버 변수 값 복사
		return *this; // 현재 객체의 참조 반환
	}
};

// 파생 클래스 정의
class Second : public First // First 클래스 상속
{
private:
	// 추가된 멤버 변수
	int num3, num4;

public:
	// 생성자: 부모 클래스의 생성자를 호출하여 일부 멤버 초기화 및 나머지 초기화
	Second(int n1, int n2, int n3, int n4)
		: First(n1, n2), num3(n3), num4(n4)
	{  }

	// 멤버 함수: 부모 클래스와 자신의 멤버 변수 출력
	void ShowData()
	{
		First::ShowData(); // 부모 클래스의 ShowData() 호출
		cout << num3 << ", " << num4 << endl; // 자신의 멤버 변수 출력
	}

	// 대입 연산자 오버로딩 함수는 주석 처리됨
};

int main(void)
{
	// 파생 클래스의 객체 생성
	Second ssrc(111, 222, 333, 444); // 소스 객체
	Second scpy(0, 0, 0, 0); // 대상 객체

	scpy = ssrc; // 대입 연산자 사용. First 클래스의 대입 연산자가 호출됨
	scpy.ShowData(); // 복사된 객체의 데이터 출력

	return 0;
}

/*
주목해야 할 점은 파생 클래스 Second에서 기본 클래스 First의 생성자를 호출하고, First의 ShowData 메소드를 활용하여 데이터를 출력하는 부분
*/