#include <iostream>
using namespace std;

// 2차원 좌표를 나타내는 Point 클래스
class Point
{
private:
	int xpos, ypos; // x, y 좌표

public:
	// 생성자: 기본값이 0, 0인 좌표로 초기화
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }

	// + 연산자 오버로딩: 두 Point 객체의 좌표를 각각 더한 새 Point 객체 반환
	Point operator+(const Point& pos) const
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	// << 연산자 오버로딩을 위한 친구 함수 선언: Point 객체를 스트림에 출력
	friend ostream& operator<<(ostream& os, const Point& pos);
};

// Point 객체를 출력하기 위한 << 연산자 오버로딩
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;
	return os;
}

// 다형적 동작을 구현한 Adder 함수 객체 클래스
class Adder
{
public:
	// int 타입 덧셈
	int operator()(const int& n1, const int& n2)
	{
		return n1 + n2;
	}

	// double 타입 덧셈
	double operator()(const double& e1, const double& e2)
	{
		return e1 + e2;
	}

	// Point 타입 덧셈 (Point 객체 간 덧셈)
	Point operator()(const Point& pos1, const Point& pos2)
	{
		return pos1 + pos2;
	}
};

int main(void)
{
	Adder adder; // Adder 객체 생성

	// int 타입 사용 예
	cout << adder(1, 3) << endl; // 4 출력

	// double 타입 사용 예
	cout << adder(1.5, 3.7) << endl; // 5.2 출력

	// Point 타입 사용 예
	cout << adder(Point(3, 4), Point(7, 9)); // [10, 13] 출력

	return 0;
}
