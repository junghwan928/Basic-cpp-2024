#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // x와 y 좌표를 나타내는 private 멤버 변수

public:
    // 생성자: x와 y 좌표를 초기화함.
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
};

int main(void)
{
    Point pos(1, 2); // 좌표 (1, 2)를 가지는 Point 객체 생성
    Point cpy; // 복사할 Point 객체를 선언함.

    // 연산자 오버로딩을 통해 pos의 좌표에 3을 곱한 결과를 cpy에 할당하고, cpy의 좌표를 출력함.
    cpy = pos * 3;
    cpy.ShowPosition(); // 출력: [3, 6]

    // 연산자 오버로딩을 통해 pos의 좌표에 3을 곱하고 그 결과에 2를 곱한 값을 cpy에 할당하고, cpy의 좌표를 출력함.
    cpy = pos * 3 * 2;
    cpy.ShowPosition(); // 출력: [6, 12]

    return 0;
}

/*
1. Point 클래스의 정의:
    - private 섹션에는 xpos와 ypos라는 두 개의 정수형 멤버 변수가 있음. 
        -> 이 변수들은 좌표를 나타냄.
    - public 섹션에는 생성자와 ShowPosition() 함수가 있음.
    - 생성자는 기본값으로 x와 y를 각각 0으로 초기화함.
    - ShowPosition() 함수는 현재 좌표를 출력함.

2. operator* 함수의 오버로딩:
    - operator* 함수는 정수 값을 매개변수로 받아서 현재 객체의 좌표에 해당 값을 곱한 후, 
        -> 새로운 Point 객체를 생성하여 반환.

3. main() 함수:
    - main() 함수에서는 Point 객체 pos를 생성하고 초기 좌표는 (1, 2).
        -> 그 다음, 비어있는 Point 객체 cpy를 생성.
    
    - pos * 3 연산을 통해 pos 객체의 좌표에 3을 곱한 결과를 cpy에 할당하고, 
        -> ShowPosition() 함수를 호출하여 좌표를 출력합니다.

    - pos * 3 * 2 연산을 통해 pos 객체의 좌표에 3을 곱한 결과에 다시 2를 곱한 값을 cpy에 할당하고, 
        -> ShowPosition() 함수를 호출하여 좌표를 출력
*/