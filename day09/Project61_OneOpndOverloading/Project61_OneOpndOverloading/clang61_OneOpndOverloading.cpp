#include <iostream>
using namespace std;

// Point 클래스 정의
class Point
{
private:
	int xpos, ypos; // Point 객체의 x, y 좌표를 나타내는 private 멤버 변수

public:
	// 생성자: x, y 좌표를 초기화합니다. 기본값은 0입니다.
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }

	// ShowPosition 멤버 함수: 객체의 좌표를 출력합니다.
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// 전위 증가 연산자 오버로딩: 객체의 x, y 좌표를 각각 1씩 증가시킵니다.
	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this; // 증가된 객체의 참조를 반환합니다.
	}

	// 전위 감소 연산자 오버로딩 (친구 함수): 객체의 x, y 좌표를 각각 1씩 감소시킵니다.
	friend Point& operator--(Point& ref);
};

// 전위 감소 연산자 오버로딩 구현: Point 객체의 좌표를 감소시키고 객체의 참조를 반환합니다.
Point& operator--(Point& ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main(void)
{
	Point pos(1, 2); // pos 객체를 (1, 2)로 초기화
	++pos; // pos 객체의 좌표를 증가
	pos.ShowPosition(); // 현재 좌표 출력: [2, 3]
	--pos; // pos 객체의 좌표를 감소
	pos.ShowPosition(); // 현재 좌표 출력: [1, 2]

	++(++pos); // pos 객체의 좌표를 두 번 증가
	pos.ShowPosition(); // 현재 좌표 출력: [3, 4]
	--(--pos); // pos 객체의 좌표를 두 번 감소
	pos.ShowPosition(); // 현재 좌표 출력: [1, 2]
	return 0;
}
/* 추가 설명
1. Point 클래스: 두 개의 int 타입 멤버 변수 xpos와 ypos를 가지며, 이는 객체의 x, y 좌표를 나타냄. 
	-> 생성자를 통해 이 좌표들은 초기화.

2. ShowPosition(): 객체의 현재 좌표를 출력하는 멤버 함수.

3. operator++(): 이 멤버 함수는 객체의 xpos와 ypos 좌표를 각각 1씩 증가시키는 전위 증가 연산자를 오버로드함. 
	-> 증가된 객체 자신의 참조(*this)를 반환함.

4. operator--(): 이 함수는 친구 함수로 구현되어 있으며, 전위 감소 연산자를 오버로드함. 
	-> 객체의 xpos와 ypos 좌표를 각각 1씩 감소시키고, 감소된 객체의 참조를 반환함.

5. main() 함수: Point 객체 pos를 생성하고, 증가 연산자와 감소 연산자를 사용하여 객체의 좌표를 조작한 뒤, 결과를 출력함. 
	-> 연산자 오버로딩을 통해, ++pos와 --pos 연산이 가능해짐. 
		=> 연산자의 중첩 사용을 통해 좌표를 연속적으로 증가시키거나 감소시키는 동작도 수행함

*/