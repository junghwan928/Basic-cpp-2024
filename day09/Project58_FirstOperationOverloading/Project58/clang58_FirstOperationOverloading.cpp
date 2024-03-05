#include <iostream>
using namespace std;

// 'Point' 클래스 정의 시작
class Point
{
private:
    // 'xpos'와 'ypos'는 클래스 내부에서만 접근 가능한 private 멤버 변수.
    // 이 변수들은 각각 점의 x 좌표와 y 좌표를 저장.
    int xpos, ypos;

public:
    // 생성자: 'Point' 객체가 생성될 때 자동으로 호출되는 함수.
    // 매개변수 'x'와 'y'는 기본값으로 0을 가지며, 이 값들은 객체의 'xpos'와 'ypos'를 초기화하는 데 사용.
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {  }

    // 'ShowPosition' 멤버 함수는 객체의 좌표를 출력.
    // 'const' 키워드는 이 함수가 멤버 변수의 값을 변경하지 않음을 의미.
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // 연산자 오버로딩 함수 'operator+'를 정의.
    // 이 함수는 두 'Point' 객체의 좌표를 더한 새로운 'Point' 객체를 반환.
    // 매개변수 'ref'는 더할 다른 'Point' 객체의 참조를 받음.
    Point operator+(const Point& ref)
    {
        // 현재 객체의 좌표와 매개변수로 받은 객체의 좌표를 더하여 새로운 'Point' 객체를 생성.
        Point pos(xpos + ref.xpos, ypos + ref.ypos);

        // 생성된 새로운 'Point' 객체를 반환합니다.
        return pos;
    }
};

int main(void)
{
    // 'pos1'과 'pos2' 객체를 생성하고, 각각 (3,4)와 (10,20)으로 초기화.
    Point pos1(3, 4);
    Point pos2(10, 20);

    // 'pos3' 객체는 'pos1' 객체와 'pos2' 객체를 '+' 연산자를 사용하여 더한 결과로 초기화.
    // 여기서 'operator+' 함수가 호출.
    Point pos3 = pos1.operator+(pos2);

    // 각 'Point' 객체의 좌표를 출력.
    pos1.ShowPosition(); // [3, 4]
    pos2.ShowPosition(); // [10, 20]
    pos3.ShowPosition(); // [13, 24] : pos1과 pos2의 좌표를 더한 결과
    return 0;
}

/*
1. 클래스 정의: Point 클래스는 2차원 공간의 점을 나타내는 클래스. 
    -> 클래스 내부에는 xpos와 ypos라는 두 개의 private 멤버 변수가 있어, 각각 점의 x좌표와 y좌표를 저장.

2. 생성자: Point 클래스의 생성자는 객체가 생성될 때 자동으로 호출되어 xpos와 ypos를 초기화. 
    -> 매개변수가 제공되지 않을 경우, 기본값으로 0을 사용함.

3. ShowPosition 함수: 이 함수는 객체의 좌표를 출력함. 
    -> const 키워드가 사용되어, 함수 내에서 멤버 변수의 값을 변경할 수 없음을 의미함.

4. 연산자 오버로딩: operator+ 함수는 두 점을 더하는 연산자 오버로딩 함수. 
    -> 이 함수는 현재 객체의 좌표와 매개변수로 받은 다른 Point 객체의 좌표를 더해 새로운 Point 객체를 생성하고 반환.

5. 메인 함수: 메인 함수에서는 Point 객체들을 생성하고 초기화한 후, ShowPosition 함수를 호출하여 각 객체의 좌표를 출력함. 
    -> 또한 operator+ 함수를 사용하여 두 점의 좌표를 더한 새로운 점의 좌표도 출력함.
*/