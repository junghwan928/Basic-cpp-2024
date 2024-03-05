#include <iostream>
using namespace std;

// Point 클래스 정의
class Point
{
private:
    int xpos, ypos; // xpos와 ypos는 Point 객체의 x, y 좌표 값을 저장하는 private 멤버 변수입니다.

public:
    // 생성자: Point 객체가 생성될 때 자동으로 호출됩니다. x, y 좌표는 기본값으로 0을 가집니다.
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {  }

    // ShowPosition 멤버 함수: Point 객체의 x, y 좌표를 출력합니다.
    void ShowPosition()
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // 연산자 오버로딩 함수 operator+: 두 Point 객체의 좌표를 더하는 기능을 구현합니다.
    Point operator+(const Point& ref)    // 'ref'는 더할 또 다른 Point 객체의 참조입니다.
    {
        // 현재 객체의 좌표(xpos, ypos)에 'ref' 객체의 좌표를 더해 새 Point 객체를 생성합니다.
        Point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos; // 더해진 좌표를 가진 새 Point 객체를 반환합니다.
    }
};

int main(void)
{
    // pos1, pos2 객체 생성 및 초기화
    Point pos1(3, 4); // pos1은 (3, 4) 좌표를 가집니다.
    Point pos2(10, 20); // pos2는 (10, 20) 좌표를 가집니다.

    // '+' 연산자를 사용해 pos1과 pos2의 좌표를 더한 새 Point 객체 pos3을 생성합니다.
    Point pos3 = pos1 + pos2;

    // 각 Point 객체의 좌표를 출력합니다.
    pos1.ShowPosition(); // [3, 4]
    pos2.ShowPosition(); // [10, 20]
    pos3.ShowPosition(); // [13, 24] - pos1과 pos2의 좌표를 더한 결과입니다.

    return 0;
}

/*
1. 클래스 정의와 생성자: Point 클래스는 두 개의 int 타입 멤버 변수 xpos와 ypos를 가지며, 이는 객체의 x, y 좌표를 저장합니다. 클래스의 생성자는 이 좌표를 초기화하는 역할을 하며, 기본값으로 0을 할당할 수 있습니다.

2. ShowPosition 함수: 이 멤버 함수는 객체의 좌표를 콘솔에 출력합니다.

3. 연산자 오버로딩: operator+ 함수는 현재 객체의 좌표에 인자로 받은 객체의 좌표를 더한 새로운 Point 객체를 반환합니다. 이는 + 연산자를 사용하여 두 Point 객체를 더할 때 자동으로 호출됩니다.

4. main 함수: main 함수에서는 Point 객체를 생성하고 초기화한 후, + 연산자를 통해 두 점을 더하고, 각 객체의 좌표를 출력합니다. 이 과정에서 operator+ 함수가 내부적으로 호출되어 좌표의 덧셈 연산을 수행
*/