#include <iostream>
using namespace std;

// Point 클래스 정의
class Point
{
private:
	int xpos, ypos; // xpos와 ypos는 Point 객체의 x, y 좌표 값을 저장하는 private 멤버 변수.

public:
	// 생성자: Point 객체가 생성될 때 자동으로 호출됩니다. x, y 좌표는 기본값으로 0을 가짐.
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }

	// ShowPosition 멤버 함수: Point 객체의 x, y 좌표를 출력.
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// 친구 함수 선언: 이 함수는 Point 클래스의 private 멤버에 접근할 수 있음.
	friend Point operator+(const Point& pos1, const Point& pos2);
};

// 연산자 오버로딩 함수 operator+: 두 Point 객체의 좌표를 더하는 기능을 구현.
// 이 함수는 Point 클래스의 친구 함수로, 클래스의 private 멤버에 직접 접근할 수 있음.
Point operator+(const Point& pos1, const Point& pos2)
{
	// 현재 객체의 좌표(xpos, ypos)에 'pos2' 객체의 좌표를 더해 새 Point 객체를 생성.
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos; // 더해진 좌표를 가진 새 Point 객체를 반환.
}

int main(void)
{
	// pos1, pos2 객체 생성 및 초기화
	Point pos1(3, 4); // pos1은 (3, 4) 좌표를 가짐.
	Point pos2(10, 20);	// pos2는 (10, 20) 좌표를 가짐.
	Point pos3 = pos1 + pos2; // '+' 연산자를 사용해 pos1과 pos2의 좌표를 더한 새 Point 객체 pos3을 생성.

	// 각 Point 객체의 좌표를 출력합니다.
	pos1.ShowPosition(); // [3, 4]
	pos2.ShowPosition(); // [10, 20]
	pos3.ShowPosition(); // [13, 24] - pos1과 pos2의 좌표를 더한 결과.

	return 0;
}

/*
1. 클래스와 생성자: Point 클래스는 두 개의 int 타입 멤버 변수 xpos와 ypos를 가지며, 이는 객체의 x, y 좌표를 저장합니다. 생성자는 이 좌표를 초기화.

2. ShowPosition 함수: const 키워드가 붙어 객체의 상태를 변경하지 않음을 명시. 이 함수는 객체의 좌표를 콘솔에 출력.

3. 친구 함수(friend function): operator+ 함수는 Point 클래스의 친구 함수로 선언되어, 클래스의 private 멤버 변수 xpos와 ypos에 직접 접근할 수 있음. 
	-> 이를 통해 두 Point 객체의 좌표를 더해 새로운 Point 객체를 반환.

4. 연산자 오버로딩: operator+는 두 Point 객체를 인자로 받아, 각각의 x 좌표와 y 좌표를 더한 새로운 Point 객체를 생성하고 반환.

5. main 함수: main 함수에서는 세 개의 Point 객체를 생성하고, + 연산자를 통해 두 점을 더한 결과를 출력합니다. 이 과정에서 친구 함수로 정의된 operator+ 함수가 호출
*/