#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // x와 y 좌표를 나타내는 private 멤버 변수

public:
    // 생성자: x와 y 좌표를 초기화?.
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

    // 현재 좌표를 출력하는 멤버 함수
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // 정수 값과의 곱셈을 수행하는 연산자 오버로딩
    Point operator*(int times)
    {
        Point pos(xpos * times, ypos * times); // 현재 객체의 x와 y 좌표를 정수 값으로 곱한 새로운 Point 객체 생성
        return pos; // 새로운 Point 객체를 반환
    }

    // 전역 범위에서 정수 값과 Point 객체의 곱셈을 수행하는 friend 함수를 선언
    friend Point operator*(int times, Point& ref);
};

// 전역 범위에서 정수 값과 Point 객체의 곱셈을 수행하는 friend 함수를 정의
Point operator*(int times, Point& ref)
{
    return ref * times; // Point 객체의 멤버 함수를 호출하여 연산을 수행하고, 결과를 반환함 -> return ref.operator*(times)
}

int main(void)
{
    Point pos(1, 2); // 좌표 (1, 2)를 가지는 Point 객체 생성
    Point cpy; // 복사할 Point 객체를 선언함.

    // 연산자 오버로딩을 통해 정수 3을 pos 객체와 곱하고, 그 결과를 cpy에 할당하고 cpy의 좌표를 출력함.
    cpy = 3 * pos;
    cpy.ShowPosition(); // 출력: [3, 6]

    // 연산자 오버로딩을 통해 먼저 정수 2를 pos 객체와 곱하고, 그 결과에 정수 3을 곱한 값을 cpy에 할당하고 cpy의 좌표를 출력함.
    cpy = 2 * pos * 3;
    cpy.ShowPosition(); // 출력: [6, 12]

    return 0;
}

/*
1. operator* 함수는 정수 값을 받아 현재 객체의 좌표에 해당 값을 곱한 후, 
    -> 새로운 Point 객체를 생성하여 반환함. 

2. 전역 범위에서 friend 키워드를 사용하여 operator* 함수를 정의함. 

3. 이 함수는 정수 값과 Point 객체를 받아들여 Point 객체의 멤버 함수인 operator* 함수를 호출하여 연산을 수행하고, 
    -> 그 결과를 반환함.

4. main() 함수에서는 operator*를 사용하여 좌표에 대한 곱셈 연산을 수행하고, 
    -> 그 결과를 출력함.
*/