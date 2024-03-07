#include <iostream>
using namespace std;

// Point 클래스 정의
class Point
{
private:
	int xpos, ypos; // 좌표값을 저장하는 private 멤버 변수

public:
	// 생성자: x와 y 좌표를 매개변수로 받고, 기본값은 0
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl; // 객체 생성 시 메시지 출력
	}
	~Point()
	{
		cout << "Point 객체 소멸" << endl; // 객체 소멸 시 메시지 출력
	}
	void SetPos(int x, int y) // xpos와 ypos의 값을 설정하는 멤버 함수
	{
		xpos = x;
		ypos = y;
	}
	// ostream 객체와 Point 객체의 << 연산자 오버로딩을 위한 친구 함수 선언
	friend ostream& operator<<(ostream& os, const Point& pos);
};
// << 연산자 오버로딩: Point 객체를 출력하기 위한 함수
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;
	return os;
}

// SmartPtr 클래스 정의
class SmartPtr
{
private:
	Point* posptr; // Point 객체를 가리키는 포인터

public:
	// 생성자: Point 객체의 포인터를 매개변수로 받음
	SmartPtr(Point* ptr) : posptr(ptr)
	{ }

	// * 연산자 오버로딩: Point 객체의 참조를 반환
	Point& operator*() const
	{
		return *posptr;
	}
	// -> 연산자 오버로딩: Point 객체의 포인터를 반환
	Point* operator->() const
	{
		return posptr;
	}
	// 소멸자: 할당된 메모리를 자동으로 해제
	~SmartPtr()
	{
		printf("SmartPtr 객체소멸\n");
		delete posptr; // 동적 할당된 Point 객체 메모리 해제
	}
};

int main(void)
{
	// SmartPtr 객체를 생성하면서 동적으로 Point 객체를 할당
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));

	// 생성된 Point 객체 출력
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	// Point 객체의 위치 설정
	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);

	// 변경된 위치를 가진 Point 객체 출력
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	return 0; // 프로그램 종료 시 SmartPtr 소멸자가 호출되면서 동적 할당된 Point 객체들의 메모리를 자동으로 해제
}
